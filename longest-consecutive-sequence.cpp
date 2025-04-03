#include <bits/stdc++.h>
using namespace std;
// LeetCode Problem 2 : Longest consecutive sequence
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> h;
        int longest = 0;
        for (int num : nums)
        {
            h[num] = true;
        }

        for (auto pair : h)
        {
            int i = pair.first;
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