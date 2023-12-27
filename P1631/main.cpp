#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
#define MAX 100005
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
    int n;
    Heap q=Heap();
    // cin>>n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) scanf("%d",b+i);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (q.len()<n) q.insert(a[i]+b[j]);
            else if (q.maxn()<=a[i]+b[j]) continue;
            else q.remove(),q.insert(a[i]+b[j]);
        } 
    }
    for (int i=n;i>=1;i--){
        a[i]=q.maxn();
        q.remove();
    }
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    cout<<endl;
    return 0;
}