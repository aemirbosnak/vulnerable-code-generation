//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void parse_syntax(char* str) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case '(':
                tail = malloc(sizeof(Node));
                tail->data = str[i];
                if (head == NULL) {
                    head = tail;
                } else {
                    tail->next = head;
                    head = tail;
                }
                break;
            case ')':
                tail = head;
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                tail->next = NULL;
                break;
            default:
                tail = malloc(sizeof(Node));
                tail->data = str[i];
                if (head == NULL) {
                    head = tail;
                } else {
                    tail->next = head;
                    head = tail;
                }
                break;
        }
    }

    printf("Parsing complete!\n");
    free(head);
}

int main() {
    parse_syntax("((a))");
    parse_syntax("(())");
    parse_syntax("()(())");

    return 0;
}