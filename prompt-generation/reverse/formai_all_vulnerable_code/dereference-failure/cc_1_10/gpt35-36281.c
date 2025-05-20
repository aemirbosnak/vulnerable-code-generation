//FormAI DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 10

// Structure to hold the information about the numbers
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Function to generate a random number
int getRandomNumber() {
    return rand() % 100 + 1;
}

// Function to create a new node
Node* createNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
Node* insertAtEnd(Node *head, int value) {
    // Create a new node
    Node *newNode = createNode(value);

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse to the end of the list
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;

    return head;
}

// Function to print the list
void printList(Node *head) {
    printf("List: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an empty list
    Node *list = NULL;

    // Insert random numbers into the list
    for (int i = 0; i < MAX_NUMBERS; i++) {
        int randomNumber = getRandomNumber();
        list = insertAtEnd(list, randomNumber);
        printList(list);
    }

    return 0;
}