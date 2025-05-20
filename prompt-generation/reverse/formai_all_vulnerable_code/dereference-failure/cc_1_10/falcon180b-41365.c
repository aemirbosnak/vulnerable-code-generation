//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define MAX_MOVES 1000000
#define DELAY 500000

typedef struct {
    int top;
    int size;
    int *data;
} Stack;

void push(Stack *stack, int value)
{
    if (stack->top >= stack->size) {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (stack->top <= 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int is_empty(Stack *stack)
{
    return stack->top == 0;
}

int main()
{
    int num_disks, num_moves = 0;
    Stack from, to, temp;
    int i;

    srand(time(0));
    num_disks = rand() % MAX_DISKS + 1;
    printf("Number of disks: %d\n", num_disks);

    from.size = num_disks;
    from.data = malloc(num_disks * sizeof(int));
    for (i = num_disks - 1; i >= 0; i--) {
        push(&from, i);
    }

    to.size = num_disks;
    to.data = malloc(num_disks * sizeof(int));

    temp.size = num_disks;
    temp.data = malloc(num_disks * sizeof(int));

    int start_time = clock();
    while (!is_empty(&from) && num_moves < MAX_MOVES) {
        push(&temp, pop(&from));
        if (is_empty(&temp)) {
            push(&to, pop(&from));
            push(&temp, pop(&to));
        } else if (is_empty(&to)) {
            while (!is_empty(&temp)) {
                push(&to, pop(&temp));
            }
        } else if (to.data[to.top] > temp.data[temp.top]) {
            push(&temp, pop(&to));
            push(&to, pop(&from));
            push(&temp, pop(&from));
        }
        num_moves++;
    }
    int end_time = clock();

    printf("Number of moves: %d\n", num_moves);
    printf("Time taken: %ld microseconds\n", (end_time - start_time) / CLOCKS_PER_SEC);

    free(from.data);
    free(to.data);
    free(temp.data);

    return 0;
}