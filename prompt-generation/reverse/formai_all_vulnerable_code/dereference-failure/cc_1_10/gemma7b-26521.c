//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* parse_c_syntax(char* source) {
    Node* head = NULL;
    Node* current = NULL;
    int i = 0;

    while (source[i] != '\0') {
        switch (source[i]) {
            case '(':
                current = malloc(sizeof(Node));
                current->data = '(';
                current->next = NULL;

                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                break;
            case ')':
                current = head;
                while (current->data != '(') {
                    current = current->next;
                }
                free(current);
                break;
            default:
                current = malloc(sizeof(Node));
                current->data = source[i];
                current->next = NULL;

                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                break;
        }

        i++;
    }

    return head;
}

int main() {
    char* source = "((())())";
    Node* head = parse_c_syntax(source);

    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }

    return 0;
}