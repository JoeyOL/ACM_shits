#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;long long ans;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
    cin>>n;
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        q.push(a);
    }
    while (q.size()>1){
        int a=q.top();
        q.pop();
        int b=q.top();
        ans+=1LL*a+b;
        q.pop();
        q.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}