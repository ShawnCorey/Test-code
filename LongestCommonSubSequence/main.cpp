#include <iostream>
#include <vector>
using namespace std;

int lcs(vector<int> v1, vector<int> v2)
{
    int mat[v1.size()+1][v2.size()+1];
    for(int i = 0; i <= v1.size(); i++)
    {
        for(int j = 0; j <= v2.size(); j++)
        {
            if(i == 0 || j == 0)
            {
                mat[i][j] = 0;
            } else if(v1[i-1] == v2[j-1]) {
                mat[i][j] = mat[i-1][j-1] + 1;
            } else {
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }

    int i = v1.size(), j = v2.size();
    vector<int> vlcs;
    while(i > 0 && j > 0)
    {
        if(v1[i-1] == v2[j-1])
        {
            vlcs.insert(vlcs.begin(), v1[i-1]);
            i--; j--;
        } else if(mat[i-1][j] > mat[i][j-1]){
            i--;
        } else {
            j--;
        }
    }
    for(int x = 0; x < vlcs.size(); x++)
        cout << vlcs[x] << " ";
    cout << endl;
    return mat[v1.size()][v2.size()];
}

int main()
{
    vector<int> v1 {1,4,6,1,3,4,1,725,245,2457,245};
    vector<int> v2 {4,6,1,5,3,245,2457};

    cout << lcs(v1, v2) << endl;
    return 0;
}
