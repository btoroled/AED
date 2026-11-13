/*
 * Ejercicio 20 - Maximo de aristas manteniendo el grafo bipartito
 * (Codeforces 862B - Mahmoud and Ehab and the bipartiteness)
 *
 * Problema: se da un arbol de n nodos. Se quiere agregar la mayor cantidad
 * de aristas posible de forma que el grafo siga siendo bipartito y simple
 * (sin lazos ni aristas repetidas). Imprimir cuantas aristas se pueden
 * agregar.
 *
 * Idea: un arbol siempre es bipartito. Se colorea con DFS (colores 0 y 1) y
 * se cuentan x nodos de un color e y del otro. Un grafo bipartito con esos
 * dos lados tiene como maximo x*y aristas; como el arbol ya usa n-1, la
 * respuesta es x*y - (n-1). Se usa long long porque x*y puede ser ~10^10.
 *
 * Complejidad: O(n).
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int) 2e5 + 5;
vector<int> adj[N];
int n,m;

void dfs(int u, int c, vector<int>& color){
    color[u] = c;
    for(int& v : adj[u]){
        if(color[v] == -1) 
            dfs(v,1-c,color);
    }
}

void slv(){
    for(int i = 0 ; i < n-1 ; i++){
        int u,v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n,-1);
    dfs(0,0,color);
    int x = 0 , y = 0;
    for(int i = 0 ; i < n ; i++){
        if(color[i] == 0) x++;
        else y++;
    }
    ll ans = (ll) x * y  - (n-1);
    cout<<ans<<"\n";
}

int main() {
    while(cin>>n){
        slv();
        for(int i = 0 ; i < n ; i++) adj[i].clear();
    }
    return 0;
}