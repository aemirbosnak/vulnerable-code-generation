//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct {
    int data;
    int priority;
    struct task *next;
} task;

task *stack[STACK_SIZE];
int top = -1;

void push(task *task) {
    if (top >= STACK_SIZE - 1) {
        printf("Stack is full\n");
        exit(0);
    }
    stack[++top] = task;
}

task *pop() {
    task *task = stack[top--];
    return task;
}

int is_empty() {
    return (top == -1);
}

void display() {
    if (is_empty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while (top >= 0) {
        printf("%d ", stack[top--]->data);
    }
    printf("\n");
}

void execute_task(task *task) {
    printf("Executing task with data %d\n", task->data);
    printf("Priority of task is %d\n", task->priority);
}

int main() {
    task *task1 = (task *)malloc(sizeof(task));
    task *task2 = (task *)malloc(sizeof(task));
    task *task3 = (task *)malloc(sizeof(task));

    task1->data = 10;
    task1->priority = 3;
    task1->next = NULL;

    task2->data = 20;
    task2->priority = 1;
    task2->next = NULL;

    task3->data = 30;
    task3->priority = 2;
    task3->next = NULL;

    push(task1);
    push(task2);
    push(task3);

    display();

    execute_task(pop());
    execute_task(pop());
    execute_task(pop());

    return 0;
}