#include <bits/stdc++.h>
using namespace std;
// LeetCode Problem 3 : First Unique Character in a String

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> mp; // Stores frequency of each character
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++; // Count the occurrences of each character
        }

        // Find the first character with frequency 1
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 1)
            {
                return i; // Return index of first unique character
            }
        }

        return -1; // If no unique character found
    }
};
