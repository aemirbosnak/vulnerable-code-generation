//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_SCHEDULE_SIZE 10

typedef struct process
{
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(int pid, char* name, int burst_time)
{
    process* new_process = (process*)malloc(sizeof(process));
    new_process->pid = pid;
    strcpy(new_process->name, name);
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;

    return new_process;
}

void add_process(process* head, process* new_process)
{
    if (head == NULL)
    {
        head = new_process;
    }
    else
    {
        head->next = new_process;
        head = new_process;
    }
}

void round_robin(process* head)
{
    time_t start_time = time(NULL);
    int current_process = 0;
    int completed_processes = 0;

    while (!completed_processes)
    {
        process* current_process_ptr = head->next;

        for (int i = 0; i < MAX_SCHEDULE_SIZE && current_process_ptr; i++)
        {
            if (current_process_ptr->remaining_time > 0)
            {
                current_process_ptr->remaining_time--;
                printf("Process %d is running...\n", current_process_ptr->pid);
                sleep(1);
            }
            current_process_ptr = current_process_ptr->next;
        }

        completed_processes++;
    }

    time_t end_time = time(NULL);
    printf("Total time taken: %ld seconds\n", end_time - start_time);
}

int main()
{
    process* head = NULL;

    // Create processes
    process* process1 = create_process(1, "Process A", 5);
    process* process2 = create_process(2, "Process B", 3);
    process* process3 = create_process(3, "Process C", 4);
    process* process4 = create_process(4, "Process D", 2);
    process* process5 = create_process(5, "Process E", 3);

    // Add processes to the queue
    add_process(head, process1);
    add_process(head, process2);
    add_process(head, process3);
    add_process(head, process4);
    add_process(head, process5);

    round_robin(head);

    return 0;
}