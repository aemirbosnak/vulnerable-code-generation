//FormAI DATASET v1.0 Category: Scientific ; Style: portable
#include<stdio.h>
#include<stdlib.h>

/* Define struct for stack */
typedef struct Stack {
    int top;
    unsigned max_size;
    int* s_array;
}Stack;

/* Create stack function */
Stack* create_stack(unsigned max_size) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s -> top = -1;
    s -> max_size = max_size;
    s -> s_array = (int*) malloc(s -> max_size * sizeof(int));
    return s;
}

/* Check if stack is full */
int isFull(Stack* s) {
    return s -> top == s -> max_size - 1;
}

/* Check if stack is empty */
int isEmpty(Stack* s) {
    return s -> top == -1;
}

/* Push an element on the stack */
void push(Stack* s, int element) {
    if(isFull(s)) {
        printf("Error: Stack overflow\n");
        return;
    }
    s -> s_array[++(s -> top)] = element;
    printf("%d has been pushed successfully\n", element);
}

/* Pop an element from the stack */
int pop(Stack* s) {
    if(isEmpty(s)) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    return s -> s_array[(s -> top)--];
}

/* Display elements of the stack */
void display(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements of the stack are:\n");
    for(int i = s -> top; i >= 0; i--) {
        printf("%d\n", s -> s_array[i]);
    }
}

/* Main function */
int main() {
    Stack* s = create_stack(5);

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);

    printf("\n");
    display(s);

    printf("\n");
    printf("%d has been popped from stack\n", pop(s));
    printf("%d has been popped from stack\n", pop(s));

    printf("\n");
    display(s);

    return 0;
}