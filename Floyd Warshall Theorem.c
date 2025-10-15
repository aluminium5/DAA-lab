#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N
int main() {
	int N, E;
	printf("Enter the number of vertices : ");
	scanf("%d", &N);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	int dist[N+1][N+1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		int u, v, w;
		printf("Enter source : ");
		scanf("%d", &u);
		printf("Enter destination : ");
		scanf("%d", &v);
		printf("Enter weight : ");
		scanf("%d", &w);
		dist[u][v] = w;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF &&
					dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF)
				printf("%4s","  INF");
			else
				printf(" %4d",dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
