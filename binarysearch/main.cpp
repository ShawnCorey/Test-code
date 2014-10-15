#include <iostream>

using namespace std;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int head = 0, tail = n - 1;
        while (head <= tail){   //binary search
            int middle = head + ((tail - head) >> 1);
            cout << head << " " << tail << " " << middle << " " << A[middle] << endl;
            if(A[middle] == target) return middle;
            else if (A[middle] > target) tail = middle - 1;
            else if (A[middle] < target) head = middle + 1;
        }
        // Not found so return -1
        return -1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Solution foo;
    int arraysize = 1001;
    int *A = new int[arraysize];
    for(int x = 0; x < arraysize; x++) A[x] = 2 * x;

    cout << foo.searchInsert(A, arraysize, 2000) << endl;

    return 0;
}
