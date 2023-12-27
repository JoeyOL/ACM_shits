#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 30
int n, h, f[MAX], d[MAX], t[MAX];
using namespace std;
int dp[MAX][MAX * MAX];
int get_val(int c, int i) {
    if (c < 0) return 0;
    if (f[i] - d[i] * (c - 1) < 0)
        return f[i] * (f[i] / d[i] + 1) / 2;
    else return (f[i] + f[i] - d[i] * (c - 1)) * c / 2;
}
int ans = 0;
int main() {
    cin >> n >> h;
    h *= 12;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 2; i <= n; i++) cin >> t[i], t[i] += t[i - 1];

    for (int i = 1; i <= n; i++) {
        for (int j = t[i]; j <= h; j++) {
            for (int k = 0; k < i; k++) {
                for (int c = t[k]; c <=j-(t[i]-t[k]); c++) {
                    dp[i][j] = max(dp[i][j], dp[k][c] + get_val(j-c- (t[i] - t[k]), i));

                }
            }
        }

        ans = max(dp[i][h], ans);
    }

    cout << ans << endl;
    return 0;
}