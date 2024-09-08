#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*start;

void listghoro() {
    struct node *temp;
    
    if (start==NULL) {
        printf("chop sala");
        return;}

    temp=start;
    while(temp!=start){
        printf("data=%d\n", temp->data);
        temp=temp->next;
    }
}

void listbanao(int n) {

    struct node *newnode;
    struct node *temp;
    int data,i;
    
    start = (struct node *)malloc(sizeof(struct node));

    if (start==NULL) {
        printf("chop sala");
        exit(0);}

    
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    start->data = data; 
    start->next = NULL;

    temp=start;

    for(i=2;i<=n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

    newnode->data = data; 
    newnode->next = NULL;

    temp->next = newnode; 
    temp = temp->next;    
    }
}

void insert(){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    int data,i,pos;

    printf("enter data of new node ");
    scanf("%d",&data);
    
    printf("enter position of new node ");
    scanf("%d",&pos);
    
    struct node *temp= start;

    for (i=2;i<pos;i++){
        if (temp->next!=NULL){
            temp=temp->next;
            }
    }

    newnode->next= temp->next;
    temp->next=newnode;

    printf("%d",&data);
}

int main() {
    int n;
    printf("enter nud ");
    scanf("%d", &n);

    listbanao(n);

    listghoro();

    insert();

    return 0;
}