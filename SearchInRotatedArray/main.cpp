#include <iostream>
#include <vector>

using namespace std;

int findStartOfArray(vector<int> a)
{
    int start = 0,end = a.size() -1,mid;

    if(a[start] < a[end]) return 0;

    while(start<=end){
        mid = (start + end)/2;
//        cout <<a[mid] << " " << start << " " << end << endl;
//        for(int x= start; x <= end; x++)
//            cout << a[x] << " ";
//        cout << endl;
        if(mid > 0 && a[mid] < a[mid-1]) return mid;

        if(a[mid] < a[0]){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return mid;
}

int searchArray(vector<int> a, int k, int start, int end)
{
    int mid;
    while(start <= end)
    {
        mid = (start + end) / 2;

        cout << mid << endl;

        if(a[mid] == k){
            return mid;
        } else if(a[mid] < k){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return-1;
}

int searchRotatedArray(vector<int> a, int k)
{
    int start = findStartOfArray(a);
    int end = a.size() - 1;
    int f1 = -1, f2 = -1;
    if(start > 0)
        f1 = searchArray(a,k,0,start - 1);
    f2 = searchArray(a,k,start,end);

    return max(f1,f2);
}

int main()
{
    vector<int> a {17,18,19,20,-1,11,12,13,14,15,16};//{16,17,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    cout << a[findStartOfArray(a)] << endl;
    cout << a[searchRotatedArray(a, 19)] << endl;
    return 0;
}
