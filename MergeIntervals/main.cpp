#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool myIntervalCmp(Interval a, Interval b)
    {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), myIntervalCmp);

        int last = 0;

        for(int cur = 1; cur < intervals.size(); ++cur)
        {
            if(intervals[cur].start <= intervals[last].end){
                intervals[last].end = (intervals[cur].end > intervals[last].end)?intervals[cur].end:intervals[last].end;
            } else {
              ++last;
              intervals[last].start = intervals[cur].start;
              intervals[last].end = intervals[cur].end;
            }
        }
        intervals.erase(intervals.begin() + last + 1, intervals.end());
        return intervals;
    }
};

int main()
{
    Solution foo;
    vector<Interval> a;
    Interval i1(1,3);
    Interval i2(2,6);
    Interval i3(8,10);
    Interval i4(15,18);
    a.push_back(i1);
    a.push_back(i2);
    a.push_back(i3);
    a.push_back(i4);
    vector<Interval> b = foo.merge(a);
    cout << "Result: " << endl;
    for(int x = 0; x < b.size(); x++)
        cout << b[x].start << " " << b[x].end << endl;
    return 0;
}
