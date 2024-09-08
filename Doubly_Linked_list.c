#include <stdio.h>
#include <stdlib.h>

struct Node
{
        int data;
        struct Node *prev;
        struct Node *next;
};

struct Node *createNode(int data)
{
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
        struct Node *newNode = createNode(data);
        if (*head == NULL)
        {
                *head = newNode;
                return;
        }
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
        struct Node *newNode = createNode(data);
        if (*head == NULL)
        {
                *head = newNode;
                return;
        }
        struct Node *current = *head;
        while (current->next != NULL)
        {
                current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
}

void deleteNode(struct Node **head, int data)
{
        if (*head == NULL)
        {
                printf("List is empty.\n");
                return;
        }
        struct Node *current = *head;
        while (current != NULL)
        {
                if (current->data == data)
                {
                        if (current->prev != NULL)
                                current->prev->next = current->next;
                        if (current->next != NULL)
                                current->next->prev = current->prev;
                        if (*head == current)
                                *head = current->next;
                        free(current);
                        return;
                }
                current = current->next;
        }
        printf("Element not found in the list.\n");
}

void display(struct Node *head)
{
        struct Node *current = head;
        while (current != NULL)
        {
                printf("%d ", current->data);
                current = current->next;
        }
        printf("\n");
}

void reverse(struct Node **head)
{
        struct Node *temp = NULL;
        struct Node *current = *head;
        while (current != NULL)
        {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
        }
        if (temp != NULL)
                *head = temp->prev;
}

int main()
{
        struct Node *head = NULL;
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Display the list\n");
        printf("5. Reverse the list\n");
        printf("6. Exit\n");
        int choice;
        while (1)
        {
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                {
                        int data;
                        printf("Enter the element to insert: ");
                        scanf("%d", &data);
                        insertAtBeginning(&head, data);
                        break;
                }
                case 2:
                {
                        int data;
                        printf("Enter the element to insert: ");
                        scanf("%d", &data);
                        insertAtEnd(&head, data);
                        break;
                }
                case 3:
                {
                        int data;
                        printf("Enter the element to delete: ");
                        scanf("%d", &data);
                        deleteNode(&head, data);
                        break;
                }
                case 4:
                        printf("List: ");
                        display(head);
                        break;
                case 5:
                        reverse(&head);
                        printf("Reversed List: ");
                        display(head);
                        break;
                case 6:
                        exit(0);
                default:
                        printf("Invalid choice.\n");
                }
        }

        return 0;
}