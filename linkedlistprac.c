#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void traverse(struct node* head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

struct node* insertbegin(struct node** head,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}

struct node* insertend(struct node** head,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        return *head;
    }
    struct node* current=*head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newnode;
    return *head;
}

struct node* insertind(struct node** head,int data,int index){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        return *head;
    }
    int count=0;
    struct node* cur=*head;
    while(cur!=NULL){
        cur=cur->next;
        count++;
    }
    if(index<0 || index>count){
        printf("Index is Out of Range!!\n");
        return *head;
    }
    else if(index==0){
        newnode->next=*head;
        *head=newnode;
        return *head;
    }
    else{
        struct node* current=*head;
        struct node* prev=NULL;
        for(int i=0;i<index;i++){
            prev=current;
            current=current->next;
        }
        prev->next=newnode;
        newnode->next=current;
        return *head;
    }
}

struct node* deletebegin(struct node** head){
    if(*head==NULL){
        printf("List is already Empty!!\n");
        return *head;
    }
    else if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return *head;
    }
    struct node* temp=*head;
    *head=(*head)->next;
    free(temp);
    return *head;
}

struct node* deleteend(struct node** head){
    if(*head==NULL){
        printf("List is already Empty!!\n");
        return *head;
    }
    else if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return *head;
    }
    struct node* current=*head;
    struct node* prev=NULL;
    while(current->next!=NULL){
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    free(current);
    return *head;
}

struct node* deleteind(struct node** head,int ind){
    int count=0;
    struct node* cur=*head;
    if(*head==NULL){
        printf("List is already empty!!\n");
        return *head;
    }
    while(cur!=NULL){
        count++;
        cur=cur->next;
    }
    if(ind<0 || ind>count){
        printf("Index is Out of Range!!\n");
        return *head;
    }
    if(ind==0 && (*head)->next==NULL){
        free(*head);
        *head=NULL;
        return *head;
    }
    else if(ind==0 && (*head)->next!=NULL){
        struct node* temp=*head;
        *head=(*head)->next;
        free(temp);
        return *head;
    }
    else{
        struct node* current=*head;
        struct node* prev=NULL;
        for(int i=0;i<ind;i++){
            prev=current;
            current=current->next;
        }
        if(current==NULL){
            printf("Cannot Delete 'NULL' element!!\n");
            return *head;
        }
        prev->next=NULL;
        free(current);
    }
}

int main(){
    struct node* head=NULL;
    int n;
    printf("Enter your Choice:\n1)Traverse\n2)Insert at Begin\n3)Insert at End\n4)Insert at Index\n5)Delete at Begin\n6)Delete at End\n7)Delete at Index\n8)Exit: ");
    scanf("%d",&n);
    while(n!=8){
        if(n==1){
            traverse(head);
        }
        else if(n==2 || n==3 || n==4){
            int ele;
            printf("Enter the Value to Insert: ");
            scanf("%d",&ele);
            if(n==2){
                insertbegin(&head,ele);
            }
            else if(n==3){
                insertend(&head,ele);
            }
            else{
                int ind;
                printf("Enter the Index to Insert at: ");
                scanf("%d",&ind);
                insertind(&head,ele,ind);
            }
        }
        else if(n==5){
            deletebegin(&head);
        }
        else if(n==6){
            deleteend(&head);
        }
        else if(n==7){
            int ind;
            printf("Enter the Index to Delete:");
            scanf("%d",&ind);
            deleteind(&head,ind);
        }
        printf("Enter your Choice:\n1)Traverse\n2)Insert at Begin\n3)Insert at End\n4)Insert at Index\n5)Delete at Begin\n6)Delete at End\n7)Delete at Index\n8)Exit: ");
        scanf("%d",&n);
    }
    return 0;
}