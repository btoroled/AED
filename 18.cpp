/*
 * Ejercicio 18 - Permutacion a partir de restricciones en un arbol
 *
 * Problema: hay t casos. En cada uno se da n y n-1 lineas "u v x y" que
 * forman un arbol. Cada linea es una restriccion entre p_u y p_v: si x > y
 * entonces p_u > p_v, si no p_u < p_v. Hay que imprimir una permutacion
 * p_1..p_n de 1..n que cumpla todas las restricciones.
 *
 * Idea: cada restriccion se modela como una arista dirigida "menor -> mayor".
 * Como las aristas forman un arbol, el grafo dirigido no tiene ciclos (DAG),
 * asi que siempre existe un orden topologico. Se obtiene con DFS (post-orden
 * invertido) y al nodo en la posicion i del orden se le asigna el valor i+1,
 * de modo que el nodo "menor" de cada restriccion recibe un valor mas chico.
 *
 * Complejidad: O(n) por caso.
 */

#include <bits/stdc++.h>
using namespace std;
 
const int N = (int) 2e5 + 5;
vector<int> adj[N];
int n;
 
 
 
void dfs(int u, vector<int>& topo , vector<bool>& vis){
    vis[u] = true;
    for(auto& v : adj[u]){
        if(!vis[v]) dfs(v,topo,vis);
    }
    topo.push_back(u);
}
 
void slv(){
    cin>>n;
    for(int i = 0 ; i < n-1 ; i++){
        int u,v,x,y; cin>>u>>v>>x>>y;
        u--; v--;
        if(x > y) adj[v].push_back(u); // v a u
        else adj[u].push_back(v); // u a v
    }
    vector<int> topo;
    vector<bool> vis(n,false);
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]) dfs(i,topo,vis);
    }
    reverse(topo.begin(),topo.end());
    vector<int> p(n);
    for(int i = 0 ; i < n ; i++){
        p[topo[i]] = i;
    }
 
    for(int i = 0 ; i < n ; i++) cout<<(p[i] + 1)<<" ";
    cout<<"\n";
}
 
int main() {
    int t = 1; cin>>t;
    while(t--){
        slv();
        for(int i = 0 ; i < n ; i++) adj[i].clear();
    }
    return 0;
}