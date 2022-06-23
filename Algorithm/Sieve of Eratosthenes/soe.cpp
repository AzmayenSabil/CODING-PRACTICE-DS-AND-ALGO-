#include <bits/stdc++.h>

using namespace std;

const int maxLimit = 100001;

bool isPrime[maxLimit];

void sieveOfEratosthenes(int n){

    for(int i=2; i<=n; i++){
        isPrime[i] = true;
    }

    for(int i=2 ; i*i<n; i++){
        if(isPrime[i] == true){
            for(int j=i*2; j<=n; j=j+i){
                isPrime[j] = false;
            }
        }
    }

}


int main()
{
    sieveOfEratosthenes(100);

    for(int i=2; i<=100; i++){
        if(isPrime[i])
            cout<<i<<" ";
    }

    return 0;
}
