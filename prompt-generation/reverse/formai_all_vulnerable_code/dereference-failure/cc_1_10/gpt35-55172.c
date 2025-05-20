//FormAI DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct task {
    void (*func)(void);
    struct task *next;
} task;

task *head = NULL;
task *tail = NULL;

int schedule(task *t) {
    if (head == NULL) {
        head = t;
        tail = t;
    } else {
        tail->next = t;
        tail = t;
    }
    return 0;
}

int run() {
    while (head != NULL) {
        task *t = head;
        head = t->next;
        t->func();
        free(t);
    }
    return 0;
}

void task1(void) {
    printf("Hello from task 1!\n");
}

void task2(void) {
    printf("Hello from task 2!\n");
}

void task3(void) {
    printf("Hello from task 3!\n");
}

int main() {
    task *t1 = malloc(sizeof(task));
    t1->func = task1;
    t1->next = NULL;

    task *t2 = malloc(sizeof(task));
    t2->func = task2;
    t2->next = NULL;

    task *t3 = malloc(sizeof(task));
    t3->func = task3;
    t3->next = NULL;

    schedule(t1);
    schedule(t2);
    schedule(t3);

    run();

    return 0;
}