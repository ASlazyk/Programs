#include <iostream>
#include <math.h>
using namespace std;

int solution(int N);

int main()
{

    auto answer = solution(666);
    cout << answer << endl;
    return 0;
}

#include <iostream>
#include <math.h>
using namespace std;

int solution(int N)
{
    int len = floor(log2(N)+1);
    int maxGap = 0;
    int currGap = 0;
    if(N%2==1)
        N = (N-1)/2;
    for(int x = 0; x < len-1; x++)
    {
        if(N%2 == 1)
        {
            if(currGap > maxGap)
                maxGap = currGap;
            currGap = 0;
            N--;
        } else {
            currGap++;
        }
        N/=2;

    }
    return maxGap;
}
