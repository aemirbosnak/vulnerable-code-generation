//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void parseExpression(Node* head) {
    Node* current = head;
    while (current) {
        switch (current->data) {
            case '+':
                parseExpression(current->next);
                current->data = '+';
                break;
            case '-':
                parseExpression(current->next);
                current->data = '-';
                break;
            case '*':
                parseExpression(current->next);
                current->data = '*';
                break;
            case '/':
                parseExpression(current->next);
                current->data = '/';
                break;
            default:
                printf("%c ", current->data);
                break;
        }
        current = current->next;
    }
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 'a';
    head->next = malloc(sizeof(Node));
    head->next->data = '+';
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 'b';
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = '*';
    head->next->next->next->next = malloc(sizeof(Node));
    head->next->next->next->next->data = 'c';

    parseExpression(head);

    return 0;
}