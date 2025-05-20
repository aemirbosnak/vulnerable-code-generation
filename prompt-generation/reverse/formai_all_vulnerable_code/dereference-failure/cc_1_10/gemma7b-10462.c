//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_PARENS 10

typedef struct Parenthesis {
    char type;
    int level;
    struct Parenthesis* next;
} Parenthesis;

Parenthesis* parse_paren(char* str) {
    Parenthesis* head = NULL;
    Parenthesis* tail = NULL;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        Parenthesis* new_paren = malloc(sizeof(Parenthesis));
        new_paren->type = str[i];
        new_paren->level = -1;
        new_paren->next = NULL;

        if (head == NULL) {
            head = new_paren;
            tail = new_paren;
        } else {
            tail->next = new_paren;
            tail = new_paren;
        }
    }

    return head;
}

int validate_paren(Parenthesis* head) {
    int balance = 0;

    for (Parenthesis* current = head; current; current = current->next) {
        switch (current->type) {
            case '(':
                balance++;
                break;
            case ')':
                balance--;
                break;
            default:
                return 0;
        }

        if (balance < 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char* str = "(())";
    Parenthesis* head = parse_paren(str);

    if (validate_paren(head)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}