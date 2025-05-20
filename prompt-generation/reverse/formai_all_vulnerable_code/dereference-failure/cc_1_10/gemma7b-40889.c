//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PROCESSORS 8
#define MAX_QUEUE_SIZE 20

typedef struct process_node {
    int process_id;
    int arrival_time;
    int execution_time;
    struct process_node* next;
} process_node;

void insert_process(process_node** head, int process_id, int arrival_time, int execution_time) {
    process_node* new_node = malloc(sizeof(process_node));
    new_node->process_id = process_id;
    new_node->arrival_time = arrival_time;
    new_node->execution_time = execution_time;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void simulate_scheduler(process_node* head) {
    int current_time = 0;
    int quantum = 4;
    process_node* ready_queue = NULL;

    while (!head->next || current_time > head->arrival_time) {
        if (head->arrival_time == current_time) {
            insert_process(&ready_queue, head->process_id, head->arrival_time, head->execution_time);
        }

        if (!ready_queue) {
            current_time++;
            continue;
        }

        if (quantum > 0) {
            current_time++;
            quantum--;
        } else {
            process_node* completed_process = ready_queue;
            printf("Process %d completed.\n", completed_process->process_id);
            free(completed_process);
            ready_queue = ready_queue->next;
            quantum = 4;
        }
    }

    printf("All processes completed.\n");
}

int main() {
    process_node* head = NULL;
    insert_process(&head, 1, 0, 5);
    insert_process(&head, 2, 1, 3);
    insert_process(&head, 3, 2, 6);
    insert_process(&head, 4, 3, 2);

    simulate_scheduler(head);

    return 0;
}