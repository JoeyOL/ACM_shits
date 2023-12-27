#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int, int>
priority_queue<pii,vector<pii>,greater<pii>> q;
struct Node{
	int a,b,c;
	bool operator < (const Node& other) const{
		return b>other.b;
	}
};
vector<Node>v;
long long ans;
int main(){
	int x,n;
	cin>>x>>n;
	for (int i=1;i<=n;i++){
		int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
	}
	sort(v.begin(),v.end());
	int pos=0;
	for (int t=x;t>=1;t--){
		while (v[pos].b>=t){
			q.push({v[pos].a,v[pos].c});
			pos++;
		}
		if (q.empty()){
			cout<<-1;
			return 0;
		}
		pii cur=q.top();q.pop();
		ans+=1LL*cur.first;
		cur.second--;
		if (cur.second) q.push(cur);

	}
	cout<<ans;
	return 0;
}