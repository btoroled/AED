/*
 * Ejercicio 13 - Operaciones para conectar una red
 * (LeetCode 1319 - Number of Operations to Make Network Connected)
 *
 * Problema: hay n computadoras (0..n-1) unidas por cables (edges). En cada
 * operacion se puede quitar un cable entre dos computadoras y ponerlo entre
 * otras dos. Devolver el minimo numero de operaciones para que toda la red
 * quede conectada, o -1 si no es posible.
 *
 * Idea: con menos de n-1 cables es imposible conectar n nodos -> -1.
 * Si alcanzan los cables, se cuentan las componentes conexas con DFS; cada
 * componente extra necesita un cable para unirse al resto, asi que la
 * respuesta es (componentes - 1).
 *
 * Complejidad: O(n + m).
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static const int N = 1e5 + 5;
    vector<int> adj[N];

    void dfs(int u,vector<bool>& vis){
        vis[u] = true;
        for(auto& v : adj[u]){
            if(!vis[v]) dfs(v,vis);
        }
    }

    int makeConnected(int n, vector<vector<int>>& edges) {
        if(edges.size() < n-1) return -1;
        for(auto& e : edges){
            int u = e[0] , v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis);
            }
        }
        return cnt - 1;
    }
};

int main(){
    return 0;
}