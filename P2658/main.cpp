#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 505
using namespace std;
#define pii pair<int, int>
int mp[MAX][MAX],token[MAX][MAX],sx,sy;
int n,m,tot;
bool bfs(int d){
    int cnt=0;
    bool vis[MAX][MAX]={false};
    queue<pii>q;
    q.push(pii(sx,sy));
    vis[sx][sy]=true;
    int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
    while (!q.empty()){
        pii cur=q.front();
        q.pop();
        if (token[cur.first][cur.second]) cnt++;
        for (int i=1;i<=4;i++){
            int nx=cur.first+dx[i],ny=cur.second+dy[i];
            if (nx<=0||nx>n||ny<=0||ny>m) continue;
            if (vis[nx][ny]) continue;
            if (abs(mp[nx][ny]-mp[cur.first][cur.second])>d) continue;
            q.push(pii(nx,ny));vis[nx][ny]=true;
        }
    }
    return cnt==tot;
}
int main(){
    cin>>n>>m;
    // for (int i=1;i<=n;i++)
    // for (int j=1;j<=m;j++)
    //     cin>>mp[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>mp[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            cin>>token[i][j];
            tot+=token[i][j];
            if (!sx&&token[i][j]) sx=i,sy=j; 
        }
    
    int l=0,r=1e9;
    while (r>=l){
        int mid=(l+r)>>1;
        // cout<<mid<<" "<<endl;
        if (bfs(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}