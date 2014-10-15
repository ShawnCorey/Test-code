#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for(int x = s.length() - 1; x >= 0; x--)
        {
            char sc = s[x];
            switch(sc)
            {
                case 'I':
                    ret += (ret < 5) ? 1 : -1;
                    break;
                case 'V':
                    ret += 5;
                    break;
                case 'X':
                    ret += (ret < 50) ? 10 : -10;
                    break;
                case 'L':
                    ret += 50;
                    break;
                case 'C':
                    ret += (ret < 500) ? 100 : -100;
                    break;
                case 'D':
                    ret += 500;
                    break;
                case 'M':
                    ret += 1000;
                    break;
            }
            cout << ret << endl;
        }
        return ret;
    }
};

int main()
{
    Solution foo;
    cout << foo.romanToInt("MMMXLV") << endl;
    return 0;
}
