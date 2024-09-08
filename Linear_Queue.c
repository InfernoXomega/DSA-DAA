#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front=-1,rear=-1;

void enqueue(int value){
	if(rear==MAX_SIZE-1){
		printf("Queue is full. Can't enqueue\n");
		return;
	}
	if(front==-1)
		front=0;
	rear++;
	queue[rear]=value;
	printf("Enqueued %d\n",value);
}
		
void dequeue(){
	if(front==-1){
		printf("Queue is Empty,Can't dequeue\n");
		return;
	}
		printf("Dequeued %d\n",queue[front]);
		if(front == rear)
			front = rear =-1;
		else
			front++;
}
void display(){
	if(front==-1){
		printf("Queue is Empty.\n");
		return;
	}	
	printf("Queue: ");
	for(int i = front; i<= rear; i++){
		printf("%d ", queue[i]);
	}
	printf("\n");
}

int main(){
	int choice, value;
	
	while(1){
		printf("\nLinear Queue Implementation using Array\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				printf("Enter value to enqueue: ");
				scanf("%d",&value);
				enqueue(value);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid choice. Please select again.\n");
		}
	}
	
	return 0;
}										
							
