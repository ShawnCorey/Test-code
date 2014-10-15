#include <iostream>

using namespace std;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int head = 0,tail = n - 1;

        while (head <= tail){   //binary search
            int middle = head + ((tail - head) >> 1);
            cout << head << " " << tail << " " << middle << " " << A[middle] << endl;
            if (A[middle] > target) tail = middle - 1;
            else if (A[middle] < target) head = middle + 1;
            else return middle;
        }
        //If target is not found,the target will be in (b,a).so a is the answer.
        return head;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    Solution foo;
    int A[] = {1,3,5,6,7,8,9,12,14,15,16,17,18,21,22,23,24,25};

    cout << foo.searchInsert(A, 18, 9) << endl;

    return 0;
}
