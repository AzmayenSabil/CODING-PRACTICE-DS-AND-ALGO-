#include <bits/stdc++.h>
using namespace std;

#define w 6

vector <int> graph[1001];
vector <int> vis(1001,0);
vector <int> dis(1001,0);

void bfs(int s){

    /*
    for(int i = 0; i < 1001; i++){
        vis[i] = 0;
        dis[i] = 0;
    }
    */


    vis[s] = 1;
    dis[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(vis[v] == 1) continue;
            dis[v] = dis[u] + w;
            vis[v] = 1;
            q.push(v);

        }

    }


}

int main()
{
    int t;
    cin>>t;

    while(t--){

        int n,m,s;
        cin>>n>>m;

        while(m--){
            int u,v;
            cin>>u>>v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cin>>s;
        bfs(s);

        for(int i = 1; i <= n; i++){
            if(i != s){
                if(dis[i] == 0){
                    printf("-1 ");
                    continue;
                }
                printf("%d ",dis[i]);
            }
        }

        cout << endl;

        //graph.clear();
        for (int i = 0; i <= 1000; i++) {
            graph[i].clear();
            vis[i] = 0;
            dis[i] = 0;
        }

    }



    return 0;
}


//-------another code--------------------//

/*
// A Quick implementation of BFS using
// vectors and queue
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<bool> v;
vector<vector<int> > g;

void edge(int a, int b)
{
	g[a].pb(b);

	// for undirected graph add this line
	// g[b].pb(a);
}

void bfs(int u)
{
	queue<int> q;

	q.push(u);
	v[u] = true;

	while (!q.empty()) {

		int f = q.front();
		q.pop();

		cout << f << " ";

		// Enqueue all adjacent of f and mark them visited
		for (auto i = g[f].begin(); i != g[f].end(); i++) {
			if (!v[*i]) {
				q.push(*i);
				v[*i] = true;
			}
		}
	}
}

// Driver code
int main()
{
	int n, e;
	cin >> n >> e;

	v.assign(n, false);
	g.assign(n, vector<int>());

	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		edge(a, b);
	}

	for (int i = 0; i < n; i++) {
		if (!v[i])
			bfs(i);
	}

	return 0;
}

*/
