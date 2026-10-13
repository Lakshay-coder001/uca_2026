//Adobe 2025
#include <bits/stdc++.h>
using namespace std;

int largestSubsequence(const std::vector<int>& arr) {
    // Your code here
  int res= 0;
  for(int i = 0 ; i<30 ; i++){
    int count = 0;
    for(int num : arr){
      if((num >> i) & 1){
        count++;
      }
    }
    if(count > res){
      res = count;
    }
  }
  return res;
}

int main() {
    
    return 0;
}