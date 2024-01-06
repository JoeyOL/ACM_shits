#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100005
typedef long long ll;
ll mod=1e9+1;
ll f[20][1<<(11)],vis[MAX],valid[1<<11],ans=1;
int n;
void work(int x){
    int sz[21]={0};
    int p=1;
    for (int i=x;i<=n;i*=2,p++){
        for (int j=i;j<=n;j*=3){
            sz[p]++;vis[j]++;
        }
    }

    for (int s=0;s<(1<<(sz[1]));s++) 
        f[1][s]=valid[s];
    for (int i=2;i<p;i++){
        for (int s=0;s<(1<<(sz[i]));s++){
            if (!valid[s]) continue;
            f[i][s]=0;
            for (int k=0;k<(1<<(sz[i-1]));k++){
                if (!valid[k]) continue;
                if ((s&k)) continue;
                f[i][s]=(f[i][s]+f[i-1][k])%mod;
            }
        }
    }
    ll sum=0;
    for (int s=0;s<(1<<(sz[p-1]));s++){
        if (!valid[s]) continue;
        sum=(sum+f[p-1][s])%mod;
    }
    ans=ans*sum%mod;
}

int main(){
    cin>>n;
    for (int i=0;i<(1<<11);i++){
        if ((i<<1)&i) valid[i]=0;
        else valid[i]=1;
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]) work(i);
    }
    cout<<ans<<endl;
    return 0;
}
