#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define tii tuple<int,int,int>
#define MAX 10005
vector<tii>e;
int fa[MAX],n,m,k,cnt,ans;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m>>k;
    while (m--){
        int x,y,l;
        cin>>x>>y>>l;
        e.push_back({l,y,x});
    }
    cnt=n;
    sort(e.begin(),e.end());
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=0;i<e.size();i++){
        auto &[l,y,x]=e[i];
        // cout<<l<<endl;
        if (find(x)!=find(y)){
            fa[find(x)]=find(y);
            cnt--;
            ans+=l;
        }
        if (cnt==k) break;
    }
    cout<<ans<<endl;
    return 0;
}