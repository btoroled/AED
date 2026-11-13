/*
 * DFS_islas - Contar islas en una grilla
 *
 * Problema: se da una grilla de n x m donde '.' es agua y cualquier otro
 * caracter es tierra. Una isla es un grupo de celdas de tierra conectadas en
 * 4 direcciones (arriba, abajo, izquierda, derecha). Imprimir la cantidad de
 * islas y la cantidad de celdas de la isla mas grande.
 *
 * Idea: se recorre la grilla y cada vez que se encuentra una celda de tierra
 * no visitada se lanza una DFS que marca toda su isla y devuelve su tamanio.
 *
 * Complejidad: O(n * m).
 */

#include <bits/stdc++.h>
using namespace std;


int DFS(int x, int y, vector<string> &s, vector<vector<bool>> &vis){
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    vis[x][y] = true;

    int res =1;
    for(int k = 0; k < 4; ++k){
        int vx = x + dx[k];
        int vy = y + dy[k];
        if(vx < 0 || vx >= s.size() || vy < 0 || vy >= s[0].size()) continue;
        if(s[vx][vy] == '.') continue;
        if(vis[vx][vy])continue;
        res+= DFS(vx, vy, s, vis);
    }
    return res;
}


int main() {
	cin.tie(0)-> sync_with_stdio(false);

    int n, m;
    cin>> n >> m;
    vector<string> G(n);
    for(int i = 0; i < n ; i++) cin>>G[i];
    int cnt_islas = 0; int max_isla = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(G[i][j] == '.') continue;
            if(vis[i][j]) continue;
            max_isla = max(max_isla, DFS(i, j, G, vis));
            ++cnt_islas;
        }
    }

    cout << cnt_islas << " " << max_isla << '\n';


}
