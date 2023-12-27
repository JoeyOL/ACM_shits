#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAX 100005
#define int long long
struct Node{
    pair<int,int>val;
    bool operator <(const Node &n) const {
        if (val.first!=n.val.first) return val.first<n.val.first;
        else return val.second>n.val.second;
    }
    bool operator == (const Node &n) const {
        return val.first==n.val.first&&val.second==n.val.second;
    }
    Node(){val.first=-1,val.second=(-1);};
};
#define pii Node

priority_queue<pii>q_init;// 初始蚯蚓
queue<pii>q_left,q_right;
int n,m,q,u,v,t,i;
Node maxn(Node ii,Node jj) {
    if (ii.val.first==-1) return jj;
    if (jj.val.first==-1) return ii;
   if ((ii.val.first+(i-ii.val.second-1)*q)>(jj.val.first+(i-jj.val.second-1)*q)) return ii;
   else return jj;
}
signed main(){
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    for (i=1;i<=n;i++){
        int l;
        scanf("%d",&l);
        Node cur;
        cur.val.first=l;
        cur.val.second=0;
        q_init.push(cur);
    }
    for (i=1;i<=m;i++){
        pii top_init,top_left,top_right,final;
        if (q_init.size()) top_init=q_init.top(),final=maxn(final,top_init);
        if (q_left.size()) top_left=q_left.front(),final=maxn(final,top_left);
        if (q_right.size()) top_right=q_right.front(),final=maxn(final,top_right);

        if (q_init.size()&&final==q_init.top()) q_init.pop();
        else if (q_left.size()&&final==q_left.front()) q_left.pop();
        else if (q_right.size()&&final==q_right.front()) q_right.pop();


        pii cur_left,cur_right;
        cur_left.val.first=floor((final.val.first+(i-final.val.second-1)*q)*((long double)u/v));
        cur_left.val.second=i;;
        cur_right.val.first=(final.val.first+(i-final.val.second-1)*q)-cur_left.val.first;
        cur_right.val.second=i;
        q_left.push(cur_left);
        q_right.push(cur_right);

        if (i%t==0) printf("%d ",final.val.first+(i-final.val.second-1)*q);
    }
    cout<<endl;
    for (int j=1;q_init.size()+q_left.size()+q_right.size();j++){
        pii top_init,top_left,top_right,final;
        if (q_init.size()) top_init=q_init.top(),final=maxn(final,top_init);
        if (q_left.size()) top_left=q_left.front(),final=maxn(final,top_left);
        if (q_right.size()) top_right=q_right.front(),final=maxn(final,top_right);
        if (q_init.size()&&final==q_init.top()) q_init.pop();
        else if (q_left.size()&&final==q_left.front()) q_left.pop();
        else if (q_right.size()&&final==q_right.front()) q_right.pop();
        if (j%t==0) printf("%d ",final.val.first+(i-final.val.second-1)*q);
    }

    return 0;
}
