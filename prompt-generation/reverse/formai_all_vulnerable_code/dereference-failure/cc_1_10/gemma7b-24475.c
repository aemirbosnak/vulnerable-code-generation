//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void parseCSyntax(char* source) {
    Node* head = NULL;
    char* current = source;
    while (*current) {
        if (*current == '(') {
            head = createNode('(');
            current++;
        } else if (*current == ')') {
            current++;
            Node* previous = head;
            while (previous->next) {
                previous = previous->next;
            }
            previous->next = createNode(')');
        } else {
            head = createNode(*current);
            current++;
        }
    }

    // Print the parsed nodes
    Node* node = head;
    while (node) {
        printf("%c ", node->data);
        node = node->next;
    }

    free(head);
}

int main() {
    parseCSyntax("((a)b)c)");
    return 0;
}