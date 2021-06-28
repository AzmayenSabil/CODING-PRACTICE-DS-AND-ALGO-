#include <bits/stdc++.h>

using namespace std;

int binarySearch(int a[], int n, int target){
    int left = 0;
    int right = n-1;
    int mid;

    while(left<=right){
        mid = (right+left)/2;

        if(a[mid]==target){
            return mid + 1;
        }
        if(a[mid]<target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return -1;
}


int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int target;
    cin>>target;

    cout<< binarySearch(a, n, target);


    return 0;
}
