//FormAI DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct task_s {
    char name[20];
    int priority;
    time_t start_time;
    int duration;
} task_t;

typedef struct node_s {
    task_t *task;
    struct node_s *next;
} node_t;

typedef struct schedule_s {
    node_t *head;
    int count;
} schedule_t;

node_t *create_node(task_t *task) {
    node_t *node = malloc(sizeof(node_t));
    node->task = task;
    node->next = NULL;
    return node;
}

void add_task(schedule_t *schedule, task_t *task) {
    node_t *node = create_node(task);
    if (schedule->head == NULL) {
        schedule->head = node;
    } else {
        node_t *current = schedule->head;
        if (task->priority < current->task->priority) {
            node->next = current;
            schedule->head = node;
        } else {
            while (current->next != NULL
                   && task->priority >= current->next->task->priority) {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }
    schedule->count++;
}

void print_schedule(schedule_t *schedule) {
    printf("\n------ Task Schedule ------\n");
    node_t *current = schedule->head;
    while (current != NULL) {
        printf("Name: %s\n", current->task->name);
        printf("Priority: %d\n", current->task->priority);
        printf("Start Time: %ld\n", current->task->start_time);
        printf("Duration: %d\n\n", current->task->duration);
        current = current->next;
    }
}

void delete_schedule(schedule_t *schedule) {
    node_t *current = schedule->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->task);
        free(current);
        current = next;
    }
    free(schedule);
}

int main() {
    srand(time(NULL));
    schedule_t *schedule = malloc(sizeof(schedule_t));
    schedule->head = NULL;
    schedule->count = 0;

    for (int i = 0; i < 5; i++) {
        task_t *task = malloc(sizeof(task_t));
        sprintf(task->name, "Task %d", i+1);
        task->priority = rand()%10;
        task->start_time = time(NULL) + rand()%60*60;
        task->duration = rand()%60;
        add_task(schedule, task);
    }

    print_schedule(schedule);
    delete_schedule(schedule);

    return 0;
}