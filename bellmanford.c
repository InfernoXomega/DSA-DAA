#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct Edge {
	int source, destination, weight;
};

struct Graph {
	int V, E;
	struct Edge edges[MAX_EDGES];
};


void initializeGraph(struct Graph* graph, int V, int E) {
	graph->V = V;
	graph->E = E;
}

void BellmanFord(struct Graph* graph, int source) {
	int V = graph->V;
	int E = graph->E;
	int distance[MAX_VERTICES];

	for (int i = 0; i < V; ++i)
	distance[i] = INT_MAX;
	distance[source] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edges[j].source;
			int v = graph->edges[j].destination;
			int weight = graph->edges[j].weight;
			if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
				distance[v] = distance[u] + weight;
		}
	}

	for (int i = 0; i < E; i++) {
		int u = graph->edges[i].source;
		int v = graph->edges[i].destination;
		int weight = graph->edges[i].weight;
		if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
			printf("Graph contains negative weight cycle.\n");
			return;
		}
	}

	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++)
	printf("%d \t\t %d\n", i, distance[i]);
}

int main() {
	struct Graph graph;
	int V, E, source;

	printf("Enter number of vertices and edges: ");
	scanf("%d %d", &V, &E);

	initializeGraph(&graph, V, E);

	printf("Enter source vertex: ");	
	scanf("%d", &source);

	printf("Enter edge source, destination, and weight:\n");
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &graph.edges[i].source, &graph.edges[i].destination, &graph.edges[i].weight);
	}

	BellmanFord(&graph, source);

	return 0;
}
