#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int arr[MAX];
int r = -1;
int f = -1;

int isfull(){	return ((r+1)%MAX == f);}

int isempty(){ return (f == -1 && r == -1);}

void enq(int data){
	if (isfull()){
		printf("Queue is full\n");
		return;
	}else if (isempty()){
		f=r=0;
	}else r = (r+1)%MAX;
	arr[r] = data;
	printf("%d is enqueued\n",data);
}

void deq(){
	if (isempty()){
		printf("Queue is empty");
		return;
	}else if(f==r){
		printf("%d is dequeued\n",arr[f]);
		f=r=-1;
	}else{
		printf("%d is dequeued\n",arr[f]);
		f = (f+1)%MAX;
	}
		
}

void display(){
	int i;
	if (isempty()){
		printf("Queue is empty");
		return;
	}
	printf("Queue elements are: ");
	for(i = f;i!=r;i=(i+1)%MAX) printf("%d ",arr[i]);
	printf("%d\n",arr[i]);
}
	

int main(){
	printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

    int choice, x;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            	printf("Enter element to be enqueued: ");
            	scanf("%d",&x);
                enq(x);
                break;
            case 2:
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }	
    	return 0;
}

