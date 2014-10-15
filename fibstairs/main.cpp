#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int climbStairs(int n) {
        int f1 = 1, f2 = 1;
        for(int i=0; i<n; i++) {
            f1 = (f2 += f1) - f1;
            cout << f1 << " " << f2 << " " << i << endl;
        }
        return f1;
    }
};

int main()
{
    Solution foo;
    cout << foo.climbStairs(50) << endl;
    return 0;
}
