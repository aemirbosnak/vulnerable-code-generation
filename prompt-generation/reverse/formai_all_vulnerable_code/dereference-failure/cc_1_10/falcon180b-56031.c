//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

void push(char *stack, int *top, char element) {
    if (*top == MAX - 1) {
        printf("\nStack Overflow");
        exit(0);
    }
    else
        *(stack + (*top)++) = element;
}

char pop(char stack[], int *top) {
    char element;
    if (*top == -1) {
        printf("\nStack Underflow");
        exit(0);
    }
    else
        element = *(stack + (*top)--);
    return element;
}

void display(char stack[], int top) {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%c", stack[i]);
    }
}

int is_empty(int top) {
    if (top == -1)
        return 1;
    else
        return 0;
}

int main() {
    int choice, top1 = -1, top2 = -1;
    char stack1[MAX], stack2[MAX], element;
    while (1) {
        printf("\nEnter 1 for Player 1 and 2 for Player 2: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nEnter the element to be pushed: ");
            scanf("%c", &element);
            push(stack1, &top1, element);
            printf("\n%c pushed to stack 1", element);
            if (is_empty(top1)) {
                printf("\nPlayer 2 wins!");
                break;
            }
        }
        else if (choice == 2) {
            printf("\nEnter the element to be pushed: ");
            scanf("%c", &element);
            push(stack2, &top2, element);
            printf("\n%c pushed to stack 2", element);
            if (is_empty(top1)) {
                printf("\nPlayer 2 wins!");
                break;
            }
        }
        else {
            printf("\nInvalid choice!");
        }
    }
    return 0;
}