#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int N, W;

	if(scanf("%d", &N) != 1) return 0;

	int *values = (int *)malloc(N * sizeof(int));
	int *weights = (int *)malloc(N * sizeof(int));

	for(int i = 0; i < N; i++) {
		scanf("%d", &values[i]);
	}

	for(int i = 0; i < N; i++) {
		scanf("%d", &weights[i]);
	}

	scanf("%d", &W);

	int *dp = (int *)calloc(W + 1, sizeof(int));

	for(int i = 0; i < N; i++) {
		for(int w = W; w >= weights[i]; w--) {
			dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
		}
	}

	printf("%d\n", dp[W]);

	free(values);
	free(weights);
	free(dp);

	return 0;
}
