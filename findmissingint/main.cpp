#include <iostream>
#include <vector>
using namespace std;

int getBit(vector<int> a, int index, int bit)
{
    int mask = 1 << bit;
    return (a[index] & mask) >> bit;
}

int findMissingInt(vector<int> a, int bit)
{
    vector<int> zeroes;
    vector<int> ones;
    if(bit == 31) return 0;

    for(int x = 0; x < a.size(); x++)
    {
        if(getBit(a,x,bit) == 1)
        {
            ones.push_back(a[x]);
        } else {
            zeroes.push_back(a[x]);
        }
    }

    if(zeroes.size() <= ones.size())
    {
        int ret = findMissingInt(zeroes, bit+1);
        return (ret << 1) | 0;
    } else {
        int ret = findMissingInt(ones, bit+1);
        return (ret << 1) | 1;
    }
}

int findMissingInt(vector<int> a)
{
    return findMissingInt(a, 0);

}

int findMissingSorted(vector<int> a)
{
    int start = 0, end = a.size() - 1, middle = end /2;
    for(int x = 0; x < a.size(); x++)
    {
        cout << "x: " << x << endl;
        cout << getBit(a, x, 0) << endl;
        cout << (x & 1) << endl;
        if(getBit(a, x, 0) != (x & 1))
            return x;
    }

    return -1;
}

int main()
{
    vector<int> foo {0,1,2,3,4,5,6,7,8,9,11,12,13,14};
    cout << findMissingInt(foo, 0) << endl;
    return 0;
}
