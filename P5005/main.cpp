#include <iostream>
#include <algorithm>
using namespace std;
int f[2][1<<6][1<<6],n,m;
int mod=1e9+7;
bool chk3(int k1,int k2,int k3){
    for (int i=0;i<m;i++){
        if (!((k1>>i)&1)) continue;
        if (((k2>>i)&1)) continue;
        if (((k3>>(i+1))&1)) return false;
        if (i>0&&((k3>>(i-1))&1)) return false;
    }
    for (int i=0;i<m;i++){
        if (!((k3>>i)&1)) continue;
        if (((k2>>i)&1)) continue;
        if (((k1>>(i+1))&1)) return false;
        if (i>0&&((k1>>(i-1))&1)) return false;
    }
    return true;
}

bool chk2(int k1,int k2){
    for (int i=0;i<m;i++){
        if (!((k1>>i)&1)) continue;
        if (!((k1>>(i+1))&1)&&((k2>>(i+2))&1)) return false;
        if (i>1&&!((k1>>(i-1))&1)&&((k2>>(i-2))&1)) return false;
    }
    for (int i=0;i<m;i++){
        if (!((k2>>i)&1)) continue;
        if (!((k2>>(i+1))&1)&&((k1>>(i+2))&1)) return false;
        if (i>1&&!((k2>>(i-1))&1)&&((k1>>(i-2))&1)) return false;
    }
    return true;
}

int main(){
    // cout<<(chk3(10,16,16));
    cin>>n>>m;
    for (int s=0;s<(1<<m);s++) f[1&1][s][0]=1;
    for (int s=0;s<(1<<m);s++){
        for (int s1=0;s1<(1<<m);s1++){
            if (!chk2(s1,s)) continue;
            f[2&1][s][s1]=(f[2&1][s][s1]+f[1&1][s1][0])%mod;
        }
    }
    for (int i=3;i<=n;i++){
        for (int k1=0;k1<(1<<m);k1++){
            for (int k2=0;k2<(1<<m);k2++){
                f[i&1][k1][k2]=0;
                if (!chk2(k1,k2)) continue;
                for (int k3=0;k3<(1<<m);k3++){
                    if (!chk2(k2,k3)) continue;
                    if (!chk3(k1,k2,k3)) continue;
                    f[i&1][k1][k2]=(f[(i-1)&1][k2][k3]+f[i&1][k1][k2])%mod;
                }
            }
        }
    }
    int ans=0;
    for (int k1=0;k1<(1<<m);k1++){
        for (int k2=0;k2<(1<<m);k2++){
            if (!chk2(k1,k2)) continue;
            ans=(ans+f[n&1][k1][k2])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
