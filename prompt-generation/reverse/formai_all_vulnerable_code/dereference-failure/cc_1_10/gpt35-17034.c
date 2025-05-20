//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int priority;
    void (*task)();
} Task;

typedef struct {
    Task *heap[MAX_TASKS];
    int size;
} PriorityQueue;

PriorityQueue *createPriorityQueue();
void enqueue(PriorityQueue *q, Task *task);
Task *dequeue(PriorityQueue *q);
void swap(Task **a, Task **b);
void printQueue(PriorityQueue *q);

void task1() { printf("This is task 1!\n"); }
void task2() { printf("This is task 2!\n"); }
void task3() { printf("This is task 3!\n"); }
void task4() { printf("This is task 4!\n"); }
void task5() { printf("This is task 5!\n"); }
void task6() { printf("This is task 6!\n"); }
void task7() { printf("This is task 7!\n"); }
void task8() { printf("This is task 8!\n"); }
void task9() { printf("This is task 9!\n"); }
void task10() { printf("This is task 10!\n"); }

int main() {
    Task *t1 = (Task *)malloc(sizeof(Task));
    t1->id = 1;
    t1->priority = 3;
    t1->task = task1;

    Task *t2 = (Task *)malloc(sizeof(Task));
    t2->id = 2;
    t2->priority = 1;
    t2->task = task2;

    Task *t3 = (Task *)malloc(sizeof(Task));
    t3->id = 3;
    t3->priority = 5;
    t3->task = task3;

    Task *t4 = (Task *)malloc(sizeof(Task));
    t4->id = 4;
    t4->priority = 4;
    t4->task = task4;

    Task *t5 = (Task *)malloc(sizeof(Task));
    t5->id = 5;
    t5->priority = 2;
    t5->task = task5;

    Task *t6 = (Task *)malloc(sizeof(Task));
    t6->id = 6;
    t6->priority = 1;
    t6->task = task6;

    Task *t7 = (Task *)malloc(sizeof(Task));
    t7->id = 7;
    t7->priority = 4;
    t7->task = task7;

    Task *t8 = (Task *)malloc(sizeof(Task));
    t8->id = 8;
    t8->priority = 5;
    t8->task = task8;

    Task *t9 = (Task *)malloc(sizeof(Task));
    t9->id = 9;
    t9->priority = 2;
    t9->task = task9;

    Task *t10 = (Task *)malloc(sizeof(Task));
    t10->id = 10;
    t10->priority = 3;
    t10->task = task10;

    PriorityQueue *q = createPriorityQueue();

    enqueue(q, t1);
    enqueue(q, t2);
    enqueue(q, t3);
    enqueue(q, t4);
    enqueue(q, t5);
    enqueue(q, t6);
    enqueue(q, t7);
    enqueue(q, t8);
    enqueue(q, t9);
    enqueue(q, t10);

    printf("Tasks in queue:\n");
    printQueue(q);

    printf("Dequeueing tasks:\n");
    int i;
    for (i = 1; i <= MAX_TASKS; i++) {
        Task *t = dequeue(q);
        if (t == NULL) {
            printf("Queue is empty!\n");
            break;
        }
        printf("Running task with ID %d and priority %d!\n", t->id, t->priority);
        t->task();
        free(t);
    }

    return 0;
}

PriorityQueue *createPriorityQueue() {
    PriorityQueue *q = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    q->size = 0;
    return q;
}

void enqueue(PriorityQueue *q, Task *task) {
    if (q->size >= MAX_TASKS) {
        printf("Queue is full!\n");
        return;
    }
    q->heap[q->size++] = task;
    int i = q->size - 1;
    while (i > 0 && q->heap[i]->priority > q->heap[(i - 1) / 2]->priority) {
        swap(&q->heap[i], &q->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Task *dequeue(PriorityQueue *q) {
    if (q->size == 0) return NULL;
    Task *task = q->heap[0];
    q->heap[0] = q->heap[--q->size];
    int i = 0;
    while (i * 2 + 1 < q->size) {
        int j = i * 2 + 1;
        if (j < q->size - 1 && q->heap[j]->priority < q->heap[j + 1]->priority) j++;
        if (q->heap[i]->priority >= q->heap[j]->priority) break;
        swap(&q->heap[i], &q->heap[j]);
        i = j;
    }
    return task;
}

void swap(Task **a, Task **b) {
    Task *temp = *a;
    *a = *b;
    *b = temp;
}

void printQueue(PriorityQueue *q) {
    int i;
    for (i = 0; i < q->size; i++) {
        printf("[%d] ID: %d, Priority: %d\n", i, q->heap[i]->id, q->heap[i]->priority);
    }
}