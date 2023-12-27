#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 2005
int fa[MAX],m,n;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int ans;
void merge(int x,int y){
    int fax=find(x);
    int fay=find(y);
    if (fax==fay) return;
    fa[fax]=fay;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=2*n;i++) fa[i]=i;
    while ( m-- ){
        char re;int x,y;
        cin>>re>>x>>y;
        if (re=='E'){
            merge(x+n,y);
            merge(y+n,x);
        }else merge(x,y);
    }
    for (int i=1;i<=n;i++) ans+=(fa[i]==i);
    cout<<ans;
    return 0;
}