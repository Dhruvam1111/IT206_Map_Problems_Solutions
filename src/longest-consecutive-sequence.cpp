#include <bits/stdc++.h>
using namespace std;
// LeetCode Problem 2 : Longest consecutive sequence

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> h; // Tracks presence of each number
        int longest = 0;

        // Mark each number as present
        for (int num : nums)
        {
            h[num] = true;
        }

        // Iterate to find sequence starting points
        for (auto pair : h)
        {
            int i = pair.first;
            if (h.find(i - 1) == h.end()) // Only start if previous number doesn't exist
            {
                int count = 1;
                int element = i;

                // Count the length of the current sequence
                while (h.find(element + 1) != h.end())
                {
                    count++;
                    element++;
                }

                longest = max(longest, count); // Update longest length
            }
        }
        return longest;
    }
};
