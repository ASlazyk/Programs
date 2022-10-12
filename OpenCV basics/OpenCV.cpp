void ASmaxMin(Mat Im, double *pmax, double *pmin)
{
    Mat ImD;
    Im.convertTo(ImD, CV_64F);
    int rows = Im.rows;
    int cols = Im.cols;
    int pxls = rows*cols;

    double max = -1.7E308;
    double min = 1.7E308;

    double *pImD = (double*)(ImD.data);

    for(int i = 0; i < pxls; i++)
    {
        double val = *pImD;
        if(val == val) {
            if(max < val)
                max = val;
            if(min > val)
                min = val;
        }
        pImD++;
    }

    *pmax = max;
    *pmin = min;
    ImD.release();
}

cv::Mat ASmask(Mat Im, double threshold)
{

    Mat ImD;
    Im.convertTo(ImD, CV_64F);
    int rows = Im.rows;
    int cols = Im.cols;
    int pxls = rows*cols;

    Mat MaskOut = Mat::zeros(rows, cols, CV_16U);
    double *pImD = (double*)(ImD.data);
    uint16_t *pMaskOut = (uint16_t*)(MaskOut.data);



    for(int i = 0; i < pxls; i++)
    {
        double val = *pImD;
        if(val == val) {            //check for NaN
            if(val > threshold) {
                *pMaskOut = 1;        //write to mask
            } else {
                *pMaskOut = 0;
            }

         }

        pImD++;
        pMaskOut++;
    }

    ImD.release();
    return MaskOut;
}

cv::Mat ASgetGaborKernel(double sigma, double theta, double lambda, double psi, double gamma)
{
    int ks = 65;                //kernel size
    int hks = (ks - 1) / 2;     //half of the kernel size
    theta = theta * CV_PI / 180;
    psi = psi * CV_PI / 180;
    double sigma_x = sigma;
    double sigma_y = sigma/gamma;



    double x_theta;
    double y_theta;

    cv::Mat kernel(ks, ks, CV_64F);

    for(int y = -hks; y <= hks; y++)
    {
        for(int x = -hks; x <= hks; x++)
        {
            x_theta =  x  * cos(theta) + y * sin(theta);
            y_theta = -x  * sin(theta) + y * cos(theta);
            kernel.at<double>(hks+x, hks+y) =
                    (double)exp(-0.5 / pow(sigma_x, 2) * pow(x_theta, 2)
                                -0.5 / pow(sigma_y, 2) * pow(y_theta, 2))
                              * cos(CV_PI * 2 / lambda * x_theta + psi);
        }
    }

    return kernel;
}

cv::Mat ASgetSingleWaveGaborKernel(int ksize, double sig, double the, double lam, double psi, double gam)
{

    //constant for calculating deg to rad
    double dtr = CV_PI / 180;

    Mat GaborKernel = getGaborKernel(Size(ksize, ksize), sig, the*dtr, lam, psi, gam);

    for (int row = 0; row < ksize; row++)
    {
        int x = (ksize - 1) - row - (ksize - 1) / 2;
        for (int col = 0; col < ksize; col++)
        {
            int y = col - (ksize - 1) / 2;
            if (abs(tan(the*dtr)*x -1 * y) / sqrt((tan(the*dtr) * tan(the*dtr) + 1)) > lam / 2)
                GaborKernel.at<double>(row, col) = 0;
        }
    }

    return GaborKernel;
}

cv::Mat ASgetQuadSingleWaveGaborKernel(int ksize, double sig, double the, double lam, double psi, double gam)
{

    Mat KernelT00  = ASgetSingleWaveGaborKernel(ksize, sig,   (0+the), lam, psi, gam);
    Mat KernelT45  = ASgetSingleWaveGaborKernel(ksize, sig,  (45+the), lam, psi, gam);
    Mat KernelT90  = ASgetSingleWaveGaborKernel(ksize, sig,  (90+the), lam, psi, gam);
    Mat KernelT135 = ASgetSingleWaveGaborKernel(ksize, sig, (135+the), lam, psi, gam);

    //auxilliary matrices
    Mat AuxKernel1;
    Mat AuxKernel2;
    Mat QuadKernel;

    ::max(KernelT00, KernelT90, AuxKernel1);
    ::max(KernelT45, KernelT135, AuxKernel2);
    ::max(AuxKernel1, AuxKernel2, QuadKernel);

    return QuadKernel;
}