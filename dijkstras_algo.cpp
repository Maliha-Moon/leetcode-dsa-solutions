#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF=10e9+10;
// dijkstra algo works on weighted graph
// create weighted graph
vector<pair<int, int>> G[N];

void dijkstra(int source){
    //all the nodes except source node are set to infinity distance
   vector<int>dist(N,INF);
   //to track visited node
   vector<int> visited(N,NULL);

   set<pair<int,int>>st; //weight,node
   //insert source node
   st.insert({0,source});
   dist[source] = 0;
}
int main()
{
    int v, e;
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        G[x].push_back({y,wt});
    }
    return 0;
}