//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct task {
    char name[30];
    int priority;
    int run_time;
} Task;

typedef struct item {
    Task task;
    int arrival_time;
    struct item* next;
} Item;

typedef struct queue {
    Item* head;
    Item* tail;
} Queue;

typedef struct scheduler {
    Queue* queues;
    int num_queues;
} Scheduler;

Task create_task(char* name, int priority, int run_time) {
    Task task;
    strcpy(task.name, name);
    task.priority = priority;
    task.run_time = run_time;
    return task;
}

void print_task(Task task) {
    printf("Task name: %s\nPriority: %d\nRun time: %d\n", task.name, task.priority, task.run_time);
}

void print_item(Item* item) {
    printf("Task name: %s\nPriority: %d\nRun time: %d\nArrival time: %d\n", item->task.name, item->task.priority, item->task.run_time, item->arrival_time);
}

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, Task task, int arrival_time) {
    Item* item = (Item*)malloc(sizeof(Item));
    item->task = task;
    item->arrival_time = arrival_time;
    item->next = NULL;
    if (queue->head == NULL) {
        queue->head = item;
    }
    else {
        queue->tail->next = item;
    }
    queue->tail = item;
}

Item* dequeue(Queue* queue) {
    Item* item = queue->head;
    if (queue->head == NULL) {
        return NULL;
    }
    else if (queue->head == queue->tail) {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else {
        queue->head = queue->head->next;
    }
    return item;
}

int is_empty(Queue* queue) {
    return queue->head == NULL;
}

Scheduler* create_scheduler(int num_queues) {
    Scheduler* scheduler = (Scheduler*)malloc(sizeof(Scheduler));
    scheduler->num_queues = num_queues;
    scheduler->queues = (Queue*)malloc(sizeof(Queue) * num_queues);
    for (int i = 0; i < num_queues; i++) {
        scheduler->queues[i] = *create_queue();
    }
    return scheduler;
}

int get_queue_index(Scheduler* scheduler, int priority) {
    return priority >= 0 && priority < scheduler->num_queues ? priority : scheduler->num_queues - 1;
}

void schedule_task(Scheduler* scheduler, Task task, int arrival_time) {
    int index = get_queue_index(scheduler, task.priority);
    enqueue(&scheduler->queues[index], task, arrival_time);
}

void run_task(Item* item, int current_time) {
    printf("Running task: %s\n", item->task.name);
    printf("Arrival time: %d\n", item->arrival_time);
    printf("Start time: %d\n", current_time);
    printf("End time: %d\n", current_time + item->task.run_time);
    printf("Total time: %d\n", item->task.run_time);
    printf("====================\n");
}

int main() {
    Scheduler* scheduler = create_scheduler(4);
    schedule_task(scheduler, create_task("Task 1", 0, 3), 0);
    schedule_task(scheduler, create_task("Task 2", 1, 5), 1);
    schedule_task(scheduler, create_task("Task 3", 2, 4), 2);
    schedule_task(scheduler, create_task("Task 4", 3, 2), 3);
    for (int i = 0; i < 4; i++) {
        while (!is_empty(&scheduler->queues[i])) {
            Item* item = dequeue(&scheduler->queues[i]);
            run_task(item, item->arrival_time);
            free(item);
        }
    }
    free(scheduler);
    return 0;
}