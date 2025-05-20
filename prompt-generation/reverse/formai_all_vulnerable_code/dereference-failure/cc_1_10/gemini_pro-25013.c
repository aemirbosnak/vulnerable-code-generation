//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stackNode {
    char data;
    struct stackNode *next;
};

typedef struct stackNode stackNode;

struct stack {
    stackNode *top;
};

typedef struct stack stack;

stack *createStack() {
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->top = NULL;
    return newStack;
}

void push(stack *s, char data) {
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        stackNode *temp = s->top;
        char data = temp->data;
        s->top = s->top->next;
        free(temp);
        return data;
    }
}

bool checkPalindrome(char *str) {
    int length = strlen(str);
    stack *s = createStack();
    for (int i = 0; i < length / 2; i++) {
        push(s, str[i]);
    }
    if (length % 2 == 1) {
        pop(s);
    }
    for (int i = length / 2; i < length; i++) {
        if (pop(s) != str[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char *str1 = "madam";
    char *str2 = "malayalam";
    char *str3 = "notPalindrome";
    printf("%s is %s a palindrome.\n", str1, (checkPalindrome(str1) ? "" : "not"));
    printf("%s is %s a palindrome.\n", str2, (checkPalindrome(str2) ? "" : "not"));
    printf("%s is %s a palindrome.\n", str3, (checkPalindrome(str3) ? "" : "not"));
    return 0;
}