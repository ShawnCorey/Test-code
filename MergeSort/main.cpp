#include <iostream>
#include <vector>

using namespace std;

void merge(int a[], int start, int end)
{
    int o1 = 0;
    int mid = (end + start) / 2;
    int s1 = start, s2 = mid + 1;

    int temp[end - start + 1];

    while(s1 <= mid && s2 <= end)
    {
        if(a[s1] < a[s2]){
            temp[o1++] = a[s1++];
        }else{
            temp[o1++] = a[s2++];
        }
    }

    while(s1 <= mid)
        temp[o1++] = a[s1++];

    while(s2 <= end)
        temp[o1++] = a[s2++];

    for ( int i = start; i <= end; i++ )
        a[i] = temp[i - start];

    return;
}

void mergesort(int a[], int start, int end)
{
    if(start < end)
    {
        int mid = (end + start) / 2;
        mergesort(a, start, mid);
        mergesort(a, mid+1, end);
        for ( int i = 0; i <= 20; i++ )
            cout << a[i] << " ";
        cout << endl;
        merge(a, start, end);
    }

    return;
}

int main()
{

    int arrsize = 20;
    int a[] {5,324,234,625,762,572,54,723,57,25,7245672,37,25,24,5762,5,725,6,245,62,234};

    for ( int i = 0; i <= arrsize; i++ )
        cout << a[i] << " ";
    cout << endl;

    mergesort(a,0,arrsize);

    for ( int i = 0; i <= arrsize; i++ )
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
