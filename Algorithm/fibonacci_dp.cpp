#include <bits/stdc++.h>

using namespace std;

int result[1000] ={0};

int fibo(int n){

    if(n==0)
        return 0;
    if(n==1)
        return 1;

    if(result[n] != 0)
        return result[n];

    result[n] = fibo(n-1) + fibo(n-2);

    return result[n];
}

int main()
{
    int n;
    cin>>n;

    cout<<fibo(n)<<endl;


    return 0;
}


