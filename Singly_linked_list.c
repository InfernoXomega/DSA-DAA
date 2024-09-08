 #include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int x;
	struct node *n;
} node;

node *head = NULL;

void ins(){
	node *n = (node*)malloc(sizeof(node));
	int pos, i=0;
	if(head == NULL){
		head = n;
		
	}else{
		node* nn = head;
		printf("Enter pos: ");
		scanf("%d",&pos);
		if(pos==0){
			n->n=head;
			head=n;
		}else{
			while(nn!=NULL && i<pos-1){		
				nn=nn->n;
				i++;
			}
			
			if(nn==NULL && i<pos){
				printf("Invalid pos!\n");
				return;
			}
			
			n->n = nn->n;
			nn->n = n;
		}
		
	}
	printf("Enter val: ");
	scanf("%d",&n->x);
	
}


void del(){
	int pos, i=0;
	if(head == NULL){
		printf("Empty!\n");
		return;
	}else{
		node* nn = head;
		printf("Enter pos: ");
		scanf("%d",&pos);
		while(nn!=NULL && i<pos-1){		
			nn=nn->n;
			i++;
		}
		if(pos==0){
			head=head->n;
			return;
		}
		
		if(nn==NULL && i<pos-1){
			printf("Invalid pos!\n");
			return;
		}
		
		nn->n = nn->n->n;
		
	}	
}

void disp(){
	node* nn = head;
	if(head==NULL) {
		printf("Empty!\n");
		return;
	}
	while(nn!=NULL){
		printf("%d, ",nn->x);
		nn=nn->n;
	}
	printf("\n");
}

void rev(){
	node *cur=head, *prev=NULL, *next;
	if(head==NULL){
		printf("Empty!\n");
		return;
	}
	while(cur!=NULL){
		next=cur->n;
		cur->n=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
	
}

void sort(){
	node *cur = head;
	if(head==NULL){
		printf("Empty!\n");
		return;
	}
	while(cur != NULL){
		node* c2 = cur;
		while(c2 != NULL){
			if(cur->x > c2 ->x){
				int tmp = cur->x;
				cur->x=c2->x;
				c2->x = tmp;
			}
			c2 = c2->n;
		}
		cur=cur->n;
	}
	
}

int main(){
	int ch = 6;
	while(1){
		printf("1. Insert 2. Delete 3. Display 4. Reverse 5. Sort  6. Exit\n>_");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				ins();
				break;
			case 2:
				del();
				break;
			case 3:
				disp();
				break;
			case 4:
				rev();
				disp();
				break;
			case 5:
				sort();
				disp();
				break;
			case 6:
				printf("bye\n");
				return 0;
			default:
				printf("Invaid Input.\n");
				return 1;
		}
	}
	return 0;
}
