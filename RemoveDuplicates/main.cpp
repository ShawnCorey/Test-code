#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;

#define BASE 10

vector<int> radixRemoveDupes(vector<int> a, int max)
{
    vector<int> out = a;
    set<int> bucket[BASE];
    int i;

    for(int n = 1; n <= max; n *= BASE)
    {
        for(i = 0; i < out.size(); i++)
            bucket[(out[i]/n)% BASE].insert(a[i]);

        out.clear();

        for(int k=i=0; i<BASE;bucket[i++].clear())
            for(set<int>::iterator j = bucket[i].begin(); j != bucket[i].end(); out.push_back(*(j++)));
    }
    return out;
}

int main()
{
    vector<int> in;
    set<int> foo;
    const int min = 0;
    const int max = 100000;
    std::default_random_engine generator(time(NULL));
    std::uniform_int_distribution<int> distribution(min,max);

    cout << in.max_size() << " " << foo.max_size() << endl;
    cout << RAND_MAX << endl;

    for(int x = 0; x < 1000000; x++)
        in.push_back(distribution(generator));

    cout << in.size() << endl;
    cout << "beginning sort" << endl;
    vector<int> out = radixRemoveDupes(in, max);
    cout << "ending sort" << endl;
//    for(int x = 0; x < out.size(); x++)
//        if(x%100 == 0) cout << out[x] << " ";

    cout << endl;
    cout << out.size() << endl;
    return 0;
}
