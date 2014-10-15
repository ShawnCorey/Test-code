#include <iostream>

using namespace std;

enum class foo{
    bar,
    baz
};

int main()
{
    foo bar = foo::baz;
    cout << "Hello world!" << endl;
    cout << bar << endl;
    cout << foo::baz << endl;

    return 0;
}
