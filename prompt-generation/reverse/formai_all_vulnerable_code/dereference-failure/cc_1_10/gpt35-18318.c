//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

typedef struct
{
    int pid; // Process ID
    int burst_time; // Burst time of the process
    int priority; // Priority of the process
} Process;

Process *create_process(int pid, int burst_time, int priority)
{
    Process *p = (Process *) malloc(sizeof(Process));
    p->pid = pid;
    p->burst_time = burst_time;
    p->priority = priority;
    return p;
}

void display_process(Process *p)
{
    printf("Process ID: %d, Burst Time: %d, Priority: %d\n", p->pid, p->burst_time, p->priority);
}

typedef struct Node
{
    Process *p;
    struct Node *next;
} Node;

Node *create_node(Process *p)
{
    Node *n = (Node *) malloc(sizeof(Node));
    n->p = p;
    n->next = NULL;
    return n;
}

typedef struct
{
    Node *head;
    Node *tail;
} Queue;

Queue *create_queue()
{
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue *q, Process *p)
{
    Node *n = create_node(p);

    if (q->head == NULL) // Queue is empty
    {
        q->head = n;
        q->tail = n;
    }
    else
    {
        q->tail->next = n;
        q->tail = n;
    }
}

Process *dequeue(Queue *q)
{
    if (q->head == NULL) // Queue is empty
    {
        return NULL;
    }
    else
    {
        Node *n = q->head;
        Process *p = n->p;

        if (q->head == q->tail) // Only one element in queue
        {
            q->head = NULL;
            q->tail = NULL;
        }
        else
        {
            q->head = q->head->next;
        }

        free(n);
        return p;
    }
}

typedef struct
{
    int quantum; // Time quantum for Round Robin
} Scheduler_Data;

typedef struct
{
    Queue *queue; // Queue of processes
    Scheduler_Data *scheduler_data; // Scheduler-specific data
} Scheduler;

Scheduler *create_scheduler(Scheduler_Data *data)
{
    Scheduler *s = (Scheduler *) malloc(sizeof(Scheduler));
    s->queue = create_queue();
    s->scheduler_data = data;
    return s;
}

void add_process(Scheduler *s, Process *p)
{
    enqueue(s->queue, p);
}

Process *get_next_process(Scheduler *s)
{
    return dequeue(s->queue);
}

void display_queue(Queue *q)
{
    printf("Queue\n--------\n");

    Node *current = q->head;
    while (current != NULL)
    {
        display_process(current->p);
        current = current->next;
    }
}

void first_come_first_serve(Scheduler *s)
{
    printf("First Come First Serve Scheduling\n\n");

    int current_time = 0;

    while (s->queue->head != NULL)
    {
        Process *p = get_next_process(s);
        int wait_time = current_time;
        int turnaround_time = wait_time + p->burst_time;
        printf("PID: %d, Wait Time: %d, Turnaround Time: %d\n", p->pid, wait_time, turnaround_time);
        current_time += p->burst_time;
        free(p);
    }
}

void shortest_job_first(Scheduler *s)
{
    printf("Shortest Job First Scheduling\n\n");

    int current_time = 0;

    while (s->queue->head != NULL)
    {
        Node *current = s->queue->head;
        Node *previous = NULL;
        Node *shortest = current;
        Node *shortest_previous = previous;

        // Find shortest job in queue
        while (current != NULL)
        {
            if (current->p->burst_time < shortest->p->burst_time)
            {
                shortest = current;
                shortest_previous = previous;
            }
            previous = current;
            current = current->next;
        }

        if (shortest_previous == NULL) // Shortest job is at head of queue
        {
            s->queue->head = shortest->next;
        }
        else
        {
            shortest_previous->next = shortest->next;
        }

        if (shortest == s->queue->tail) // Shortest job is at tail of queue
        {
            s->queue->tail = shortest_previous;
        }

        shortest->next = NULL;

        Process *p = shortest->p;
        int wait_time = current_time;
        int turnaround_time = wait_time + p->burst_time;
        printf("PID: %d, Wait Time: %d, Turnaround Time: %d\n", p->pid, wait_time, turnaround_time);
        current_time += p->burst_time;

        free(shortest);
    }
}

