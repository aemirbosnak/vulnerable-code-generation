//FormAI DATASET v1.0 Category: System boot optimizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 500
#define MAX_BOOT_TIME 120

struct Process {
    int pid;
    int priority;
    int execution_time;
};

struct Queue {
    struct Process processes[MAX_PROCESSES];
    int front;
    int rear;
};

void initialize_queue(struct Queue *q) {
    q -> front = -1;
    q -> rear = -1;
}

int is_empty(struct Queue *q) {
    return q -> front == -1;
}

int is_full(struct Queue *q) {
    return q -> front == 0 && q -> rear == MAX_PROCESSES - 1 || q -> front == q -> rear + 1;
}

void enqueue(struct Process p, struct Queue *q) {
    if (is_full(q)) {
        printf("Error: Queue is full!\n");
        return;
    } else if (is_empty(q)) {
        q -> front = 0;
        q -> rear = 0;
    } else if (q -> rear == MAX_PROCESSES - 1) {
        q -> rear = 0;
    } else {
        q -> rear++;
    }
    
    q -> processes[q -> rear] = p;
}

struct Process dequeue(struct Queue *q) {
    struct Process p;
    
    if (is_empty(q)) {
        printf("Error: Queue is empty!\n");
        p.pid = -1;
        return p;
    }
    
    p = q -> processes[q -> front];
    
    if (q -> front == q -> rear) {    
        q -> front = -1;
        q -> rear = -1;
    } else if (q -> front == MAX_PROCESSES - 1) {
        q -> front = 0;
    } else {
        q -> front++;
    }
    
    return p;
}

int main() {
    int num_processes;
    int boot_time;
    struct Queue *high_priority;
    struct Queue *low_priority;
    struct Process p;
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    high_priority = (struct Queue *) malloc(sizeof(struct Queue));
    low_priority = (struct Queue *) malloc(sizeof(struct Queue));
    
    initialize_queue(high_priority);
    initialize_queue(low_priority);
    
    for (int i = 1; i <= num_processes; i++) {
        printf("Enter the priority and execution time of process %d: ", i);
        scanf("%d %d", &p.priority, &p.execution_time);
        p.pid = i;
        
        if (p.priority == 1) {
            enqueue(p, high_priority);
        } else {
            enqueue(p, low_priority);
        }
    }
    
    printf("Enter the boot time in seconds: ");
    scanf("%d", &boot_time);
    
    printf("\nStarting system boot...\n\n");
    sleep(1);

    for (int i = 1; i <= boot_time; i++) {
        printf("%d seconds elapsed.\n", i);
        sleep(1);

        if (!is_empty(high_priority)) {
            p = dequeue(high_priority);

            if (p.execution_time > 10) {
                printf("Process %d (High Priority) is taking too long.\n", p.pid);
                p.execution_time -= 10;
                enqueue(p, high_priority);
            } else {
                printf("Process %d (High Priority) completed in %d seconds.\n", p.pid, p.execution_time);
            }
        } else if (!is_empty(low_priority)) {
            p = dequeue(low_priority);

            if (p.execution_time > 10) {
                printf("Process %d (Low Priority) is taking too long.\n", p.pid);
                p.execution_time -= 10;
                enqueue(p, low_priority);
            } else {
                printf("Process %d (Low Priority) completed in %d seconds.\n", p.pid, p.execution_time);
            }
        }
    }

    printf("\nSystem boot completed in %d seconds.\n", boot_time);
    
    return 0;
}