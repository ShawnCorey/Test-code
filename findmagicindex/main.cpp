#include <iostream>
#include <vector>

using namespace std;

int findMagicIndex(vector<int> a)
{
    int start = 0, end = a.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        cout << mid << " " << a[mid] << endl;
        if(a[mid] == mid){
            return mid;
        } else if(a[mid] > mid){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a {-2,-1,1,3,5,6,7,17,18,19};
    cout << findMagicIndex(a) << endl;
    return 0;
}
