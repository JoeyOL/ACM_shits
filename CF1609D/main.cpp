#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
#define MAX 10005
#define pii pair<int,int>
int fa[MAX],n,d,k=0,sz[MAX];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
vector<int>v;
int main(){
    cin>>n>>d;
    for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for (int i=1;i<=d;i++){
        int x,y;
        cin>>x>>y;
        int fax=find(x);
        int fay=find(y);
        if (fax==fay) k++;
        else {
            fa[fax]=fay;
            sz[fay]+=sz[fax];
            // v.push_back(sz[fay]);
            // cout<<sz[fay]<<endl;;
        }
        v.clear();
        for (int i=1;i<=n;i++){
            if (fa[i]==i) v.push_back(sz[i]);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        for (int i=0;i<=min(v.size()-1,1ULL*k);i++) ans+=v[i];
        cout<<ans-1<<endl;
        
    }
    return 0;
}