/*
function dijkstra(G, S)
    for each vertex V in G
        distance[V] <- infinite
        previous[V] <- NULL
        If V != S, add V to Priority Queue Q
    distance[S] <- 0

    while Q IS NOT EMPTY
        U <- Extract MIN from Q
        for each unvisited neighbour V of U
            tempDistance <- distance[U] + edge_weight(U, V)
            if tempDistance < distance[V]
                distance[V] <- tempDistance
                previous[V] <- U
    return distance[], previous[]-
*/

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

#define inf 100000000000000000

long long dist[100005];
int par[100005];

int sum = 0;

vector< pair<int,int> >adj[100005];

struct data
{
    int v;
    long long w;
    bool operator <(const data &obj) const
    {
        return obj.w < w;
    }
};

void dijkstra(int src)
{
    for(int i = 0;i < 100005; i++)
    {
        dist[i] = inf;
        par[i] =  -1;
    }

    priority_queue<data>Q;

    dist[src] = 0;
    Q.push({src,0});

    /*
    3 1
    1 2 4
    1 3
    */

    while(!Q.empty())
    {
        int u = Q.top().v;
        Q.pop();


        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i].first; //2
            int w = adj[u][i].second; //4

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w; //2->4
                par[v] = u; //1
                Q.push({v,dist[v]}); //2,4

            }
        }
    }


}

void find_path(int i)
{
    if(i == -1)
        return;

    find_path(par[i]);

    //sum += dist[i];
}

int main()
{
    int t;
    cin>>t;

    int c = 1;

    while(t--){

        int n,m,s,t;
        cin>>n>>m>>s>>t;

        while(m--){

            int a, b, w;
            cin>>a>>b>>w;

            adj[a].push_back({b,w});
            adj[b].push_back({a,w});

        }

        dijkstra(s);

        if(dist[t] != inf){
            printf("Case #%d: %d\n", c++, dist[t]);

        }
        else{
            //find_path(B);
            printf("Case #%d: unreachable\n", c++);
        }

        for(int i=0; i<100005; i++){
            dist[i]=0;
            par[i]=0;
            adj[i].clear();
        }

    }



    return 0;
}



