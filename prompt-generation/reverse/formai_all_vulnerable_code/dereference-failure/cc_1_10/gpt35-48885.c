//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
};

struct node {
    struct process data;
    struct node* next;
};

void insert(struct process new_process, struct node** head) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_process;
    new_node->next = NULL;

    if (*head == NULL)
        *head = new_node;
    else {
        struct node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void delete(struct node** head, struct process processToDelete) {
    if (*head == NULL)
        return;
    else if ((*head)->data.pid == processToDelete.pid) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    else {
        struct node* temp = *head;
        struct node* prev = NULL;
        while (temp != NULL && temp->data.pid != processToDelete.pid) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        free(temp);
    }
}

struct process getHighestPriorityProcess(struct node* head) {
    struct process highestPriorityProcess = head->data;
    while (head != NULL) {
        if (head->data.priority < highestPriorityProcess.priority)
            highestPriorityProcess = head->data;
        head = head->next;
    }
    return highestPriorityProcess;
}

void fcfs(struct node* processes) {
    float total_waiting_time = 0, total_turnaround_time = 0;
    int total_processes = 0;
    while (processes != NULL) {
        total_waiting_time += total_turnaround_time - processes->data.arrival_time;
        total_turnaround_time += processes->data.burst_time;
        total_processes++;
        processes = processes->next;
    }
    printf("\nFCFS scheduling algorithm:\nAverage waiting time: %f\nAverage turnaround time: %f\n", total_waiting_time / total_processes, total_turnaround_time / total_processes);
}

void sjf(struct node* processes) {
    float total_waiting_time = 0, total_turnaround_time = 0;
    int total_processes = 0;
    while (processes != NULL) {
        struct process shortest_job_process = processes->data;
        struct node* current = processes->next;
        while (current != NULL) {
            if (current->data.burst_time < shortest_job_process.burst_time)
                shortest_job_process = current->data;
            current = current->next;
        }
        total_waiting_time += total_turnaround_time - shortest_job_process.arrival_time;
        total_turnaround_time += shortest_job_process.burst_time;
        total_processes++;
        delete(&processes, shortest_job_process);
    }
    printf("\nSJF scheduling algorithm:\nAverage waiting time: %f\nAverage turnaround time: %f\n", total_waiting_time / total_processes, total_turnaround_time / total_processes);
}

void priority(struct node* processes) {
    float total_waiting_time = 0, total_turnaround_time = 0;
    int total_processes = 0;
    while (processes != NULL) {
        struct process highest_priority_process = getHighestPriorityProcess(processes);
        total_waiting_time += total_turnaround_time - highest_priority_process.arrival_time;
        total_turnaround_time += highest_priority_process.burst_time;
        total_processes++;
        delete(&processes, highest_priority_process);
    }
    printf("\nPriority scheduling algorithm:\nAverage waiting time: %f\nAverage turnaround time: %f\n", total_waiting_time / total_processes, total_turnaround_time / total_processes);
}

int main() {
    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    struct node* processes = NULL;

    for (int i = 0; i < num_processes; i++) {
        struct process new_process;
        printf("\nProcess %d:\n", i + 1);
        printf("Enter process ID: ");
        scanf("%d", &new_process.pid);
        printf("Enter burst time: ");
        scanf("%d", &new_process.burst_time);
        printf("Enter arrival time: ");
        scanf("%d", &new_process.arrival_time);
        printf("Enter priority: ");
        scanf("%d", &new_process.priority);
        insert(new_process, &processes);
    }

    fcfs(processes);
    sjf(processes);
    priority(processes);

    return 0;
}