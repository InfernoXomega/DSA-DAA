#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(int val)
{
    
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop()
{
    
    struct Node *temp;
    if(head == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Poped element = %d\n", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}


void display()
{
    struct Node *temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
   while(1){
    int data,choice;
    printf("1. push 2. pop 3. display 4. exit \n");
    scanf("%d",choice);
    switch(choice){
        case 1:
        printf("input data to push");
        scanf("%d",data);
        push(data);
        break;
        case 2:
        printf("input data to pop");
        scanf("%d",data);
        pop(data);
        break;
        case 3:
        return 0;
        default:
        printf("invalid");
        return 1;
    }
   }
    return 0;
}





// int len,data;
// printf("\n Enter length:");
// scanf("%d",&len);
// for(int i=0;i<len;i++)
// {
// printf("\n Enter data:");
// scanf("%d",&data);
// push(data);
// }



//  printf("Linked List\n");
//     display();
//     pop();
//     printf("After the pop, the new linked list\n");
//     display();
//     pop();
//     printf("After the pop, the new linked list\n");
//     display();