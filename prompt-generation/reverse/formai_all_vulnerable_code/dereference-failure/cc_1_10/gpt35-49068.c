//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int process_id;
    int cpu_burst_time;
    int arrival_time;
    int priority;
} Process;

typedef struct Node
{
    Process process;
    struct Node *next;
} Node;

void insert(Node **head, Process process)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->process = process;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
}

void delete(Node **head, Process process)
{
    Node *temp, *prev;
    temp = *head;
    if (temp != NULL && temp->process.process_id == process.process_id)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->process.process_id != process.process_id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

Process get_min_priority_process(Node **head)
{
    Node *current = *head;
    Process min_priority_process = current->process;

    while (current != NULL)
    {
        if (current->process.priority < min_priority_process.priority)
        {
            min_priority_process = current->process;
        }

        current = current->next;
    }

    return min_priority_process;
}

void print_process(Process process)
{
    printf("Process ID: %d\n", process.process_id);
    printf("CPU Burst Time: %d\n", process.cpu_burst_time);
    printf("Arrival Time: %d\n", process.arrival_time);
    printf("Priority: %d\n\n", process.priority);
}

void print_processes(Node **head)
{
    Node *current = *head;

    while (current != NULL)
    {
        print_process(current->process);
        current = current->next;
    }
}

void fcfs(Node **head)
{
    printf("First Come First Serve (FCFS) Scheduling Algorithm:\n\n");
    Node *current = *head;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int completion_time = current->process.cpu_burst_time + current->process.arrival_time;

    while (current != NULL)
    {
        printf("Process ID: %d\n", current->process.process_id);
        printf("CPU Burst Time: %d\n", current->process.cpu_burst_time);
        printf("Arrival Time: %d\n", current->process.arrival_time);
        printf("Completion Time: %d\n\n", completion_time);

        total_wait_time += completion_time - current->process.cpu_burst_time - current->process.arrival_time;
        total_turnaround_time += completion_time - current->process.arrival_time;

        current = current->next;
        
        if (current != NULL)
        {
            completion_time += current->process.cpu_burst_time;
        }
    }

    printf("Average Wait Time: %f\n", (float)total_wait_time / 3);
    printf("Average Turnaround Time: %f\n\n", (float)total_turnaround_time / 3);
}

void sjf(Node **head)
{
    printf("Shortest Job First (SJF) Scheduling Algorithm:\n\n");
    Node *current = *head;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int completion_time = current->process.cpu_burst_time + current->process.arrival_time;

    while (current != NULL)
    {
        Process min_burst_time_process = current->process;

        while (current != NULL)
        {
            if (current->process.cpu_burst_time < min_burst_time_process.cpu_burst_time)
            {
                min_burst_time_process = current->process;
            }

            current = current->next;
        }

        printf("Process ID: %d\n", min_burst_time_process.process_id);
        printf("CPU Burst Time: %d\n", min_burst_time_process.cpu_burst_time);
        printf("Arrival Time: %d\n", min_burst_time_process.arrival_time);
        printf("Completion Time: %d\n\n", completion_time);

        total_wait_time += completion_time - min_burst_time_process.cpu_burst_time - min_burst_time_process.arrival_time;
        total_turnaround_time += completion_time - min_burst_time_process.arrival_time;

        delete(head, min_burst_time_process);

        if (*head != NULL)
        {
            completion_time += (*head)->process.cpu_burst_time;
        }

        current = *head;
    }

    printf("Average Wait Time: %f\n", (float)total_wait_time / 3);
    printf("Average Turnaround Time: %f\n\n", (float)total_turnaround_time / 3);
}

void priority(Node **head)
{
    printf("Priority Scheduling Algorithm:\n\n");
    Node *current = *head;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int completion_time = current->process.cpu_burst_time + current->process.arrival_time;

    while (current != NULL)
    {
        Process min_priority_process = get_min_priority_process(head);

        while (min_priority_process.arrival_time > completion_time)
        {
            printf("Process ID: %d\n", -1);
            printf("CPU Burst Time: %d\n", 0);
            printf("Arrival Time: %d\n", completion_time);
            printf("Completion Time: %d\n\n", completion_time);

            completion_time = min_priority_process.arrival_time;
            min_priority_process = get_min_priority_process(head);
        }

        printf("Process ID: %d\n", min_priority_process.process_id);
        printf("CPU Burst Time: %d\n", min_priority_process.cpu_burst_time);
        printf("Arrival Time: %d\n", min_priority_process.arrival_time);
        printf("Completion Time: %d\n\n", completion_time + min_priority_process.cpu_burst_time);

        total_wait_time += completion_time - min_priority_process.arrival_time;
        total_turnaround_time += completion_time + min_priority_process.cpu_burst_time - min_priority_process.arrival_time;

        delete(head, min_priority_process);

        completion_time += min_priority_process.cpu_burst_time;

        current = *head;
    }

    printf("Average Wait Time: %f\n", (float)total_wait_time / 3);
    printf("Average Turnaround Time: %f\n\n", (float)total_turnaround_time / 3);
}

int main()
{
    Node *head = NULL;

    Process p1 = {1, 6, 0, 2};
    Process p2 = {2, 8, 1, 3};
    Process p3 = {3, 3, 2, 1};

    insert(&head, p1);
    insert(&head, p2);
    insert(&head, p3);

    printf("Initial Processes:\n\n");
    print_processes(&head);

    fcfs(&head);

    sjf(&head);

    priority(&head);

    return 0;
}