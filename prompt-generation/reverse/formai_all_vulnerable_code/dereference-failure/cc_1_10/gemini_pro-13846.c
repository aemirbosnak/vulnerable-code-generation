//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char character;
    struct node *next;
} node;

typedef struct stack {
    struct node *top;
} stack;

void push(stack *s, char c) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->character = c;
    new_node->next = s->top;
    s->top = new_node;
}

char pop(stack *s) {
    if (s->top == NULL) {
        return '\0';
    }
    struct node *temp = s->top;
    s->top = s->top->next;
    char c = temp->character;
    free(temp);
    return c;
}

int is_palindrome(char *str) {
    stack s;
    s.top = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != pop(&s)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}