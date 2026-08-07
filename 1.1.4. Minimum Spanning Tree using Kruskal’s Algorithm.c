#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

	// Write your code here...
	int parent[V];

	for(int i = 0; i < V; i++) {
		parent[i] = i;
	}

	int ne = 0;
	int mincost = 0;

	while(ne < V - 1) {
		int min = 9999;
		int a = -1, b = - 1;

		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				if(cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		if(a != -1 && b != -1) {
			int u = a;
			while(parent[u] != u) {
				u = parent[u];
			}

			int v = b;
			while(parent[v] != v) {
				v = parent[v];
			}

			if(u != v) {
				printf("Edge %d:(%d, %d) cost:%d\n", ne++, a, b, min);
				mincost += min;
				parent[u] = v;
			}

			cost[a][b] = 9999;
		} else {
			break;
		}
	}
	printf("Minimum cost= %d\n", mincost);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
