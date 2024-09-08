#include <stdio.h>
#include <limits.h>

#define inf 9999
#define max 100

int minDistance(int dist[], int spt[], int vertices) {
	int min = inf, minIndex;

	for (int v = 0; v < vertices; v++) {
		if (!spt[v] && dist[v] < min) {
			min = dist[v];
			minIndex = v;
		}
	}

	return minIndex;
}

void print(int dist[], int vertices) {
	printf("Vertex \tDistance from Source\n");
	
	for (int i = 0; i < vertices; i++) {
		printf("%d \t%d\n", i, dist[i]);
	}
}

void dijkstra(int graph[max][max], int src, int vertices) {
	int dist[max]; 
	int spt[max]; 

	for (int i = 0; i < vertices; i++) {
		dist[i] = inf;
		spt[i] = 0;
	}
	
	dist[src] = 0;


	for (int count = 0; count < vertices - 1; count++) {
		int u = minDistance(dist, spt, vertices);
		spt[u] = 1;

		for (int v = 0; v < vertices; v++) {
			if (!spt[v] && graph[u][v] && dist[u] != inf && dist[u] + graph[u][v] < dist[v]) {
			dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	
	print(dist, vertices);
}

int main() {
	int vertices;

	printf("Input the number of vertices: ");
	scanf("%d", &vertices);

	if (vertices <= 0 || vertices > max) {
		printf("Invalid number of vertices. Exiting...\n");
		return 1;
	}

	int graph[max][max];

	printf("Input the adjacency matrix for the graph (inf - infinity):\n");
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
		scanf("%d", &graph[i][j]);
		}
	}

	int source;

	printf("Input the source vertex: ");
	scanf("%d", &source);

	if (source < 0 || source >= vertices) {
		printf("Invalid source vertex. Exiting...\n");
		return 1;
	}

	dijkstra(graph, source, vertices);

	return 0;
}
