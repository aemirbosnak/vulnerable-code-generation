//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
};

struct Node {
    struct Process process;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};

void enqueue(struct Queue *queue, struct Process process) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->process = process;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

struct Process dequeue(struct Queue *queue) {
    struct Process process = queue->head->process;
    struct Node *old_head = queue->head;

    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(old_head);

    return process;
}

int main() {
    struct Queue queue;
    queue.head = NULL;
    queue.tail = NULL;

    struct Process processes[] = {
        {1, 0, 5, 5, 1},
        {2, 1, 4, 4, 2},
        {3, 2, 3, 3, 3},
        {4, 3, 2, 2, 4},
        {5, 4, 1, 1, 5},
    };

    for (int i = 0; i < sizeof(processes) / sizeof(processes[0]); i++) {
        enqueue(&queue, processes[i]);
    }

    while (queue.head != NULL) {
        struct Process process = dequeue(&queue);
        printf("Running process %d\n", process.pid);
        process.remaining_time--;
        if (process.remaining_time == 0) {
            printf("Process %d finished\n", process.pid);
        } else {
            enqueue(&queue, process);
        }
    }

    return 0;
}