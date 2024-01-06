#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>
int n,m,a[105][15];
bool vis[100005];
void bfs(){
    pii now=pii((1<<n)-1,0);
    queue<pii> q;
    q.push(now);
    vis[now.first]=true;
    while(!q.empty()){
        pii cur=q.front();q.pop();
        if (!cur.first){
            cout<<cur.second<<endl;
            return;
        }
        int s=cur.first;
        for (int i=1;i<=m;i++){
            int tmp=s;
            for (int j=1;j<=n;j++){
                if (a[i][j]==1&&((s>>(j-1))&1)) s-=1<<(j-1);
                if (a[i][j]==-1&&!((s>>(j-1))&1)) s+=1<<(j-1);
            }
            if (!vis[s]){
                q.push(pii(s,cur.second+1));
                vis[s]=true;
            }
            s=tmp;
        }
    }
    cout<<-1<<endl;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    bfs();
    return 0;
}