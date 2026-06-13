#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();

        vector<pair<int,int>> projects;

        for(int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> pq;

        int i = 0;

        while(k--) {

            
            while(i < n && projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }

        
            if(pq.empty())
                break;

            
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};

int main(){
    int k = 2, w = 0;
    vector<int> profits = {1,2,3}, capital = {0,1,1};

    Solution solution;
    
    cout<<solution.findMaximizedCapital(k,w,profits, capital)<<endl;

    k = 3; w = 0;
    profits = {1,2,3}; capital = {0,1,2};

    cout<<solution.findMaximizedCapital(k,w,profits, capital)<<endl;

}