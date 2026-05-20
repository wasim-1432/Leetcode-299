🚀 LeetCode 299 - Bulls and Cows
📌 Problem Statement

You are playing the Bulls and Cows game with your friend.

Given two strings:

secret
guess

You need to return a hint in the format:

xAyB

Where:

x = Number of Bulls
(Correct digit at the correct position)
y = Number of Cows
(Correct digit but at the wrong position)
🧠 Example
Example 1
Input:
secret = "1807"
guess  = "7810"

Output:
1A3B
Explanation
8 is at the correct position → 1 Bull
7, 1, 0 are correct digits but wrong positions → 3 Cows
⚡ Approach
Step 1: Store Digits with Their Indices

Used:

vector<pair<char,int>>

to store:

digit
index
Step 2: Count Bulls First

A Bull means:

digit same && index same

Matched elements are removed to avoid duplicate counting.

Step 3: Count Cows

Now check remaining unmatched digits.

If:

digit same && index different

then it is counted as a Cow.

✅ C++ Solution
class Solution {
public:
    string getHint(string secret, string guess) {

        string ans = "";

        vector<pair<char,int>> v1;
        vector<pair<char,int>> v2;

        for(int i=0;i<secret.size();i++)
        {
            v1.push_back({secret[i],i});
        }

        for(int i=0;i<guess.size();i++)
        {
            v2.push_back({guess[i],i});
        }

        // Count Bulls
        for(int i=0;i<v1.size();i++)
        {
            auto it = find_if(v2.begin(), v2.end(),
            [&](pair<char,int> p){
                return p.first == v1[i].first &&
                       p.second == v1[i].second;
            });

            if(it != v2.end())
            {
                ans += 'A';

                v2.erase(it);

                v1[i].first = '#';
            }
        }

        // Count Cows
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i].first == '#')
                continue;

            auto it = find_if(v2.begin(), v2.end(),
            [&](pair<char,int> p){
                return p.first == v1[i].first;
            });

            if(it != v2.end())
            {
                ans += 'B';

                v2.erase(it);
            }
        }

        unordered_map<char,int> mp;

        for(char ch : ans)
        {
            mp[ch]++;
        }

        string res = "";

        res += to_string(mp['A']);
        res += 'A';
        res += to_string(mp['B']);
        res += 'B';

        return res;
    }
};
📊 Complexity Analysis
Time Complexity
O(n²)

Because find_if() is used inside loops.

Space Complexity
O(n)

For storing vectors.

🔥 Key Learnings
Importance of counting Bulls before Cows
Handling duplicate digits carefully
Using find_if() with vector<pair<char,int>>
Avoiding duplicate matching
Debugging tricky edge cases
✅ Edge Case Handled
secret = "11"
guess  = "01"

Output:

1A0B
🛠️ Concepts Used
C++
STL
Vector
Pair
find_if()
Hash Map
String Manipulation
🔗 GitHub Repository
Paste Your GitHub Repository Link Here
🌟 If you found this helpful

Give this repository a ⭐ on GitHub.
