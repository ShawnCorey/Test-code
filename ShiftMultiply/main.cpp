#include <iostream>
using namespace std;

int shiftmultiply(int x, int y)
{
    int n = 0;
    if (y < 0)
    {
        x=0-x;
        y=0-y;
    }
    while (y>0) {
        if (y & 1 > 0)
            n += x;
        x <<= 1; y >>= 1;
    }
    return n;
}

int main()
{
    cout << shiftmultiply(5,3) << endl;
    cout << shiftmultiply(571,29234) << endl;
    cout << shiftmultiply(50,90) << endl;
    cout << shiftmultiply(50,-90) << endl;
    cout << shiftmultiply(-50,-90) << endl;
    cout << shiftmultiply(-50,90) << endl;

    return 0;
}
