#include <bits/stdc++.h>

using namespace std;

const int sizeOfArray = 10001;

int a[sizeOfArray];
int freq[sizeOfArray];

int n;

int longConsecNumSubArray(){

    int highestCount = 0;

    for(int Left=0; Left<n; Left++) {
        for(int i=0; i<n; i++)
            freq[i] = 0;

        int Min = a[Left];
        int Max = a[Left];

        for(int Right = Left; Right < n; Right++) {
            if(freq[a[Right]] == 1)
                break;

            freq[a[Right]] = 1;

            Min = min(Min, a[Right]);
            Max = max(Max, a[Right]);

            if(Right - Left == Max - Min)
                highestCount = max(highestCount, Right - Left + 1);
        }
    }

    return highestCount;

}


int main(){

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<longConsecNumSubArray();


    return 0;

}
