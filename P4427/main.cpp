#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define MAX 300005
#define int long long 
int sum[MAX][55],fa[MAX][25],depth[MAX];
vector<int>g[MAX];
int mod=998244353;
void dfs(int cur,int la,int dep){
    depth[cur]=dep;
    sum[cur][0]=(1)%mod;
    fa[cur][0]=la;
    for (int i=1;i<=20;i++) fa[cur][i]=fa[fa[cur][i-1]][i-1];
    for (int i=1;i<=50;i++)
        sum[cur][i]=(sum[cur][i-1]*dep%mod)%mod;
    for (int i=1;i<=50;i++) sum[cur][i]=(sum[cur][i]+sum[la][i])%mod;
    for (auto v:g[cur]){
        if (v==la) continue;
        dfs(v,cur,dep+1);
    }
}
int lca(int x,int y){
    if (depth[x]<depth[y]) swap(x,y);
    for (int i=20;i>=0;i--)
        if (depth[fa[x][i]]>=depth[y]) x=fa[x][i];
    if (x==y) return x;
    for (int i=20;i>=0;i--)
        if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int n,m;
signed main(){
    scanf("%lld",&n);
    for (int i=1;i<n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,0);
    scanf("%d",&m);
    // for (int i=1;i<=n;i++){
    //     cout<<i<<endl;
    //     for (int j=0;j<=50;j++) 
    //         cout<<sum[i][j]<<" ";
    //     cout<<endl;
    // }
    while (m--){
        int x,y,k;
        scanf("%lld%lld%lld",&x,&y,&k);
        // cout<<x<<" "<<y<<" "<<k<<endl;

        int lcaa=lca(x,y);
        int flca=fa[lcaa][0];
        // cout<<sum[x][k]<<' '<<sum[y][k]<<endl;
        printf("%lld\n",(mod+(sum[x][k]+sum[y][k])%mod-(sum[lcaa][k]+sum[flca][k])%mod)%mod);
    }
    return 0;
}