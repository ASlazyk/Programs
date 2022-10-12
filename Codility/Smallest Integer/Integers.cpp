#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A);

int main()
{
    vector<int>ww = {1,3,3,7,4,5,6};
    auto something = solution(ww);
    cout<<something<<endl;
    return 0;
}

int solution(vector<int> &A) {
    int smallest {1};
    bool found = false;
    while(smallest <=100000)
    {
        for(int k = 0; k  < A.size(); k++)
        {
            if (A[k] == smallest)
            {
                found = true;
                break;
            }
        }
        if (found == false)
            return smallest;
        else
            found = false;
        smallest++;
    }
    return 0;
}
