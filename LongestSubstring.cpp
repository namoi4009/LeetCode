#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.empty())
        return 0;

    int maxLen = 0;
    int i = 0;
    unordered_set<char> seen;

    for (int j = 0; j < s.size(); ++j) 
    {
        while (seen.find(s[j]) != seen.end()) // character s[j] appear twice
        {
            seen.erase(s[i]);
            ++i;
        }
        seen.insert(s[j]);
        maxLen = max(maxLen, j - i + 1);
    }
    return maxLen;
}

int main()
{
    string str = "abcabcbb";
    cout << lengthOfLongestSubstring(str);
    return 0;
}