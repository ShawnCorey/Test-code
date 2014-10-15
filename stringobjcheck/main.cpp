#include <iostream>
#include <string>

using namespace std;

void foo(string &s)
{
    if(s.length() == 0)
        return;
    cout << s << endl;
}

int main()
{
    string foo1("Test");
    foo(foo1);
    //foo(NULL);
    return 0;
}
