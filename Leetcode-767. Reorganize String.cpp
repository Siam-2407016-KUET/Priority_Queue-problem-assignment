#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        priority_queue<pair<int, char>> pri_que;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0)
                pri_que.push({freq[i], char('a' + i)});
        }

        string ans;

        pair<int, char> pre = {0, '#'}; 

        while(!pri_que.empty()) {
            auto current = pri_que.top();
            pri_que.pop();

            ans += current.second;
            current.first--;

            if(pre.first > 0)
                pri_que.push(pre);

            pre = current;
        }

        if(ans.size() != s.size())
            return "";

        return ans;
    }
};

int main(){
    string s1= "aab";
    string s2= "aaab";
    Solution solution;
    cout << solution.reorganizeString(s1) << endl;
    cout << solution.reorganizeString(s2) << endl;

    return 0;

}