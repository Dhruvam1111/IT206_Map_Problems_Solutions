#include <bits/stdc++.h>
using namespace std;
// LeetCode Problem 4 : Top K Frequent Elements

class Solution
{
public:
    // Custom comparator to sort by frequency, break ties by value
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first; // Optional tie-breaker by value
        }
        return a.second > b.second; // Higher frequency comes first
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp; // Frequency map
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> v;
        for (auto i : mp)
        {
            v.push_back(i); // Store element and its frequency
        }

        sort(v.begin(), v.end(), comp); // Sort by frequency

        vector<int> v1;
        for (int i = 0; i < k; i++)
        {
            v1.push_back(v[i].first); // Collect top K elements
        }

        return v1;
    }
};
