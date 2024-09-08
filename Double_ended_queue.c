#include <stdio.h>
#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1, rear = -1;

void enqueueFront(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
}

void enqueueRear(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

void dequeueFront() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Removed element from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void dequeueRear() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Removed element from rear: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", deque[rear]);
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
