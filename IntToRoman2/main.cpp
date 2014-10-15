#include <iostream>
#include <string>

using namespace std;
class Solution{
public:
    string intToRoman(int num) {
            string roman = "IVXLCDM";
            string result;
            int divide = 1000;
            for (int i = 6; i >= 0; i-=2) {
                int temp = num / divide;
                if (temp == 0) {
                    divide /= 10;
                    continue;
                }
                if (temp <= 3) {
                    result += createChars(roman[i],temp);
                }
                else if (temp == 4) {
                    result += roman[i];
                    result += roman[i+1];
                }
                else if (temp == 5) {
                    result += roman[i+1];
                }
                else if (temp <= 8) {
                    result += roman[i+1];
                    result += createChars(roman[i],temp-5);
                }
                else {
                    result += roman[i];
                    result += roman[i+2];
                }
                num %= divide;
                divide /= 10;
            }
            return result;
        }

        string createChars(char c, int temp) {
            string result = "";
            for (int i = 0; i < temp; i++)
                result += c;
            return result;
        }
    };
int main()
{
    Solution foo;
    cout << foo.intToRoman(3999) << endl;
    return 0;
}
