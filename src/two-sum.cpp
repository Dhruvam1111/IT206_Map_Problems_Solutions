#include <bits/stdc++.h>
using namespace std;
// LeetCode Problem 1 : Two Sum

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp; // Stores number and its index

        for (int i = 0; i < nums.size(); i++)
        {
            int y = target - nums[i]; // Complement needed to reach target
            if (mp.find(y) != mp.end())
            {
                return {mp[y], i}; // Return indices if complement is found
            }

            mp[nums[i]] = i; // Save current number with its index
        }

        return {}; // No solution found
    }
};
