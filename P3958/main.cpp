#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;
#define tll tuple<ll,ll,ll>
#define MAX 1005
int fa[MAX],n,h,r;
bool check(tll i,tll j){
    auto &[ix,iy,iz]=i;
    auto &[jx,jy,jz]=j;
    // cout<<ix<<" "<<iy<<" "<<iz<<" "<<
    // jx<<" "<<jy<<" "<<jz<<endl;
    return ((ix-jx)*(ix-jx)+(iy-jy)*(iy-jy)+(iz-jz)*(iz-jz))<=4*r*r;
}
tll p[MAX];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int i,int j){
    i=find(i),j=find(j);
    if(i==j) return;
    fa[i]=j;
}
void solve(){
    cin>>n>>h>>r;
    for (int i=0;i<=n+1;i++) fa[i]=i;
    for (int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        p[i]=tll(x,y,z);
    }
    for (int i=1;i<=n;i++){
        auto &[x,y,z]=p[i];
        if (z<=r) merge(i,0);
        if (z+r>=h)merge(i,n+1);
        for (int j=1;j<=n;j++){
            if (check(p[i],p[j])){
                // cout<<i<<" "<<j<<endl;
                merge(i,j);
            }
        }
    }
    if (find(0)==find(n+1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}