//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *top;
} stack;

void push(stack *s, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    int data = s->top->data;
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

int peek(stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    return s->top->data;
}

void print_stack(stack *s) {
    node *current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    stack *rods[3];
    for (int i = 0; i < 3; i++) {
        rods[i] = malloc(sizeof(stack));
        rods[i]->top = NULL;
    }

    for (int i = n; i >= 1; i--) {
        push(rods[0], i);
    }

    int num_moves = 0;
    while (rods[2]->top == NULL) {
        int min_rod = -1;
        int min_data = -1;
        for (int i = 0; i < 3; i++) {
            if (rods[i]->top != NULL && (min_data == -1 || rods[i]->top->data < min_data)) {
                min_rod = i;
                min_data = rods[i]->top->data;
            }
        }

        int rod1 = (min_rod + 1) % 3;
        int rod2 = (min_rod + 2) % 3;

        while (rods[rod1]->top != NULL && rods[rod2]->top != NULL && rods[rod1]->top->data > rods[rod2]->top->data) {
            int temp = pop(rods[rod1]);
            push(rods[rod2], temp);
            num_moves++;
        }

        if (rods[rod1]->top != NULL) {
            int temp = pop(rods[rod1]);
            push(rods[rod2], temp);
            num_moves++;
        } else if (rods[rod2]->top != NULL) {
            int temp = pop(rods[rod2]);
            push(rods[rod1], temp);
            num_moves++;
        }
    }

    printf("The number of moves required is: %d\n", num_moves);

    return 0;
}