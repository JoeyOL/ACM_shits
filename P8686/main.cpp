#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 2000005
int fa[MAX],a[MAX],n,b[MAX];
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=MAX-1;i++) fa[i]=i;
    fa[a[1]]=a[1]+1;
    b[1]=a[1];
    for (int i=2;i<=n;i++){
        int fai=find(a[i]);
        b[i]=fai;
        fa[fai]=fai+1;
    }
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}