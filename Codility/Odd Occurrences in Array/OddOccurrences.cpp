#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
    int len = A.size();
    int result = 0;
    bool foundPairFlag = false;

    if(len == 1)
            return A[0];

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(i == j)
                continue;
            if(A[i] == A[j])
            {
                foundPairFlag = true;
            }
        }

        if(foundPairFlag == false)
        {
            result = A[i];
            break;
        }
        foundPairFlag = false;
    }
    return result;
}

int main()
{
    vector<int> ww {9, 3, 9, 3, 9, 7, 3};
    int sol = solution(ww);
    cout<<sol<<endl;
}