#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int cur = 0;
        int back = n;

        if(n == 0) return n;

        while(cur < back)
        {
            if(A[cur] == elem)
            {
                A[cur] = A[--back];
            } else {
                cur++;
            }
            cout << cur << " " << back << endl;
        }

        return back;
    }
};
int main()
{
    Solution foo;
    int a[] {2,2,3};
    int ret = foo.removeElement(a,3, 2);
    cout << "Result: ";
    for(int x = 0; x < ret; x++)
        cout << a[x] << " ";
    cout << endl;
    return 0;
}
