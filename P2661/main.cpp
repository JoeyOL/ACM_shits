#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 200005
int fa[MAX],dis[MAX],ans=1e9;
int find(int x){
    if (fa[x]==x) return x;
    int tmp=fa[x];
    fa[x]=find(fa[x]);
    dis[x]+=dis[tmp];
    return fa[x];
}
void check(int x,int y){
    int fax=find(x);
    int fay=find(y);
    if (fax==fay) ans=min(ans,dis[x]+dis[y]+1);
    else {
        fa[fax]=fay;
        dis[x]=dis[y]+1;
    }
}
int a[MAX];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=n;i++) cin>>a[i];

    for (int i=1;i<=n;i++)
        check(i,a[i]);
    cout<<ans<<endl;
    return 0;
}