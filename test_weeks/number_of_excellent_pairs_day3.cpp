#include <iostream>
#include <vector>
#include<map>
using namespace std;

int count_bit(int n){
  int count = 0;
  for(int i = 0 ; i<30 ; i++){
    if(n&1){
      count++;
    }
    n = n>>1;
  }
  return count;
}

long long countExcellentPairs(const vector<int>& nums, int k) {
    // Your code here
  map<int,int> num_bit;
  for(int num : nums){
    num_bit[num] = count_bit(num);
  }
  int res = 0;
  for(auto it1: num_bit){
    for(auto it2 : num_bit){
      if(it1.second + it2.second >= k){
        res++;
      }
    }
  }
  return res;
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int k;
        cin >> k;
        cout << countExcellentPairs(nums, k) << "\n";
    }
    return 0;
}