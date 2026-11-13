/*
 * Ejercicio B - Camino minimo en un grafo completo con pesos generados
 *
 * Problema: hay n nodos (1..n) y entre cada par x != y existe una arista con
 * peso ((x+y)*p + x*y*q) mod m + 1. Encontrar la distancia minima de 1 a n
 * y, entre todos los caminos con esa distancia, la menor cantidad de
 * aristas. Si n == 1 la respuesta es "0 0".
 *
 * Entrada: n p q m.
 * Salida: distancia_minima cantidad_minima_de_aristas.
 *
 * Idea: Dijkstra O(n^2). Como el grafo es completo no se guardan las
 * aristas: el peso se calcula al vuelo con la formula. Ademas de d[v] se
 * guarda l[v], el minimo numero de aristas para llegar a v con distancia
 * d[v]; ante un empate en la distancia se queda con el menor l.
 *
 * Complejidad: O(n^2).
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int) 2e5 + 5;
int n;
int p,q,m;

using i2 = pair<ll,ll>;


const ll INF = (ll) 1e18;

pair<vector<ll>,vector<int>> Dijkstra(int s){
    vector<ll> d(n,INF);
    vector<int> l(n,1e9 + 7);
    d[s] = 0; l[s] = 0;
    vector<bool> vis(n,false);

    int iter = n;
    while(iter--){
        //u el nodo con menor distancia que no ha sido visitado
        
        int u = -1;
        ll d_u = INF;
        for(int i = 0 ; i < n ; i++){
            if(vis[i]) continue;
            if(d[i] < d_u){
                u = i;
                d_u = d[i];
            }
        }

        assert(u != -1);

        vis[u] = true;

        for(int v = 0 ; v < n ; v++){
            if(v == u) continue;
            ll x = u+1;
            ll y = v+1;
            ll wuv = ((x+y)*p + x*y*q) % m + 1;
            if(d[v] > d[u] + wuv){
                d[v] = d[u] + wuv;
                l[v] = l[u] + 1;
            }
            else if(d[v] == d[u] + wuv){
                l[v] = min(l[v] , l[u] + 1);
            }
        }
    }
    return {d,l};
}


void slv(){
    if(n == 1){
        cout<<"0 0\n";
        return;
    }
    

    auto [d,l] = Dijkstra(0);
    cout<<d[n-1]<<" "<<l[n-1]<<"\n";
}


signed main() {
	while(cin >> n >> p >> q >> m) {
        slv();
    }
    return 0;
}
