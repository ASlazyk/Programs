#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> &A, int K);

int main()
{
    cout << "raz" << endl;
    vector<int> xd = solution([-1, -2, -3, -4, -5, -6],5);

    return 0;
}

vector<int> solution(vector<int> &A, int K)
{
    int len = A.size();
    vector<int> Aa(len,0);
    Aa = A;
    vector<int> B(len,0);
    B = A;

    if(!len)
        return B;

    K %= len;

    for(int k = 0; k < K; k++)
    }
        B[0] = Aa[len-1];
        for(int x = 0; x < len; x++)
        {
            B[x+1] = Aa[x];
        }
    Aa = B;
    }
    return B;
}

