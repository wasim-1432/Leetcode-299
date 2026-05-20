# 🎯 LeetCode 299. Bulls and Cows

## 📝 Problem Description

You are playing the **Bulls and Cows** game with your friend. 🐂 🐄

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
* **Bulls (`A`)**: The number of digits in the guess that are in the correct position.
* **Cows (`B`)**: The number of digits in the guess that are in the secret number but are located in the wrong position.

Given the `secret` string and `guess` string, return *the hint formatted as `"xAyB"`*.

---

## 💡 Method Explanation

The solution uses a **Two-Pass Approach** with vectors to carefully match and track digits without double counting:

1. **📦 Initialization**: Store characters of both `secret` and `guess` alongside their positions using `vector<pair<char, int>>`.
2. **🎯 First Pass (Bulls - `A`)**: Search for exact matches where both the character and the index are identical. When found, increment bulls, erase the character from the guess vector, and mark the secret character with `#` so it isn't reused.
3. **🔍 Second Pass (Cows - `B`)**: Iterate through the remaining secret characters. If a character exists anywhere in the remaining guess vector, count it as a cow and erase it from the guess vector to prevent duplicate matches.
4. **📊 Formatting**: Count the collected signals and build the final string result format (`"xAyB"`).

---

## 💻 C++ Source Code

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";
        vector<pair<char,int>> v1;
        vector<pair<char,int>> v2;
        
        // Step 1: Populate data structures
        for(int i = 0; i < secret.size(); i++) {
            v1.push_back({secret[i], i});
        }
        for(int i = 0; i < guess.size(); i++) {
            v2.push_back({guess[i], i});
        }
        
        // Step 2: First Pass - Find all Bulls (Exact Match) 🎯
        for(int i = 0; i < v1.size(); i++) {
            auto it = find_if(v2.begin(), v2.end(), [&](pair<char,int> p){
                return p.first == v1[i].first && p.second == v1[i].second;
            });
            if(it != v2.end()) {
                ans += 'A';
                v2.erase(it);
                v1[i].first = '#'; // Mark as processed
            }
        }
        
        // Step 3: Second Pass - Find all Cows (Character Match Only) 🔍
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i].first == '#') {
                continue;
            }
            auto it = find_if(v2.begin(), v2.end(), [&](pair<char,int> p){
                return p.first == v1[i].first;
            });
            if(it != v2.end()) {
                ans += 'B';
                v2.erase(it);
            }
        }
        
        // Step 4: Count frequencies and format output 📊
        unordered_map<char,int> mp;
        for(char ch : ans) {
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



        
        return res;
    }
};
