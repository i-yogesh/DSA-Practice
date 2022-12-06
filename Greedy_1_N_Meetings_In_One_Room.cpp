#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        arr.push_back(p);
    }

    sort(arr.begin(), arr.end(), cmp);
    int count = 1;
    int endingTime = arr[0].second;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first > endingTime)
        {
            count++;
            endingTime = arr[i].second;
        }
    }
    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5}, end = {2, 4, 6, 7, 9, 9};
    int n = 6;
    cout<<"No of meetings that can be held are : "<<maxMeetings(start,end,n);
    return 0;
}