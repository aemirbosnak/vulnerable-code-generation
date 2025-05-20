//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* parse_c_syntax(char* str) {
    Node* head = NULL;
    Node* tail = NULL;

    // Iterate over the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the character is a letter
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Create a new node
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = str[i];
            newNode->next = NULL;

            // If the head is NULL, make it the head
            if (head == NULL) {
                head = newNode;
            }

            // If the tail is not NULL, update the tail
            if (tail) {
                tail->next = newNode;
            }

            // Update the tail
            tail = newNode;
        }
    }

    return head;
}

int main() {
    char str[] = "abc123";
    Node* head = parse_c_syntax(str);

    // Print the nodes
    for (Node* node = head; node; node = node->next) {
        printf("%c ", node->data);
    }

    return 0;
}