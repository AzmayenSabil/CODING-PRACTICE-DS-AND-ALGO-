// ---- DISJOINT SET UNION ----///

#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using ULL = unsigned long long;

const long long MOD = 1e9+7;


#define INPUT(x)                freopen(x,"r",stdin)
#define OUTPUT(x)               freopen (x,"w",stdout)

#define YES                     cout << "YES\n"
#define NO                      cout << "NO\n"

#define pb                      push_back
#define endl                    '\n'
#define LCM(a,b)                (a/__gcd(a,b))*b
#define GCD(a,b)                __gcd(a,b)
#define SP(x,y)                 setprecision((y))<<fixed<<(x)
#define PI                      acos(-1.0)
#define distance(x1,y1,x2,y2)   sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))

#define taratari                ios_base::sync_with_stdio(0);cin.tie(NULL);

int parent[100005];

void make_set(int numberOfComputers) {
    for(int i = 1; i < numberOfComputers + 1; i++){
        parent[i] = i;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}


int main()
{
    //taratari

    int t;

    scanf("%d",&t);
    getchar();


    while(t--){

        int numberOfComputers;
        cin>>numberOfComputers;

        getchar();
        make_set(numberOfComputers);

        int ac = 0;
        int rej = 0;

        string input;

        while(getline(cin,input)){

            if(input.size() == 0)
                break;

            stringstream ss;
            ss << input;

            string q;
            int a;
            int b;

            ss >> q >> a >> b;

            if(q=="c"){
                union_sets(a,b);
            }
            else{
                if(find_set(a) != find_set(b)){
                    rej++;
                }
                else{
                    ac++;
                }
            }

        }

        printf("%d,%d\n", ac, rej);

        if(t!=0){
            cout<<endl;
        }


    }

    return 0;

}


