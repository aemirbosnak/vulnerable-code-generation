//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void (*task_handler)(void *);

struct task {
    task_handler handler;
    void *arg;
    struct task *next;
};

struct scheduler {
    struct task *head;
    struct task *tail;
};

void scheduler_init(struct scheduler *s) {
    s->head = NULL;
    s->tail = NULL;
}

void scheduler_add(struct scheduler *s, task_handler handler, void *arg) {
    struct task *t = malloc(sizeof(struct task));
    t->handler = handler;
    t->arg = arg;
    t->next = NULL;
    if (s->head == NULL) {
        s->head = t;
        s->tail = t;
    } else {
        s->tail->next = t;
        s->tail = t;
    }
}

void scheduler_run(struct scheduler *s) {
    while (s->head != NULL) {
        struct task *t = s->head;
        t->handler(t->arg);
        s->head = t->next;
        free(t);
    }
}

void task1(void *arg) {
    printf("Task 1 running\n");
}

void task2(void *arg) {
    printf("Task 2 running\n");
}

void task3(void *arg) {
    printf("Task 3 running\n");
}

int main() {
    struct scheduler s;
    scheduler_init(&s);
    scheduler_add(&s, task1, NULL);
    scheduler_add(&s, task2, NULL);
    scheduler_add(&s, task3, NULL);
    scheduler_run(&s);
    return 0;
}