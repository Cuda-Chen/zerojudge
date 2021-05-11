// https://programinn.blogspot.com/2020/10/f314-3-apcs-20201017.html
// DP

#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int m, n, x;
    scanf("%d %d", &m, &n);
    vector<vector<int>> map(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    vector<vector<int>> dp_left(m, vector<int>(n, INT_MIN));
    vector<vector<int>> dp_right(m, vector<int>(n, INT_MIN));
    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
    dp_right[0][0] = map[0][0];
    dp_left[0][n - 1] = map[0][n - 1];
    for(int i = 1; i < n; i++) {
        dp_right[0][i] = max(dp_right[0][i - 1] + map[0][i], map[0][i]);
        dp_left[0][n - i - 1] = max(dp_left[0][n - i] + map[0][n - i - 1], map[0][n - i - 1]);
        dp[0][i] = max(dp_right[0][i], dp_left[0][i]);
        dp[0][n - i - 1] = max(dp_right[0][n - i - 1], dp_left[0][n - i - 1]);
    }

    int half = n / 2;
    for(int j = 1; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(i == 0)
                dp_right[j][i] = dp[j - 1][i];
            else
                dp_right[j][i] = max(dp_right[j][i - 1], dp[j - 1][i]);
            dp_right[j][i] += map[j][i];

            if(i == 0)
                dp_left[j][n - i - 1] = dp[j - 1][n - i - 1];
            else
                dp_left[j][n - i - 1] = max(dp_left[j][n - i], dp[j - 1][n - i - 1]);
            dp_left[j][n - i - 1] += map[j][n - i - 1];

            if(i >= half) {
                dp[j][i] = max(dp_right[j][i], dp_left[j][i]);
                dp[j][n - i - 1] = max(dp_right[j][n - i - 1], dp_left[j][n - i - 1]);
            }
        }
    }

    printf("%d\n", *max_element(dp[m - 1].begin(), dp[m - 1].end()));

    return 0;
}
