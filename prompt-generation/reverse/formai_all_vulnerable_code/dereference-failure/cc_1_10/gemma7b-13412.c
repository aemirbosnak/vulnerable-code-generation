//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
    int process_id;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

void create_process(process** head) {
    *head = (process*)malloc(sizeof(process));
    (*head)->process_id = 0;
    strcpy((*head)->name, "Process A");
    (*head)->burst_time = 5;
    (*head)->remaining_time = 5;
    (*head)->next = NULL;
}

void add_process(process** head, process* new_process) {
    new_process->next = (*head);
    *head = new_process;
}

void round_robin(process** head) {
    process* current_process = *head;
    while (current_process) {
        printf("Process ID: %d, Name: %s, Remaining Time: %d\n", current_process->process_id, current_process->name, current_process->remaining_time);
        current_process->remaining_time--;
        if (current_process->remaining_time == 0) {
            printf("Process completed: %s\n", current_process->name);
            current_process = current_process->next;
        }
    }
}

int main() {
    process* head = NULL;
    create_process(&head);
    add_process(&head, (process*)malloc(sizeof(process)));
    add_process(&head, (process*)malloc(sizeof(process)));
    add_process(&head, (process*)malloc(sizeof(process)));

    round_robin(&head);

    return 0;
}