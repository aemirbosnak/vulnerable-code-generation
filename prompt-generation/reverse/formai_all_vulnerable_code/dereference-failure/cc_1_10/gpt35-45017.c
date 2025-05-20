//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
#define ARRAY_SIZE 5

//Structure for nodes of linked list
struct node {
    int data;
    struct node *next;
};

//Function to create a node
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to add node at the beginning of linked list
void addNodeAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

//Function to add node at the end of linked list
void addNodeAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to delete node at the beginning of linked list
void deleteNodeAtBeginning(struct node** head) {
    if(*head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

//Function to delete node at the end of linked list
void deleteNodeAtEnd(struct node** head) {
    if(*head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

//Function to display linked list
void display(struct node* head) {
    if(head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to push element in stack
void push(int stack[], int *top, int size, int element) {
    if(*top == size-1) {
        printf("\nStack is full!\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = element;
}

//Function to pop element from stack
void pop(int stack[], int *top) {
    if(*top == -1) {
        printf("\nStack is empty!\n");
        return;
    }
    *top = *top - 1;
}

//Function to display stack
void displayStack(int stack[], int top) {
    if(top == -1) {
        printf("\nStack is empty!\n");
        return;
    }
    for(int i=top; i>=0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

//Main function
int main() {
    int linkedList[MAX_SIZE] = {0};    //Array to store linked list
    int stack[MAX_SIZE] = {0};          //Array to store stack
    int top = -1;                       //Variables to store top of the stack

    printf("\n*******************************");
    printf("\n*        CYBERPUNK DS         *");
    printf("\n*******************************\n\n");

    //Adding nodes at the beginning and end of linked list
    for(int i=1; i<=ARRAY_SIZE; i++) {
        addNodeAtBeginning(&linkedList[0], i*10);
        addNodeAtEnd(&linkedList[0], i*100);
    }

    printf("Linked List: ");
    display(linkedList[0]);

    //Pushing elements in stack
    for(int i=1; i<=ARRAY_SIZE; i++) {
        push(stack, &top, MAX_SIZE, i*10);
    }

    printf("\nStack: ");
    displayStack(stack, top);

    printf("\nDeletion of first element from Linked List and Stack:\n");
    deleteNodeAtBeginning(&linkedList[0]);
    pop(stack, &top);

    printf("\nLinked List: ");
    display(linkedList[0]);

    printf("\nStack: ");
    displayStack(stack, top);

    printf("\nDeletion of last element from Linked List and Stack:\n");
    deleteNodeAtEnd(&linkedList[0]);
    pop(stack, &top);

    printf("\nLinked List: ");
    display(linkedList[0]);

    printf("\nStack: ");
    displayStack(stack, top);

    return 0;
}