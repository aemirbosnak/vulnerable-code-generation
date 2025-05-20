//FormAI DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define a struct to represent the node of a linked list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

//Function to create and return a new node
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

//Function to add a new node to the end of a linked list
void addNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

//Function to print the contents of a linked list
void printList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL)); //Seed the random number generator
    
    Node* head = NULL; //Initialize an empty linked list
    
    //Add some random nodes to the linked list
    for (int i = 0; i < 10; i++) {
        addNode(&head, rand() % 100);
    }
    
    //Print the linked list
    printList(head);
    
    //Free the memory allocated for the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}