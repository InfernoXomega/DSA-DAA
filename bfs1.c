#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 40

typedef struct
{
	int items[MAX_SIZE];
	int front;
	int rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, int value) ;
int dequeue(Queue* q);
int isEmpty(Queue* q);

void BFS(int graph[][MAX_SIZE], int start, int n)
{
	Queue* q = createQueue();
	int visited[MAX_SIZE] = {0};
	
	visited[start]=1;
	enqueue(q, start);
	 
	while(!isEmpty(q))
	{
		int current = dequeue(q);
		printf("%d ", current);
		
		for(int i=0; i<n; i++)
		{
			if(graph[current][i] == 1 && !visited[i])
			{
				visited[i] = 1;
				enqueue(q, i);
			}
		} 
	}
	free(q);
}

Queue* createQueue() 
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

void enqueue(Queue* q, int value) 
{
	if (q->rear == MAX_SIZE - 1) 
	{
		printf("Queue is full.\n");
		return;
	}

	if (q->front == -1)
	q->front = 0;
	q->rear++;
	q->items[q->rear] = value;
}

int dequeue(Queue* q) 
{
	int item;
	if (isEmpty(q)) 
	{
		printf("Queue is empty.\n");
		item = -1;
	} 
	else 
	{
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear) 
		{
			q->front = q->rear = -1;
		}
	}
	return item;
}

int isEmpty(Queue* q) 
{
	return q->rear == -1;
}


int main() 
{
	int n, start;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	int graph[MAX_SIZE][MAX_SIZE];
	printf("Enter the adjacency matrix:\n");
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			scanf("%d", &graph[i][j]);
		}
	}

	printf("Enter the starting vertex: ");
	scanf("%d", &start);
	printf("BFS traversal: ");
	BFS(graph, start, n);
	return 0;
}
