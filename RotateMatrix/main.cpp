#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int temp;
        int t1 = 0, t2 = matrix.size() - 1;
        while(t1 < t2)
        {
            for(int x = 0; x < t2 - t1; x++)
            {
                int temp = matrix[t1][t1 + x];
                matrix[t1][t1 + x] = matrix[t2 - x][t1];
                matrix[t2 - x][t1] = matrix[t2][t2 - x];
                matrix[t2][t2 - x] = matrix[t1 + x][t2];
                matrix[t1 + x][t2] = temp;

//                cout << x << endl;
//                cout << t1 << " " << t2 << endl;
//                for(int z = 0; z < matrix.size(); z++)
//                {
//                    for(int y = 0; y < matrix[z].size(); y++)
//                        cout << matrix[z][y] << " ";
//                    cout << endl;
//                }
            }
            t1++;
            t2--;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Solution foo;

    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{2,29,20,26,16,28});
    matrix.push_back(vector<int>{12,27,9,25,13,21});
    matrix.push_back(vector<int>{32,33,32,2,28,14});
    matrix.push_back(vector<int>{13,14,32,27,22,26});
    matrix.push_back(vector<int>{33,1,20,7,21,7});
    matrix.push_back(vector<int>{4,24,1,6,32,34});
    //matrix.push_back(vector<int>{13,14,15,16});

    for(int x = 0; x < matrix.size(); x++)
    {
        for(int y = 0; y < matrix[x].size(); y++)
            cout << matrix[x][y] << " ";
        cout << endl;
    }

    foo.rotate(matrix);
    cout << "After" << endl;
    for(int x = 0; x < matrix.size(); x++)
    {
        for(int y = 0; y < matrix[x].size(); y++)
            cout << matrix[x][y] << " ";
        cout << endl;
    }

    return 0;
}
