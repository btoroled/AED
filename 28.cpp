/*
 * Ejercicio 28 - Auto de la empresa y luego tren
 * (AtCoder ABC325 E - Our clients, please wait a moment)
 *
 * Problema: hay n ciudades y una matriz D de distancias. Ir de i a j cuesta
 * D[i][j]*a minutos en auto, o D[i][j]*b + c minutos en tren. Se empieza en
 * la ciudad 1 en auto y se puede cambiar al tren (sin costo) en cualquier
 * ciudad, pero no se puede volver al auto. Hallar el tiempo minimo para
 * llegar a la ciudad n.
 *
 * Entrada: n a b c, y luego la matriz D de n x n.
 *
 * Idea: Dijkstra desde la ciudad 1 con los costos del auto (d1) y Dijkstra
 * desde la ciudad n con los costos del tren (dn). Si se cambia de transporte
 * en la ciudad u, el tiempo es d1[u] + dn[u]; la respuesta es el minimo
 * sobre todo u. Como el grafo es completo (matriz), se usa Dijkstra O(n^2).
 *
 * Complejidad: O(n^2).
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int) 2e5 + 5;
int n;
ll a,b,c;

using i2 = pair<ll,ll>;


const ll INF = (ll) 1e18;

vector<ll> Dijkstra(int s, vector<vector<ll>>& W){
    vector<ll> d(n,INF);
    d[s] = 0;
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
            ll wuv = W[u][v];
            if(d[v] > d[u] + wuv){
                d[v] = d[u] + wuv;
            }
        }
    }
    return d;
}


void slv(){
    vector<vector<ll>> Dc(n,vector<ll>(n)),Dt(n,vector<ll>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ll x; cin >> x;
            Dc[i][j] = a*x;
            Dt[i][j] = b*x + c;
        }
    }
    auto d1 = Dijkstra(0,Dc);
    auto dn = Dijkstra(n-1,Dt);
    ll ans = INF;
    for(int u = 0 ; u < n ; u++){
        ans = min(ans , d1[u] + dn[u]);
    }
    cout<<ans<<"\n";
}


int main() {
	while(cin >> n >> a >> b >> c) {
        slv();
    }
    return 0;
}
