#include <stdio.h>
#include <stdlib.h>

#define V 100  // Maximum number of vertices
#define INF 99999  // A large number to represent infinity

void floydWarshall(int graph[][V], int n) {
    int dist[V][V];

    // Initialize the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("X ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter the adjacency matrix (use 'X' for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char input[10];
            scanf("%s", input);
            if (input[0] == 'X' || input[0] == 'x') {
                graph[i][j] = INF;
            } else {
                graph[i][j] = atoi(input);
            }
        }
    }

    floydWarshall(graph, n);

    return 0;
}
