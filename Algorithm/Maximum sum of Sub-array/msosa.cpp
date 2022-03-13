#include <iostream>

using namespace std;

const int maxNumberOfElement = 10000;

long long maxSumSubarray(int a[], int n) {
    if(n == 0)
        return 0;
    long long s[maxNumberOfElement], ans = a[0], minimumPartialSum = 0;
    s[0] = a[0];
    for(int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i];

    for(int i = 0; i < n; i++) {
        if(s[i] - minimumPartialSum > ans)
            ans = s[i] - minimumPartialSum;
        if(s[i] < minimumPartialSum)
            minimumPartialSum = s[i];
    }
    return ans;
}

int main()
{
    int n, a[maxNumberOfElement];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxSumSubarray(a, n);
    return 0;
}
