#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int tot = INT_MIN;
        int temp = INT_MIN;

        for(int x = 0; x < n; x++)
        {
            if(temp <= 0)
                temp = A[x];
            else
                temp += A[x];

            if(temp > tot)
                tot = temp;
        }
        return tot;
    }
};

int main()
{
    Solution foo;

    int A[] = {1,-1,-3,4,-5};//{-2,1,-3,4,-1,2,1,-5,4};
    cout << foo.maxSubArray(A, 5) << endl;
    return 0;
}
