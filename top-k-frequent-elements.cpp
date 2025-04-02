#include <bits/stdc++.h>
using namespace std;
// LeetCode Problem 4 : Top K Frequent Elements
class Solution
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto i : mp)
        {
            v.push_back(i);
        }
        sort(v.begin(), v.end(), comp);
        vector<int> v1;
        for (int i = 0; i < k; i++)
        {
            v1.push_back(v[i].first);
        }
        return v1;
    }
};