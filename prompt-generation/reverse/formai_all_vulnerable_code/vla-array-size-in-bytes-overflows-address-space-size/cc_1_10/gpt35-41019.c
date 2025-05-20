//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

typedef struct Node {
    Process process;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initialize(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, Process process) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->process = process;
    node->next = NULL;
    if(isEmpty(queue)) {
        queue->front = node;
    }
    else {
        queue->rear->next = node;
    }
    queue->rear = node;
}

void printQueue(Queue* queue) {
    Node* temp = queue->front;
    printf("Queue: ");
    while(temp != NULL) {
        printf("P%d -> ", temp->process.pid);
        temp = temp->next;
    }
    printf("\n");
}

void FCFS(Process p[], int n) {
    printf("FCFS Scheduling:\n");
    Queue queue;
    initialize(&queue);
    int time = 0, i = 0, wait_time = 0, turn_around_time = 0;
    enqueue(&queue, p[i]);
    i++;
    while(!isEmpty(&queue)) {
        Process temp = queue.front->process;
        queue.front = queue.front->next;
        if(queue.front == NULL) {
            queue.rear = NULL;
        }
        printf("P%d starts execution at time %d.\n", temp.pid, time);
        wait_time += time - temp.arrival_time;
        time += temp.burst_time;
        turn_around_time += time - temp.arrival_time;
        while(i < n && p[i].arrival_time <= time) {
            enqueue(&queue, p[i]);
            i++;
        }
    }
    printf("Average Waiting Time: %.2f\n", (float) wait_time / n);
    printf("Average Turnaround Time: %.2f\n", (float) turn_around_time / n);
}

void SJF(Process p[], int n) {
    printf("SJF Scheduling:\n");
    Queue queue;
    initialize(&queue);
    int time = 0, i = 0, wait_time = 0, turn_around_time = 0;
    enqueue(&queue, p[i]);
    i++;
    while(!isEmpty(&queue)) {
        int min_burst_time = 9999;
        Node* temp = queue.front, *prev = NULL, *min_prev = NULL;
        while(temp != NULL) {
            if(temp->process.burst_time < min_burst_time) {
                min_burst_time = temp->process.burst_time;
                min_prev = prev;
            }
            prev = temp;
            temp = temp->next;
        }
        if(min_prev == NULL) {
            Process min = queue.front->process;
            queue.front = queue.front->next;
            if(queue.front == NULL) {
                queue.rear = NULL;
            }
            temp = queue.front;
            printf("P%d starts execution at time %d.\n", min.pid, time);
            wait_time += time - min.arrival_time;
            time += min.burst_time;
            turn_around_time += time - min.arrival_time;
        }
        else {
            Node* min = min_prev->next;
            Process min_process = min->process;
            min_prev->next = min->next;
            if(min_prev->next == NULL) {
                queue.rear = min_prev;
            }
            printf("P%d starts execution at time %d.\n", min_process.pid, time);
            wait_time += time - min_process.arrival_time;
            time += min_process.burst_time;
            turn_around_time += time - min_process.arrival_time;
        }
        while(i < n && p[i].arrival_time <= time) {
            enqueue(&queue, p[i]);
            i++;
        }
    }
    printf("Average Waiting Time: %.2f\n", (float) wait_time / n);
    printf("Average Turnaround Time: %.2f\n", (float) turn_around_time / n);
}

void Priority(Process p[], int n) {
    printf("Priority Scheduling:\n");
    Queue queue;
    initialize(&queue);
    int time = 0, i = 0, wait_time = 0, turn_around_time = 0;
    enqueue(&queue, p[i]);
    i++;
    while(!isEmpty(&queue)) {
        int min_priority = 9999;
        Node* temp = queue.front, *prev = NULL, *min_prev = NULL;
        while(temp != NULL) {
            if(temp->process.priority < min_priority) {
                min_priority = temp->process.priority;
                min_prev = prev;
            }
            prev = temp;
            temp = temp->next;
        }
        if(min_prev == NULL) {
            Process min = queue.front->process;
            queue.front = queue.front->next;
            if(queue.front == NULL) {
                queue.rear = NULL;
            }
            temp = queue.front;
            printf("P%d starts execution at time %d.\n", min.pid, time);
            wait_time += time - min.arrival_time;
            time += min.burst_time;
            turn_around_time += time - min.arrival_time;
        }
        else {
            Node* min = min_prev->next;
            Process min_process = min->process;
            min_prev->next = min->next;
            if(min_prev->next == NULL) {
                queue.rear = min_prev;
            }
            printf("P%d starts execution at time %d.\n", min_process.pid, time);
            wait_time += time - min_process.arrival_time;
            time += min_process.burst_time;
            turn_around_time += time - min_process.arrival_time;
        }
        while(i < n && p[i].arrival_time <= time) {
            enqueue(&queue, p[i]);
            i++;
        }
    }
    printf("Average Waiting Time: %.2f\n", (float) wait_time / n);
    printf("Average Turnaround Time: %.2f\n", (float) turn_around_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process p[n];
    printf("Enter the arrival time, burst time, and priority of each process:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].pid = i+1;
    }
    printf("\n");
    FCFS(p, n);
    printf("\n");
    SJF(p, n);
    printf("\n");
    Priority(p, n);
    return 0;
}