#include <bits/stdc++.h>

using namespace std;

int result[1000] ={0};

int fact(int n){

    if(n == 1){
        return 1;
    }
    else{
        if(result[n] != 0)
            return result[n];
        else{
            result[n] = n*fact(n-1);
            return result[n];
        }

    }
}

int main()
{
    int n;
    cin>>n;

    cout<<fact(n)<<endl;


    return 0;
}

