//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    char *name;
    int priority;
    time_t duration;
    time_t start_time;
} Task;

typedef struct node {
    Task *task;
    struct node *next;
} Node;

typedef struct schedule {
    Node *head;
    int size;
} Schedule;

void add_task(Schedule *s, Task *t) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->task = t;
    new_node->next = NULL;

    if (s->head == NULL) {
        s->head = new_node;
    } else {
        Node *curr_node = s->head;
        Node *prev_node = NULL;

        while (curr_node != NULL && curr_node->task->priority <= t->priority) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        if (prev_node == NULL) {
            new_node->next = s->head;
            s->head = new_node;
        } else {
            new_node->next = curr_node;
            prev_node->next = new_node;
        }
    }

    s->size++;
}

Task* get_next_task(Schedule *s) {
    if (s == NULL || s->head == NULL) {
        return NULL;
    }

    Task *next_task = s->head->task;
    s->head = s->head->next;
    s->size--;

    return next_task;
}

void print_schedule(Schedule *s) {
    if (s == NULL || s->head == NULL) {
        printf("No tasks scheduled.\n");
        return;
    }

    Node *curr_node = s->head;
    printf("Scheduled tasks:\n");

    while (curr_node != NULL) {
        printf("Task: %s, Priority: %d, Duration: %ld, Start Time: %s",
               curr_node->task->name,
               curr_node->task->priority,
               curr_node->task->duration,
               ctime(&curr_node->task->start_time));
        curr_node = curr_node->next;
    }
}

int main() {
    time_t curr_time = time(NULL);

    Task *task1 = (Task*) malloc(sizeof(Task));
    task1->name = "Task 1";
    task1->priority = 1;
    task1->duration = 10;
    task1->start_time = curr_time;

    Task *task2 = (Task*) malloc(sizeof(Task));
    task2->name = "Task 2";
    task2->priority = 2;
    task2->duration = 5;
    task2->start_time = curr_time + 15;

    Task *task3 = (Task*) malloc(sizeof(Task));
    task3->name = "Task 3";
    task3->priority = 3;
    task3->duration = 3;
    task3->start_time = curr_time + 25;

    Schedule *schedule = (Schedule*) malloc(sizeof(Schedule));
    schedule->head = NULL;
    schedule->size = 0;

    add_task(schedule, task1);
    add_task(schedule, task2);
    add_task(schedule, task3);

    print_schedule(schedule);

    while (schedule->size > 0) {
        Task *next_task = get_next_task(schedule);
        printf("Executing task: %s\n", next_task->name);
        curr_time += next_task->duration;
        free(next_task);
    }

    return 0;
}