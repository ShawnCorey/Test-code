#include <iostream>
#include <vector>
using namespace std;

int evenodd(vector<int> v1)
{
    int a = 0xffffffff;
    int b = 0;
    for(int x = 0; x < v1.size(); x++)
    {
        a ^= v1[x];
        b ^= v1[x];
    }
    cout << a << endl;
    cout << b << endl;
    return a ^ b;
}

int main()
{
    vector<int> in {1,1,1,3,3,3,4,4,4,6,6,6};
    cout << evenodd(in) << endl;
    return 0;
}
