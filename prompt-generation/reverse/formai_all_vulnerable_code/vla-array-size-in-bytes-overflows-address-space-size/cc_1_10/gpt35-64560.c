//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define MAX_PROCESSES 20
#define TIME_QUANTUM 2

struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    int last_executed_time;
};

struct process processes[MAX_PROCESSES];
int num_processes;

int total_waiting_time = 0;
int total_turnaround_time = 0;
int total_response_time = 0;

pthread_mutex_t mutex_lock;

void *round_robin_scheduler(void *arg)
{
    struct process *p = (struct process *) arg;
    while(p->remaining_time > 0)
    {
        pthread_mutex_lock(&mutex_lock);
        if(p->remaining_time > TIME_QUANTUM)
        {
            p->remaining_time -= TIME_QUANTUM;
        }
        else
        {
            p->waiting_time += p->last_executed_time - p->arrival_time - p->burst_time + p->remaining_time;
            p->remaining_time = 0;
        }
        p->last_executed_time += TIME_QUANTUM;
        pthread_mutex_unlock(&mutex_lock);
        usleep(1000);
    }
    p->turnaround_time = p->last_executed_time - p->arrival_time;
    p->waiting_time = p->turnaround_time - p->burst_time;

    total_turnaround_time += p->turnaround_time;
    total_waiting_time += p->waiting_time;
    total_response_time += p->waiting_time + p->burst_time;

    return NULL;
}

void initialize_processes(int n)
{
    printf("Enter arrival time and burst time for each process:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i;
        processes[i].waiting_time = 0;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].last_executed_time = processes[i].arrival_time;
    }
}

void print_processes()
{
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
            processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float) total_waiting_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / num_processes);
    printf("Average Response Time: %.2f\n", (float) total_response_time / num_processes);
}

int main()
{
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    initialize_processes(num_processes);

    pthread_t thread_id[num_processes];
    pthread_mutex_init(&mutex_lock, NULL);

    for(int i = 0; i < num_processes; i++)
    {
        pthread_create(&thread_id[i], NULL, round_robin_scheduler, (void *) &processes[i]);
    }

    for(int i = 0; i < num_processes; i++)
    {
        pthread_join(thread_id[i], NULL);
    }

    print_processes();

    return 0;
}