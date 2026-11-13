/*
 * Ejercicio 25 - Cantidad de caminos minimos
 * (LeetCode 1976 - Number of Ways to Arrive at Destination)
 *
 * Problema: hay n intersecciones (0..n-1) y calles bidireccionales con un
 * tiempo de viaje. Contar de cuantas formas se puede ir de 0 a n-1 usando el
 * menor tiempo posible. La respuesta se da modulo 1e9+7.
 *
 * Idea: Dijkstra (version O(n^2), sin cola de prioridad) llevando ademas
 * cnt[v] = cantidad de caminos minimos hasta v:
 *   - si se encuentra un camino mas corto a v, cnt[v] = cnt[u]
 *   - si se encuentra otro camino con la misma distancia, cnt[v] += cnt[u]
 *
 * Complejidad: O(n^2 + m).
 */

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    using ll = long long;
    ll INF = 1e18;
    ll mod = 1e9 + 7;
    using i2 = pair<int,ll>;
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<i2>> adj(n,vector<i2>());
        for(auto& e : edges){
            int u = e[0] , v = e[1] , w = e[2];
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }
        vector<ll> d(n,INF);
        vector<ll> cnt(n,0);
        vector<bool> vis(n,false);
        d[0] = 0;
        cnt[0] = 1;
        for(int i = 0 ; i < n ; i++){
            int u = -1;
            
            ll d_u = INF;
            for(int j = 0 ; j < n ; j++){
                if(vis[j]) continue;
                if(d[j] < d_u){
                    u = j;
                    d_u = d[j];
                }
            }
            vis[u] = true;
            // u - nodo con minima distancia entre los no visitados
            // una visitado un nodo ya esta definida su distancia
            if( u == -1) break;
            for(auto& [v,w] : adj[u]){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    cnt[v] = cnt[u];
                }
                else if (d[v] == d[u] + w){
                    cnt[v] = (cnt[v] + cnt[u]) % mod;
                }
            }
        }
        return cnt[n-1];
    }
};

int main(){
    return 0;
}