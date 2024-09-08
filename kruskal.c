#include <stdio.h>
#include <stdlib.h>

struct Edge {
	int src, dest, weight;
};

int compare(const void* a, const void* b);
int find(int parent[], int i);
void Union(int parent[], int rank[], int x, int y);
void kruskalMST(struct Edge* edge, int V, int E);

int main() {
	int V, E;
	printf("Enter the number of vertices in the graph: ");
	scanf("%d", &V);
	printf("Enter the number of edges in the graph: ");
	scanf("%d", &E);

struct Edge* edge = (struct Edge*)malloc(E * sizeof(struct Edge));
printf("Enter source, destination, and weight for each edge:\n");

for (int i = 0; i < E; ++i)
	scanf("%d %d %d", &edge[i].src, &edge[i].dest, &edge[i].weight);
	kruskalMST(edge, V, E);
	free(edge);
	
return 0;
}

	int compare(const void* a, const void* b) {
	return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

	int find(int parent[], int i) {
	if (parent[i] == -1)
		return i;
		return parent[i] = find(parent, parent[i]);
}

void Union(int parent[], int rank[], int x, int y) {
	int xroot = find(parent, x);
	int yroot = find(parent, y);

	if (rank[xroot] < rank[yroot])
		parent[xroot] = yroot;
	else if (rank[xroot] > rank[yroot])
		parent[yroot] = xroot;
	else {
		parent[yroot] = xroot;
		rank[xroot]++;
}
}

void kruskalMST(struct Edge* edge, int V, int E) {
	qsort(edge, E, sizeof(edge[0]), compare);
	struct Edge result[V];
	
	int e = 0, i = 0;
	int* parent = (int*)malloc(V * sizeof(int));
	int* rank = (int*)malloc(V * sizeof(int));
	
	for (int v = 0; v < V; ++v) {
		parent[v] = -1;
		rank[v] = 0;
	}

	while (e < V - 1 && i < E) {
		struct Edge next_edge = edge[i++];
		int x = find(parent, next_edge.src);
		int y = find(parent, next_edge.dest);
		
		if (x != y) {
			result[e++] = next_edge;
			Union(parent, rank, x, y);
		}
	}

	printf("Edge \tWeight\n");
	for (i = 0; i < e; ++i)
		printf("%d - %d \t%d \n", result[i].src, result[i].dest, result[i].weight);

	free(parent);
	free(rank);
}
