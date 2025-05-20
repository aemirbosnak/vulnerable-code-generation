//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct mirror {
    char *str;
    struct mirror *next;
} mirror;

void push(mirror **stack, const char *str) {
    mirror *new = (mirror *)malloc(sizeof(mirror));
    new->str = strdup(str);
    new->next = *stack;
    *stack = new;
}

int pop(mirror **stack, char **str) {
    mirror *temp = *stack;
    *str = temp->str;
    *stack = temp->next;
    free(temp);
    return 1;
}

int is_palindrome(const char *str) {
    mirror *stack = NULL;
    int length = strlen(str);
    int i;

    for (i = 0; i < length / 2; ++i) {
        push(&stack, str + i);
        push(&stack, str + length - i - 1);
    }

    if (length % 2 == 1) {
        char c1, c2;
        if (!pop(&stack, &c1) || !pop(&stack, &c2) || c1 != c2) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    if (is_palindrome(argv[1])) {
        printf("%s is a palindrome.\n", argv[1]);
    } else {
        printf("%s is not a palindrome.\n", argv[1]);
    }

    return 0;
}