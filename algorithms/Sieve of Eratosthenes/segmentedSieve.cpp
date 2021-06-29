#include <bits/stdc++.h>
using namespace std;

vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);

    for(int i = 0; primes[i]*primes[i] <= R; i++){
        long long currentPrime = primes[i];
        long long base = (L/currentPrime)*currentPrime;

        if(base < L){
            base += currentPrime;
        }

        for(long long j = base; j <= R; j+=currentPrime){
            isPrime[j-L] = false;
        }
        if(base == currentPrime){
            isPrime[base - L] = true;
        }
    }

    if(L == 1){
        isPrime[0] = false;
    }


    for(int i = 0; i < R - L + 1; i++){
        if(isPrime[i]){
            cout<<i + L<<" ";
        }
    }
}


int main(){

    segmentedSieve(1,20);


    return 0;
}
