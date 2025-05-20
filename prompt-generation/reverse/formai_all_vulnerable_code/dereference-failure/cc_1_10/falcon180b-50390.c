//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void addNode(struct node** head, int data);
void deleteNode(struct node** head, int key);
void printList(struct node* head);

int main() {
    struct node* head = NULL;
    int option, key, data;

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void addNode(struct node** head, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while(temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if(temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(struct node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}