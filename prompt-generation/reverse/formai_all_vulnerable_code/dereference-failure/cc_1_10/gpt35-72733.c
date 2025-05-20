//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complete
#include<stdio.h>
#include<stdlib.h>

//definition of Node structure
struct Node {
    int data;
    struct Node* next;
};

//Function to add nodes to the Linked List
void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

//Function to remove the specified node from the linked list
void removeNode(struct Node **head, struct Node *toRemove) { 
    if (*head == NULL) 
        return;

    if (toRemove == *head) { 
        *head = toRemove->next; 
        free(toRemove); 
        return; 
    } 

    struct Node *temp = *head; 
    while (temp->next != NULL && temp->next != toRemove) 
        temp = temp->next; 

    if (temp->next == NULL) 
        return; 

    temp->next = temp->next->next; 
    free(toRemove); 
} 

//Function to print elements of the Linked List
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);

    printf("Initial Linked List:\n");
    printList(head);

    printf("Removing 4 from Linked List:\n");
    removeNode(&head, head->next);
    printList(head);

    printf("Removing 6 from Linked List:\n");
    removeNode(&head, head->next->next);
    printList(head);

    printf("Removing 3 from Linked List:\n");
    removeNode(&head, head);
    printList(head);
    
    return 0;
}