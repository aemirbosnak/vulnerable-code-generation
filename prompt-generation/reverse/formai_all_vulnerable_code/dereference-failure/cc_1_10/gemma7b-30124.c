//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    char input[MAX_BUFFER_SIZE];

    // Simulate a conversation
    while (1) {
        // Get the user input
        printf("Enter a message: ");
        scanf("%s", input);

        // Allocate memory for the new node
        Node* newNode = malloc(sizeof(Node));

        // Copy the user input into the new node
        strcpy(newNode->data, input);

        // Insert the new node into the linked list
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        // Print the list of messages
        for (Node* current = head; current; current = current->next) {
            printf("Message: %s\n", current->data);
        }

        // Check if the user wants to quit
        printf("Do you want to quit? (Y/N): ");
        char quit;
        scanf("%c", &quit);

        // Break out of the loop if the user wants to quit
        if (quit == 'Y' || quit == 'y') {
            break;
        }
    }

    return 0;
}