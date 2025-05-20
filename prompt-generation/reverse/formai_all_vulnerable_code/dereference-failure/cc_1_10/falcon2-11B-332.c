//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* array;
    int top;
} Stack;

void initStack(Stack* s, int size) {
    s->top = -1;
    s->array = (int*) malloc(size * sizeof(int));
}

void push(Stack* s, int value) {
    if (s->top == s->array - 1) {
        printf("Sorry, stack overflow!\n");
        return;
    }
    s->array[++s->top] = value;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Sorry, stack underflow!\n");
        return -1;
    }
    int value = s->array[s->top];
    s->array[s->top] = 0;
    s->top--;
    return value;
}

void enqueue(Stack* s1, Stack* s2) {
    while (s1->top > -1) {
        push(s2, pop(s1));
    }
}

int dequeue(Stack* s1, Stack* s2) {
    while (s2->top > -1) {
        push(s1, pop(s2));
    }
    return pop(s1);
}

int main() {
    Stack s1, s2;
    initStack(&s1, 100);
    initStack(&s2, 100);

    enqueue(&s1, &s2);
    printf("Queue 1: ");
    while (s1.top > -1) {
        printf("%d ", s1.array[s1.top]);
        s1.top--;
    }
    printf("\n");

    dequeue(&s1, &s2);
    printf("Queue 2: ");
    while (s2.top > -1) {
        printf("%d ", s2.array[s2.top]);
        s2.top--;
    }
    printf("\n");

    return 0;
}