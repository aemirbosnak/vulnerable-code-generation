//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

//Defining the structures required
struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

struct Node {
    struct Process *process;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

//Queue functions
void enqueue(struct Queue *q, struct Process *p) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->process = p;
    newNode->next = NULL;
    if(q->front == NULL && q->rear == NULL) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(struct Queue *q) {
    if(q->front == NULL)
        return;
    struct Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    if(q->front == NULL)
        q->rear = NULL;
}

struct Process* peek(struct Queue *q) {
    if(q->front == NULL)
        return NULL;
    return q->front->process;
}

int isEmpty(struct Queue *q) {
    if(q->front == NULL)
        return 1;
    return 0;
}

//Function to sort processes based on priority
void sort(struct Process **p, int n) {
    for(int i=0;i<n-1;++i) {
        for(int j=0;j<n-i-1;++j) {
            if(p[j]->priority > p[j+1]->priority) {
                struct Process *temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

//Function to calculate waiting time and turnaround time for each process
void calcTime(struct Process **p, int n) {
    p[0]->waiting_time = 0;
    p[0]->turnaround_time = p[0]->burst_time;
    for(int i=1;i<n;++i) {
        p[i]->waiting_time = p[i-1]->turnaround_time;
        p[i]->turnaround_time = p[i]->waiting_time + p[i]->burst_time;
    }
}

void display(struct Process **p, int n) {
    printf("PID\tARRIVAL TIME\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n");
    for(int i=0;i<n;++i) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i]->pid,p[i]->arrival_time,p[i]->burst_time,p[i]->priority,p[i]->waiting_time,p[i]->turnaround_time);
    }
}

//Priority scheduling algorithm
void priorityScheduling(struct Process **p, int n) {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;

    int counter = 0;
    int time = 0;
    while(counter < n) {
        for(int i=0;i<n;++i) {
            if(p[i]->arrival_time == time)
                enqueue(q,p[i]);
        }
        if(isEmpty(q)) {
            printf("CPU Idle for 1 unit of time.\n");
            time++;
            continue;
        }
        struct Process *currentProcess = peek(q);
        dequeue(q);
        printf("Process with ID %d is running for %d units of time.\n",currentProcess->pid,currentProcess->burst_time);
        time += currentProcess->burst_time;
        counter++;
    }
    free(q);
}

int main() {
    //Creating processes
    struct Process *p1 = (struct Process*)malloc(sizeof(struct Process));
    p1->pid = 1;
    p1->arrival_time = 0;
    p1->burst_time = 5;
    p1->priority = 3;

    struct Process *p2 = (struct Process*)malloc(sizeof(struct Process));
    p2->pid = 2;
    p2->arrival_time = 3;
    p2->burst_time = 2;
    p2->priority = 1;

    struct Process *p3 = (struct Process*)malloc(sizeof(struct Process));
    p3->pid = 3;
    p3->arrival_time = 4;
    p3->burst_time = 4;
    p3->priority = 2;

    struct Process *p4 = (struct Process*)malloc(sizeof(struct Process));
    p4->pid = 4;
    p4->arrival_time = 6;
    p4->burst_time = 1;
    p4->priority = 4;

    struct Process *p5 = (struct Process*)malloc(sizeof(struct Process));
    p5->pid = 5;
    p5->arrival_time = 8;
    p5->burst_time = 3;
    p5->priority = 5;

    int n = 5;
    struct Process *p[n];
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;

    //Sorting the processes based on priority
    sort(p,n);

    //Calculating waiting time and turnaround time for each process
    calcTime(p,n);

    //Displaying the processes with their respective waiting time and turnaround time
    display(p,n);

    //Implementing priority scheduling algorithm
    printf("\nImplementing Priority Scheduling Algorithm:\n\n");
    priorityScheduling(p,n);

    //Freeing up memory
    for(int i=0;i<n;++i)
        free(p[i]);
    return 0;
}