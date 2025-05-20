//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertNode(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

int main() {
    Node* head = NULL;
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter C Syntax: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the C syntax
    for (int i = 0; buffer[i] != '\0'; i++) {
        switch (buffer[i]) {
            case '(':
                insertNode(head, '(');
                break;
            case ')':
                insertNode(head, ')');
                break;
            case '{':
                insertNode(head, '{');
                break;
            case '}':
                insertNode(head, '}');
                break;
            case ';':
                insertNode(head, ';');
                break;
            default:
                break;
        }
    }

    // Print the parsed nodes
    Node* current = head;
    printf("Parsed nodes:\n");
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}