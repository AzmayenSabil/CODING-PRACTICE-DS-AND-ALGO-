#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int fastExpo(int base, int power, int MOD){

    if(power==0){
        return 1;
    }

    if(power % 2 == 0){
        return fastExpo((base*base)%MOD, power/2, MOD);
    }
    else{
        return (base*fastExpo(base, power-1, MOD)) % MOD;
    }

}

int main(){

    cout << fastExpo(5, 13, mod);

    return 0;
}
