#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
struct Node {
    int data;
    int priority;
};

// Structure to represent the priority queue
struct PriorityQueue {
    struct Node *array;
    int capacity;
    int size;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    return newNode;
}

// Function to create a new priority queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->array = (struct Node*)malloc(capacity * sizeof(struct Node));
    return pq;
}

// Function to swap two nodes
void swap(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with the root at given index
void minHeapify(struct PriorityQueue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->array[left].priority < pq->array[smallest].priority)
        smallest = left;

    if (right < pq->size && pq->array[right].priority < pq->array[smallest].priority)
        smallest = right;

    if (smallest != index) {
        swap(&pq->array[index], &pq->array[smallest]);
        minHeapify(pq, smallest);
    }
}

// Function to enqueue a new element into the priority queue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    if (pq->size == pq->capacity) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    struct Node* newNode = createNode(data, priority);
    int i = pq->size;
    pq->size++;
    pq->array[i] = *newNode;

    // Fix the min heap property
    while (i > 0 && pq->array[(i - 1) / 2].priority > pq->array[i].priority) {
        swap(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to dequeue the element with the highest priority
struct Node dequeue(struct PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Queue is empty. Cannot dequeue.\n");
        struct Node emptyNode = { -1, -1 };
        return emptyNode;
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->array[0];
    }

    struct Node root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return root;
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue(10);

    enqueue(pq, 5, 2);
    enqueue(pq, 10, 1);
    enqueue(pq, 3, 4);
    enqueue(pq, 7, 3);

    printf("Dequeued: %d (Priority: %d)\n", dequeue(pq).data, dequeue(pq).priority);
    printf("Dequeued: %d (Priority: %d)\n", dequeue(pq).data, dequeue(pq).priority);

    return 0;
}