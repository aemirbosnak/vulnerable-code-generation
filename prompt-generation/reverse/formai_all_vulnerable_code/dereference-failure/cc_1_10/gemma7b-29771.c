//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YY 42
#define XX 13

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* newNode(char data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void parseSyntax(char* str) {
    Node* head = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case '(':
                head = newNode('(');
                break;
            case ')':
                head = newNode(')');
                break;
            case '+':
                head = newNode('+');
                break;
            case '-':
                head = newNode('-');
                break;
            case '*':
                head = newNode('*');
                break;
            case '/':
                head = newNode('/');
                break;
            default:
                head = newNode(str[i]);
                break;
        }
        if (head) {
            head->next = newNode('\0');
        }
    }
    free(head);
}

int main() {
    parseSyntax("((+-*/)***");
    return 0;
}