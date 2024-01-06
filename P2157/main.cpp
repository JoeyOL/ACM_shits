#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1005
#define la(i) i+8
int f[MAX][1<<(8)][20],n,t;
int a[MAX],b[MAX];

void work(){
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    memset(f,0x3f,sizeof(f));
    f[1][0][la(-1)]=0;
    for (int i=1;i<=n;i++){
        for (int s=0;s<(1<<8);s++){
            for (int k=-8;k<=7;k++){
                if (f[i][s][la(k)]==0x3f3f3f3f) continue;
                if (s&1) 
                    f[i+1][s>>1][la(k-1)]=min(f[i+1][s>>1][la(k-1)],f[i][s][la(k)]);
                else{
                    int maxr=0x3f3f3f3f;
                    for (int nxt=0;nxt<=7;nxt++){
                        if (s&(1<<nxt)) continue;
                        if (i+nxt>maxr) continue;
                        maxr=min(maxr,i+nxt+b[i+nxt]);
                        f[i][s|(1<<nxt)][la(nxt)]=min(f[i][s|(1<<nxt)][la(nxt)],f[i][s][la(k)]+(i+k?a[i+k]^a[i+nxt]:0));
                    }
                }
            }
        }
    }
    int res=0x3f3f3f3f;
    for (int k=-8;k<=0;k++){
        res=min(res,f[n][1][la(k)]);
    }
    cout<<res<<endl;
}
int main(){
    cin>>t;
    while (t--){
        cin>>n;
        work();
    }
    return 0;
}