// Adobe 2025

#include <iostream>
#include <vector>

using namespace std;

// Complete the solve function below.
int solve(int n, const vector<int>& a) {
    // Your code here
  long long mod = 1e9+7;
  long long ans = 0;
  for(int i = 0 ; i<30 ; i++){
    long long zero_bit = 1;
    long long one_bit = 0;
    int xor_val = 0;
    for(int j = 0 ; j<n ; j++){
      xor_val ^= a[j];
      if((xor_val >> i) & 1){
        one_bit++;
      }
      else{
        zero_bit++;
      }
    }
    long long count = (zero_bit%mod * one_bit %mod)%mod;
    count = count*((1LL*i)%mod) %mod;
    ans = (ans+count)%mod;
  }
  return (int)ans;
}

int main() {
    
    return 0;
}