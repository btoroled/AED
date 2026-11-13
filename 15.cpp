/*
 * Ejercicio 15 - Componentes ciclicas
 * (Codeforces 977E - Cyclic Components)
 *
 * Problema: dado un grafo no dirigido con n vertices y m aristas, contar
 * cuantas componentes conexas son un ciclo simple (todos sus vertices forman
 * un unico ciclo, sin aristas extra).
 *
 * Entrada: n m, y luego m aristas u v (1-indexadas).
 * Salida: cantidad de componentes que son ciclos.
 *
 * Idea: una componente es un ciclo si y solo si todos sus vertices tienen
 * grado exactamente 2. Se recorre cada componente con DFS y se verifica que
 * todos sus vertices cumplan deg == 2.
 *
 * Complejidad: O(n + m).
 */

#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 5;
vector<int> adj[N];
int n,m;

bool dfs(int u, vector<bool>& vis){
    vis[u] = true;
    int deg = adj[u].size();
    bool ok = deg == 2 ?  true : false;
    for(int& v : adj[u]){
        if(!vis[v]) ok &= dfs(v,vis);
    }
    return ok;
}


void slv(){
    for(int i = 0 ; i < m ; i++){
        int u,v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n,false);
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            if(dfs(i,vis)){
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}

int main() {
    while(cin>>n>>m){
        slv();
        for(int i = 0 ; i < n ; i++) adj[i].clear();
    }
    return 0;
}