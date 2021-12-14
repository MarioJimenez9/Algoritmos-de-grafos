#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pii pair<int, int>

const int inf = 1e9;

int main(){
    int n, m, u, v, c;
    cin>>n>>m;
    vector<vector<pii>> ad(n + 1);
    vector<int> dis(n + 1, inf);
    for(int i = 0; i < m; i++){
        cin>>u>>v>>c;
        ad[u].push_back({v, c});
    }
    //Bellman
    dis[1] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j <= n; j++){
            if(dis[j] == inf)continue;
            for(pii adyacente : ad[j]){
                dis[adyacente.ff] = min(dis[adyacente.ff], dis[j] + adyacente.ss);
            }
        }
    }
    //Comprobacion de ciclo
    bool ciclo = false;
    for(int j = 1; j <= n; j++){
        if(dis[j] == inf)continue;
        for(pii adyacente : ad[j]){
            if(dis[adyacente.ff] < dis[j] + adyacente.ss){
                ciclo = true;
                break;
            }
        }
    }
    if(dis[n] == inf){
        cout<<-1;
    }
    else{
        if(ciclo)cout<<0;
        else cout<<dis[n];
    }
    return 0;
}
