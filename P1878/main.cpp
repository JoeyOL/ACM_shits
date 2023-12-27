#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 200005
using namespace std;
#define pii pair<int, int>
#include <string>
int n;
string s;
struct Node{
    int val,idxl,idxr;
    bool operator < (const Node&n) const { 
        if (n.val!=val) return val>n.val;
        if (idxl!=n.idxl) return idxl>n.idxl;
        return idxr<n.idxr;
    }
};
priority_queue<Node>q;
bool vis[MAX];int a[MAX],cnt;
pii ans[MAX];
int pre[MAX],nxt[MAX];
int main(){
    cin>>n;
    cin>>s;
    s=" "+s;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (i==1) continue;
        if (s[i]!=s[i-1]){
            q.push({abs(a[i]-a[i-1]),i-1,i});
        } 
        pre[i]=i-1;nxt[i-1]=i;
    }
    pre[1]=0;nxt[n]=n+1;
    while (!q.empty()){
        Node now=q.top();q.pop();
        if (vis[now.idxl]||vis[now.idxr]) continue;
        vis[now.idxl]=vis[now.idxr]=true;
        cnt++;
        ans[cnt].first=now.idxl;ans[cnt].second=now.idxr;
        pre[nxt[now.idxr]]=pre[now.idxl];
        nxt[pre[now.idxl]]=nxt[now.idxr];

        int preidx=pre[now.idxl],nxtidx=nxt[now.idxr];
        // cout<<preidx<<" "<<nxtidx<<endl;
        if (preidx==0||nxtidx==n+1) continue;
        if (s[preidx]!=s[nxtidx]) q.push({abs(a[preidx]-a[nxtidx]),preidx,nxtidx});
    }
    cout<<cnt<<endl;
    for (int i=1;i<=cnt;i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}