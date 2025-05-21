// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
  struct job{
      int id;
      int deadline;
      int profit;
  };
    bool compare(job a,job b){
      return a.profit>b.profit;
    }
    vector<int> JobScheduling(vector<job>& jobs) { 
        //your code goes here
        int n = jobs.size();
        sort(jobs.begin(),jobs.end(),compare);
        int maxDealine = 0;
        for(auto it:jobs){
          maxDealine = max(maxDealine,it.deadline);
        }
        vector<int> maxProfit(maxDealine+1,-1);
        int sum = 0;
        int count = 0;
        for(int i=0;i<n;i++){
          for(int j=jobs[i].deadline;j>0;j--){
            if(maxProfit[j]==-1){
              count+=1;
              sum += jobs[i].profit;
              maxProfit[j] = jobs[i].deadline;
              break;
            }
          }
        }
        return {count,sum};
    } 
int main() {
     vector<job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    vector<int> result = JobScheduling(jobs);
    cout << "Total Jobs Done: " << result[0] << endl;
    cout << "Total Profit: " << result[1] << endl;

    return 0;
}