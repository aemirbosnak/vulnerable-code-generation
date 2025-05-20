//FormAI DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation error!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert(Node** head, int data){
    Node* newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node* current = *head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

void delete(Node** head, int data){
    if(*head == NULL){
        printf("List is empty!\n");
        return;
    }

    Node* current = *head;
    Node* previous = NULL;

    while(current != NULL){
        if(current->data == data){
            if(current == *head){
                *head = current->next;
            }
            else{
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Data not found!\n");
}

void display(Node* head){
    printf("List: ");
    Node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    display(head);

    delete(&head, 2);

    display(head);

    delete(&head, 4);

    return 0;
}