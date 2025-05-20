//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* parseCSyntax(char* buffer) {
    Node* head = NULL;
    Node* tail = NULL;

    // Eat the first character (possibly a parenthesis)
    if (*buffer != '(') {
        return NULL;
    }

    // Eat the parentheses
    buffer++;
    buffer++;

    // Iterate over the remaining characters
    while (*buffer) {
        // Check if the character is a letter
        if (isalpha(*buffer)) {
            // Create a new node
            Node* newNode = malloc(sizeof(Node));
            newNode->data = *buffer;
            newNode->next = NULL;

            // If the head is NULL, make it the head
            if (head == NULL) {
                head = newNode;
            }

            // If the tail is not NULL, link the new node to the tail
            if (tail) {
                tail->next = newNode;
            }

            // Update the tail
            tail = newNode;
        }

        // Eat the character
        buffer++;
    }

    // Return the head of the linked list
    return head;
}

int main() {
    char buffer[] = "((a)b(c))";
    Node* head = parseCSyntax(buffer);

    // Print the nodes
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}