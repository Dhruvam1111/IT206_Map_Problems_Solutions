#include <bits/stdc++.h>
using namespace std;
// LeetCode Problem 2 : Longest consecutive sequence
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> h;
        int longest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            h.insert(nums[i]);
        }
        for (auto i : h)
        {
            if (h.find(i - 1) == h.end())
            {
                int count = 1;
                int element = i;
                while (h.find(element + 1) != h.end())
                {
                    count++;
                    element++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};