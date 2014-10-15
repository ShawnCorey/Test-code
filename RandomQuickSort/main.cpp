#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

void randQuickSort(vector<int> a)
{

}

void quickSort(vector<int> &array, int left, int right)
{
    int l = left;
    int r = right - 1;
    int size = right - left;



    if (size > 1) {
        int pivot = array[rand() % size + l];
        cout << "Pivot: " << pivot << endl;
        while (l < r) {
            while (array[r] > pivot && r > l) {
                r--;
            }

            while (array[l] < pivot && l <= r) {
                l++;
            }

            if (l < r) {
                std::swap(array[l], array[r]);
                l++;
            }
        }
        for(int x = left; x < right; x++)
            cout << array[x] << " ";
        cout << endl;
        quickSort(array, left, l);
        quickSort(array, r, right);
    }
}

int main()
{
    vector<int> a;
    srand(time(NULL));

    for(int x = 0; x < 20; x++)
        a.push_back(rand() % 40);
    quickSort(a,0,a.size());
    for(int x = 0; x < a.size(); x++)
        cout << a[x] << " ";
    cout << endl;
    return 0;
}
