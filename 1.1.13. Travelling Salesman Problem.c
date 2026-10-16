#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9
#define MAX_N 20

int n;
int cost[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];


int solve(int mask, int u) {

    if (mask == (1 << n) - 1) {
        if (cost[u][0] != -1) {
            return cost[u][0];
        }
        return INF;
    }

    if (dp[mask][u] != -1) {
        return dp[mask][u];
    }

    int min_cost = INF;

    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v)) && cost[u][v] != -1) {
            int new_cost = cost[u][v] + solve(mask | (1 << v), v);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }

    return dp[mask][u] = min_cost;
}

int main() {
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = solve(1, 0);

    if (ans >= INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}

