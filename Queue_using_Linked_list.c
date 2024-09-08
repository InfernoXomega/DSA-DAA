#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}


int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}


void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    printf("Enqueued: %d\n", data);
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1; 
    } else {
        int data = queue->front->data;
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}


void display(struct Queue* queue) {
    struct Node* current = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\t");
        printf("2. Dequeue\t");
        printf("3. Display\t");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
