#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;
string f[MAX];
int fa[MAX<<2];

int n,minn=1e9,maxn;


int main() {
    cin >> n;
    for (int i = 1; i <= n;i++) {
        int k, x;
        cin >> f[i] >> k;
        int len = f[i].length();
        len;

        for (int j = 1; j <= k; j++) {
            cin >> x;
            minn = min(x, minn);
            maxn = max(x, maxn);
            if (f[fa[x]].size() >= len) continue;
            fa[x] = i;
        }
    }
    for (int i = 1; i < minn; i++) cout << 'a';
    for (int i = minn; i<=maxn; i++) {
        if (!f[fa[i]].size()) {
            cout << 'a'; 
            continue;
        }
        int j;
        for ( j=0; j <= f[fa[i]].size() - 1; j++) {
            if (f[fa[i + j]].size() + j > f[fa[i]].size()) break;
            else cout << f[fa[i]][j];
        }
        i =i+j-1;
    }
    return 0;
}