void priority_scheduling(Scheduler *s)
{
    printf("Priority Scheduling\n\n");

    int current_time = 0;

    while (s->queue->head != NULL)
    {
        Node *current = s->queue->head;
        Node *previous = NULL;
        Node *highest_priority = current;
        Node *highest_priority_previous = previous;

        // Find process with highest priority in queue
        while (current != NULL)
        {
            if (current->p->priority < highest_priority->p->priority)
            {
                highest_priority = current;
                highest_priority_previous = previous;
            }
            previous = current;
            current = current->next;
        }

        if (highest_priority_previous == NULL) // Highest priority process is at head of queue
        {
            s->queue->head = highest_priority->next;
        }
        else
        {
            highest_priority_previous->next = highest_priority->next;
        }

        if (highest_priority == s->queue->tail) // Highest priority process is at tail of queue
        {
            s->queue->tail = highest_priority_previous;
        }

        highest_priority->next = NULL;

        Process *p = highest_priority->p;
        int wait_time = current_time;
        int turnaround_time = wait_time + p->burst_time;
        printf("PID: %d, Wait Time: %d, Turnaround Time: %d\n", p->pid, wait_time, turnaround_time);
        current_time += p->burst_time;

        free(highest_priority);
    }
}

void round_robin(Scheduler *s)
{
    printf("Round Robin Scheduling\n\n");

    int current_time = 0;

    while (s->queue->head != NULL)
    {
        Process *p = get_next_process(s);
        int remaining_time = p->burst_time;
        int wait_time = current_time;
        bool first_run = true; // Flag to indicate first time process is run

        while (remaining_time > 0)
        {
            if (!first_run)
            {
                p = get_next_process(s);
            }
            if (p == NULL) // Queue is empty
            {
                break;
            }
            int time_slice = s->scheduler_data->quantum;
            if (time_slice > remaining_time)
            {
                time_slice = remaining_time;
            }
            printf("PID: %d, Time Slice: %d\n", p->pid, time_slice);
            remaining_time -= time_slice;
            current_time += time_slice;

            if (remaining_time > 0)
            {
                enqueue(s->queue, p);
            }

            first_run = false;
        }

        if (remaining_time == 0)
        {
            int turnaround_time = current_time - wait_time;
            printf("PID: %d, Wait Time: %d, Turnaround Time: %d\n", p->pid, wait_time, turnaround_time);
            free(p);
        }
        else
        {
            // Process did not complete, enqueue for future run
            add_process(s, p);
        }
    }
}

int main()
{
    // Create processes
    Process *p1 = create_process(1, 10, 5);
    Process *p2 = create_process(2, 5, 3);
    Process *p3 = create_process(3, 8, 8);
    Process *p4 = create_process(4, 3, 1);
    Process *p5 = create_process(5, 7, 2);
    Process *p6 = create_process(6, 12, 6);

    // Create queues
    Queue *fcfs_queue = create_queue();
    Queue *sjf_queue = create_queue();
    Queue *ps_queue = create_queue();
    Queue *rr_queue = create_queue();

    // Add processes to queues
    enqueue(fcfs_queue, p1);
    enqueue(fcfs_queue, p2);
    enqueue(fcfs_queue, p3);
    enqueue(fcfs_queue, p4);
    enqueue(fcfs_queue, p5);
    enqueue(fcfs_queue, p6);

    enqueue(sjf_queue, p1);
    enqueue(sjf_queue, p2);
    enqueue(sjf_queue, p3);
    enqueue(sjf_queue, p4);
    enqueue(sjf_queue, p5);
    enqueue(sjf_queue, p6);

    enqueue(ps_queue, p1);
    enqueue(ps_queue, p2);
    enqueue(ps_queue, p3);
    enqueue(ps_queue, p4);
    enqueue(ps_queue, p5);
    enqueue(ps_queue, p6);

    enqueue(rr_queue, p1);
    enqueue(rr_queue, p2);
    enqueue(rr_queue, p3);
    enqueue(rr_queue, p4);
    enqueue(rr_queue, p5);
    enqueue(rr_queue, p6);

    // Create schedulers
    Scheduler_Data *fcfs_data = NULL;
    Scheduler *fcfs_scheduler = create_scheduler(fcfs_data);

    Scheduler_Data *sjf_data = NULL;
    Scheduler *sjf_scheduler = create_scheduler(sjf_data);

    Scheduler_Data *ps_data = NULL;
    Scheduler *ps_scheduler = create_scheduler(ps_data);

    Scheduler_Data *rr_data = (Scheduler_Data *) malloc(sizeof(Scheduler_Data));
    rr_data->quantum = 3;
    Scheduler *rr_scheduler = create_scheduler(rr_data);

    // Schedule processes
    first_come_first_serve(fcfs_scheduler);
    display_queue(sjf_queue);
    shortest_job_first(sjf_scheduler);
    display_queue(ps_queue);
    priority_scheduling(ps_scheduler);
    display_queue(rr_queue);
    round_robin(rr_scheduler);

    // Clean up
    free(fcfs_queue);
    free(sjf_queue);
    free(ps_queue);
    free(rr_queue);
    free(fcfs_scheduler);
    free(sjf_scheduler);
    free(ps_scheduler);
    free(rr_scheduler);
    free(rr_data);

    return 0;
}