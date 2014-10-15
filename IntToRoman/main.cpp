#include <iostream>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int temp = num;
        string ret;
        for(int x = temp / 1000; x > 0; x--)
            ret += "M";
        temp %= 1000;
        if(temp >= 900)
        {
            ret += "CM";
            temp -= 900;
        }
        if(temp >= 500)
        {
            ret += "D";
            temp -= 500;
        }

        if(temp >= 400)
        {
            ret += "CD";
            temp -= 400;
        }

        for(int x = temp / 100; x > 0; x --)
            ret += "C";
        temp %= 100;
        if(temp >= 90)
        {
            ret += "XC";
            temp -=90;
        }
        if(temp >= 50)
        {
            ret += "L";
            temp -=50;
        }

        if(temp >= 40)
        {
            ret += "XL";
            temp -=40;
        }

        for(int x = temp /10; x > 0; x--)
            ret += "X";
        temp %= 10;

        if(temp >= 9)
        {
            ret += "IX";
            temp -= 9;
        }

        if(temp >= 5)
        {
            ret += "V";
            temp -= 5;
        }
        if(temp == 4)
        {
            ret += "IV";
            temp -= 5;
        }

        for(int x = temp; x > 0; x--)
            ret += "I";

        return ret;
    }
};

int main()
{
    Solution foo;
    cout << foo.intToRoman(400);
    return 0;
}
