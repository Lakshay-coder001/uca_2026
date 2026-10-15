#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int R, int C, const vector<vector<int>>& matrix, int mid){
  vector<int> mask(R,0);
  for(int i = 0 ; i<R ; i++){
    for(int j = 0 ; j<C ; j++){
      if(matrix[i][j]  >= mid){
        mask[i] |= (1<<j);
      }
    }
  }
  int mask_check = (1<<C)-1;
  for(int i = 0 ; i<R ; i++){
    for(int j = i+1 ; j<R ; j++){
      if((mask[i] | mask[j]) == mask_check){
        return true;
      }
    }
  }
  return false;
}

int maximizeMinimum(int R, int C, const vector<vector<int>>& matrix) {
    // Your code here
  int s = 1;
  int e = 1000000000;
  int res = 1;
  while(s<=e){
    int mid = s+(e-s)/2;
    if(check(R,C,matrix, mid)){
      res = mid;
      s = mid+1;
    }
    else{
      e = mid-1;
    }
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, C;
    if (cin >> R >> C) {
        vector<vector<int>> matrix(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << maximizeMinimum(R, C, matrix) << "\n";
    }
    return 0;
}