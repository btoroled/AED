/*
 * Ejercicio 24 - Camino minimo con pesos en vertices y en aristas
 * (AtCoder ABC362 D - Shortest Path 3)
 *
 * Problema: grafo no dirigido y conexo con n vertices y m aristas. Cada
 * vertice i tiene peso A_i y cada arista tiene peso w. El costo de un camino
 * es la suma de los pesos de todos sus vertices y aristas. Para cada vertice
 * i = 2..n imprimir el costo minimo de un camino desde el vertice 1 hasta i.
 *
 * Idea: se pasa el peso de los vertices a las aristas: al salir de u por la
 * arista (u, v, w) se paga A_u + w. Asi se corre un Dijkstra normal desde 1
 * y al final se suma A_i del vertice destino (del cual nunca se "sale").
 *
 * Complejidad: O((n + m) log n).
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int) 2e5 + 5;
int n,m;

using i2 = pair<ll,ll>;

vector<i2> adj[N];

const ll INF = 1e18;


vector<ll> dijkstra(int s){
    vector<ll> dis(n,INF);
    dis[s] = 0;
    priority_queue<i2, vector<i2> , greater<i2>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [d_u, u] = pq.top();
        pq.pop();
        if(d_u != dis[u]) continue;
        for(auto& [v,w] : adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v] , v});
            }
        }
    }
    return dis;
}

void slv(){
    vector<int> A(n);
    for(int i = 0 ; i < n ; i++) cin>>A[i];
    for(int i = 0 ; i < m ; i++){
        int u,v; cin>>u>>v;
        ll w; cin>>w;
        u--; v--;
        adj[u].emplace_back(v,A[u] + w);
        adj[v].emplace_back(u,A[v] + w);
    }
    auto d = dijkstra(0);
    for(int i = 1 ; i < n ; i++) cout<<(d[i] + A[i])<<" ";
    cout<<"\n";
}


int main() {
	while(cin >> n >> m) {
        slv();
        for(int i = 0 ; i < n ; i++) adj[i].clear();
    }
    return 0;
}
