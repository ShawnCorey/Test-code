#include <iostream>

using namespace std;
class Solution{
    public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;

    }
};

int main()
{
    Solution foo;
    int A[] = {1,1,1,3,3,3,2};
    cout << foo.singleNumber(A, 7)<< endl;
    return 0;
}
