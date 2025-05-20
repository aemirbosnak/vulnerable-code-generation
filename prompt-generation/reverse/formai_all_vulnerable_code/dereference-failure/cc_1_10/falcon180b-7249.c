//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define STACK_SIZE 100
#define NUM_DISKS 4

typedef struct {
    int top;
    int *stack;
} Stack;

void push(Stack *s, int x) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    s->top++;
    s->stack[s->top] = x;
}

int pop(Stack *s) {
    int x;
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(0);
    }
    x = s->stack[s->top];
    s->top--;
    return x;
}

void display(Stack s) {
    int i;
    for (i = s.top; i >= 0; i--)
        printf("%d ", s.stack[i]);
    printf("\n");
}

void move_tower(int n, char from_rod, char to_rod, char aux_rod) {
    Stack s;
    s.top = -1;
    push(&s, n);
    while (s.top!= 0) {
        printf("Move disk %d from rod %c to rod %c\n", pop(&s), from_rod, to_rod);
        push(&s, n);
        printf("Move disk %d from rod %c to rod %c\n", pop(&s), to_rod, aux_rod);
        push(&s, n);
        printf("Move disk %d from rod %c to rod %c\n", pop(&s), aux_rod, from_rod);
    }
}

int main() {
    int i, n, choice;
    printf("Enter the number of disks:\n");
    scanf("%d", &n);
    printf("Enter 1 to solve the Tower of Hanoi problem\n");
    printf("Enter 2 to randomly generate a solution\n");
    scanf("%d", &choice);
    srand(time(0));
    if (choice == 1) {
        printf("Solving Tower of Hanoi problem with %d disks...\n", n);
        move_tower(n, 'A', 'C', 'B');
    } else if (choice == 2) {
        printf("Generating random solution for Tower of Hanoi problem with %d disks...\n", n);
        int sol[n];
        for (i = n - 1; i >= 0; i--) {
            sol[i] = rand() % 3;
        }
        printf("Random solution: ");
        for (i = n - 1; i >= 0; i--) {
            printf("%d ", sol[i]);
        }
        printf("\n");
    }
    return 0;
}