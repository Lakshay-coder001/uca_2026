#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr ,int s, int mid , int e,int& count){
    vector<int> temp;
    int l = s;
    int r = mid+1;
    while(l<=mid && r<=e){
        if(arr[l] <=arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else{
            temp.push_back(arr[r]);
            count+= (mid-l+1);
            r++;
        }
    }
    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=e){
        temp.push_back(arr[r]);
        r++;        
    }
    for(int i = s ; i<=e ; i++){
        arr[i] = temp[i-s];
    }
}
void mergeSort(vector<int>& arr , int s , int e,int &count){
    if(s>=e) return;
    int mid = s+(e-s)/2;
    mergeSort(arr ,s,mid,count);
    mergeSort(arr,mid+1 , e,count);
    merge(arr,s, mid , e,count);
}

int InversioCount(vector<int>& arr){
    int n = arr.size();
    int count = 0;
    mergeSort(arr, 0,n-1,count);
    return count;
}
int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int res = InversioCount(arr);
    cout<<"Inversion Count is: "<<res;
    return 0;
}