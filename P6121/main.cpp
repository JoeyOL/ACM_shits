#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100005
vector<int>g[MAX];
int f[MAX];
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); };

int n,m;
int des[MAX];
bool rec[MAX],ans[MAX];
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        des[i]=a;
    }
    for (int i=1;i<=n;i++) f[i]=i;
    int cur=1;
    for (int i=n;i>=1;i--){
        rec[des[i]]=true;
        for (auto v:g[des[i]]){
            if (rec[v]){
                int fav=find(v);
                int fau=find(des[i]);
                if (fav!=fau) {
                    cur++;
                    f[fav]=fau;
                }
            }
        }
        if (cur>=n-i+1) ans[i]=true;
    }
    for (int i=1;i<=n;i++) 
        if (ans[i]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    return 0;
}