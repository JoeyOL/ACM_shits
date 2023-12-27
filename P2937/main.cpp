#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 105
#include <string>
#include <queue>
struct Node{
    int x,y;
    int pos,stp;
    bool operator < (const Node &n)const{
        return n.stp>stp;
    }
};
string mp[MAX];
int sx=-1,sy=-1,ex,ey;
int w,h;//列、行
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
bool vis[MAX][MAX][5];
int dis[MAX][MAX][5];
enum{
    INIT,LEFT,RIGHT,UP,DOWN
};
void bfs(){
    queue<Node>q;
    q.push({sx,sy,0,0});
    vis[sx][sy][0]=true;
    for (int i=0;i<h;i++)
        for (int j=0;j<w;j++)
            dis[i][j][1]=dis[i][j][2]=dis[i][j][3]=dis[i][j][4]=1e9;
    dis[sx][sy][0]=0;
    while (!q.empty()){
        // cout<<q.size()<<endl;
        Node cur=q.front();q.pop();
        vis[cur.x][cur.y][cur.pos]=false;
        Node nxt;
        for (int i=0;i<4;i++){
            int nx=dx[i]+cur.x;
            int ny=dy[i]+cur.y;
            if (nx<0||nx>=h||ny<0||ny>=w)continue;
            if (mp[nx][ny]=='*')continue;
            nxt.x=nx;nxt.y=ny;
            nxt.pos=i+1;
            if (cur.pos==LEFT&&nxt.pos==RIGHT) continue;
            if (cur.pos==UP&&nxt.pos==DOWN) continue;

            nxt.stp=dis[cur.x][cur.y][cur.pos]+(nxt.pos!=cur.pos);
            if (dis[nx][ny][nxt.pos]>nxt.stp){
                dis[nx][ny][nxt.pos]=nxt.stp;
                // cout<<nx<<' '<<ny<<' '<<nxt.stp<<' '<<nxt.pos<<endl;
                if (!vis[nx][ny][nxt.pos]) 
                    vis[nx][ny][nxt.pos]=true,q.push(nxt);
            } 

        }
    }
    cout<<min(min(dis[ex][ey][1],dis[ex][ey][2]),min(dis[ex][ey][3],dis[ex][ey][4]))-1;
}
int main(){
    cin>>w>>h;
    for (int i=0;i<h;i++){
        cin>>mp[i];
        for (int j=0;j<mp[i].size();j++){
            if (mp[i][j]=='C'&&sx==-1) sx=i,sy=j;
            else if (mp[i][j]=='C') ex=i,ey=j;
        }
    }
    // std::cout<<sx<<' '<<sy<<endl;
    // for (int i=0;i<h;i++) std::cout<<mp[i]<<endl;
    bfs();
    return 0;
}