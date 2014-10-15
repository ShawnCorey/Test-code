#include <iostream>
#include <vector>

using namespace std;

struct points{
    int pStart;
    int pEnd;
    points(int s, int e) : pStart(s), pEnd(e) {}
};

vector<points*> insertPoint(vector<points*> vp, points *p)
{
    vector<points*> ret;
    for(int x = 0; x < vp.size(); x++)
    {
        cout << "P: " << p->pStart << " " << p->pEnd << endl;
        cout << "vp: " << vp[x]->pStart << " " << vp[x]->pEnd << endl;

        if(vp[x]->pEnd < p->pStart)
        {
            ret.push_back(vp[x]);
            continue;
        } else if(vp[x]->pEnd > p->pEnd && vp[x]->pStart < p->pStart)
        {
            return vp;
        } else if(vp[x]->pStart > p->pEnd)
        {
            ret.push_back(p);
            ret.push_back(vp[x]);
            continue;
        }
        if(vp[x]->pEnd > p->pEnd)
            p->pEnd = vp[x]->pEnd;
        if(vp[x]->pStart < p->pStart)
            p->pStart = vp[x]->pStart;

        if(x == vp.size() - 1)
            ret.push_back(p);
    }
    return ret;
}

int main()
{
    vector<points*> inp;
    inp.push_back(new points(1,5));
    inp.push_back(new points(6,15));
    inp.push_back(new points(20,21));
    inp.push_back(new points(23,26));
    inp.push_back(new points(27,30));
    inp.push_back(new points(35,40));

    points p(14,33);

    vector<points*> out = insertPoint(inp, &p);

    for(int x = 0; x < out.size(); x++)
    {
        cout << out[x]->pStart << " " << out[x]->pEnd << endl;
    }
    return 0;
}
