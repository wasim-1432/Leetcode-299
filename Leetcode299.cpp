#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        string ans="";
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
        for(int i=0;i<v1.size();i++)
        {
            auto it=find_if(v2.begin(),v2.end(),[&](pair<int,int> p){
                return p.first==v1[i].first && p.second==v1[i].second;
            });
            if(it!=v2.end())
            {
                ans+='A';
                v2.erase(it);
                v1[i].first='#';
            }
        }
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i].first=='#')
            {
                continue;
            }
            auto it=find_if(v2.begin(),v2.end(),[&](pair<int,int> p){
                return p.first==v1[i].first;
            });
            if(it!=v2.end())
            {
                ans+='B';
                v2.erase(it);
            }
        }
        unordered_map<char,int> mp;
        for(char ch : ans)
        {
            mp[ch]++;
        }
        string res="";
        res+=to_string(mp['A']);
        res+='A';
        res+=to_string(mp['B']);
        res+='B';
        return res;
    }
};