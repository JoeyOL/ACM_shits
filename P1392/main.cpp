#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 805
int n,m,k;
int a[MAX],b[MAX];
class Heap{
    private:
       int data[MAX],sz;
    public:
        Heap():sz(0){
            for(int i=0;i<MAX;i++){
                data[i]=0;
            }
        }
        void insert(int x){
            data[++sz]=x;
            int i=sz;
            while(i>1&&data[i/2]<data[i]){
                swap(data[i/2],data[i]);
                i/=2;
            }
        }
        void remove(){
            data[1]=data[sz];
            sz--;
            int i=1,j=2;
            while(j<=sz){
                if(j<sz&&data[j]<data[j+1]){
                    j++;
                }
                if(data[i]<data[j]){
                    swap(data[i],data[j]);
                    i=j;
                    j=2*i;
                }else{
                    break;
                }
            }
        }
        int len(){return sz;}
        int maxn(){return data[1];}      
};
int main(){
    scanf("%d%d%d",&n,&m,&k);
    Heap q=Heap();
    while(n--){
        for (int i=1;i<=m;i++) scanf("%d",a+i);
        sort(a+1,a+m+1);
        int cnt=0;
        while (q.len()) b[++cnt] =q.maxn(),q.remove();
        if (!cnt) {
            for (int i=1;i<=min(m,k);i++) q.insert(a[i]);
            continue;
        }
        for (int i=1;i<=m;i++){
            for (int j=cnt;j>=1;j--){
                if (q.len()<k) q.insert(a[i]+b[j]);
                else if (a[i]+b[j]>=q.maxn()) break;
                else q.remove(),q.insert(a[i]+b[j]);
            }
        }
    }
    for (int i=k;i>0;i--) b[i]=q.maxn(),q.remove();

    for (int i=1;i<=k;i++) printf("%d ",b[i]);
    return 0;
}