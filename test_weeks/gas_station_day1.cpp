// Asked in Scaler OA in UCA 2025. Leetcode problem: https://leetcode.com/problems/gas-station/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int total_gas = 0;
        int total_cost = 0;
        for(int i =0 ; i<n ; i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if(total_gas < total_cost){
            return -1;
        }
        

        int curr = 0 ;
        int res = 0;
        for(int i = 0 ; i<n ; i++){
            curr = curr + (gas[i] - cost[i]);
            if(curr <0){
                curr = 0;
                res = i+1;
            }
        }
        return res;
    }
};


int main() {
    
    return 0;
}