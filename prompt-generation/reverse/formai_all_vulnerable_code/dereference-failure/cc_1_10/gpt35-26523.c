//FormAI DATASET v1.0 Category: Memory management ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

/* Declare a structure to represent a node in a linked list */
struct node {
    int data;
    struct node* next;
};

/* Function to create a new node */
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to insert a node at the beginning of the list */
struct node* insertNode(struct node* head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

/* Function to print the list */
void printList(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Function to delete a node from the list */
void deleteNode(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

/* Main function */
int main() {

    struct node* head = NULL;

    /* Insert nodes into the list */
    head = insertNode(head, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    head = insertNode(head, 40);

    /* Print the initial list */
    printf("Initial List: ");
    printList(head);

    /* Delete a node from the list */
    deleteNode(&head, 20);

    /* Print the updated list */
    printf("Updated List: ");
    printList(head);

    /* Free the memory */
    struct node* temp = head;
    while(head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }

    return 0;
}