#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    string tmp;
    ifstream inFile("test.txt", ifstream::in);
    cout << "Hello world!" << endl;

    if(inFile.is_open())
    {
        while(true)
        {
            while(getline(inFile, tmp))
            {
                cout << tmp << endl;
            }
            if(inFile.eof())
                inFile.clear();

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } else {
        cout << "file not opened" << endl;
    }

    return 0;
}
