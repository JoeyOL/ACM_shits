#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
#define pii pair<ll, ll>
#define MAX 1000005
ll n,ans;
ll diameter[MAX],longestPath[MAX];
bool notOnLoop[MAX],vis[MAX];
ll deg[MAX];
vector<pii>g[MAX];
queue<ll> q;
void bfs(){
    for (ll i=1;i<=n;i++){
        if (deg[i]==1) {
            q.push(i);
            notOnLoop[i] = true;
        } 
    }
    while (q.size()){
        ll u=q.front();
        q.pop();
        // notOnLoop[u]=true;
        for (auto &[v,w]:g[u]){
            if (notOnLoop[v]) continue;
            deg[v]--;
            if (deg[v]==1){
                q.push(v);
                notOnLoop[v] = true;
            }
        }
    }
}
ll dfs(ll cur,ll la){
    ll d1=0,d2=0;
    for (auto &[v,w]:g[cur]){
        if (v==la||!notOnLoop[v]) continue;
        ll tmp=dfs(v,cur)+w;
        diameter[cur]=max(diameter[cur],diameter[v]);
        if (tmp>=d1) d2=d1,d1=tmp;
        else if (tmp>d2) d2=tmp;
    }
    diameter[cur]=max(diameter[cur],d1+d2);
    // cout<<cur<<" "<<d1<<" "<<d2<<endl;
    longestPath[cur]=d1;
    return d1;
}
ll dealLoop(int x){
    int tmp=x,pre=0,cur=x,nxt=0;
    ll totLen=0;
    ll m1=-1e18,m2=-1e18,res=-1e18,res1=-1e18,res2=-1e18,res3=-1e18;
    do{
        bool nxtflg=false;
        vis[cur]=true;
        dfs(cur,0);
        res3=max(diameter[cur],res3);
        res1=max(longestPath[cur]+totLen+m1,res1);
        res2=max(longestPath[cur]-totLen+m2,res2);
        m1=max(longestPath[cur]-totLen,m1);
        m2=max(longestPath[cur]+totLen,m2);
        for (auto &[v,w]:g[cur])
            if (!notOnLoop[v]&&v!=pre) {nxtflg=true;nxt=v;totLen+=w;break;}

        if (!nxtflg) {
            int tp=totLen;
            for (auto &[v,w]:g[cur])
                if (v==pre) tp+=w;
            totLen=tp-totLen;
            break;
        }
        pre=cur;
        cur=nxt;
    }while (cur!=tmp);
    return max(max(res1,res2+totLen),res3);
}
int main(){
    scanf("%d",&n);
    for (ll i=1;i<=n;i++){
        ll a=i,b,w;
        scanf("%d%d",&b,&w);
        g[a].push_back(pii(b,w));
        g[b].push_back(pii(a,w));
        deg[a]++;
        deg[b]++;
    }
    bfs();
    for (int i=1;i<=n;i++){
        if (!notOnLoop[i]&&!vis[i]) 
            ans+=dealLoop(i);
    }
    cout<<ans<<endl;
    return 0;
}
