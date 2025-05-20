//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Node structure for Process Control Block (PCB)
struct p_node{
    int pid; // Process ID
    int burst_time; // Burst Time
    int priority; // Priority of the process
    int waiting_time; // Waiting time of the process
    int turnaround_time; // Turnaround time of the process
    struct p_node *next; // Next process
};

// Function to create a new process
struct p_node* createProcess(int pid, int burst_time, int priority){
    struct p_node *new_p = (struct p_node*)malloc(sizeof(struct p_node));
    new_p->pid = pid;
    new_p->burst_time = burst_time;
    new_p->priority = priority;
    new_p->waiting_time = 0;
    new_p->turnaround_time = 0;
    new_p->next = NULL;
    return new_p;
}

// Function to print the details of the completed processes
void printProcesses(struct p_node* head){
    struct p_node *temp = head;
    printf("------------------------------------------------------------------\n");
    printf("  PID | Burst Time | Priority | Waiting Time | Turnaround Time\n");
    printf("------------------------------------------------------------------\n");
    while(temp != NULL){
        printf("%5d |%10d |%9d |%13d |%16d\n", temp->pid, temp->burst_time, temp->priority, temp->waiting_time, temp->turnaround_time);
        temp = temp->next;
    }
    printf("------------------------------------------------------------------\n");
}

// Function to swap two processes
void swapProcesses(struct p_node *p1, struct p_node *p2){
    int temp_pid = p1->pid;
    int temp_burst_time = p1->burst_time;
    int temp_priority = p1->priority;

    p1->pid = p2->pid;
    p1->burst_time = p2->burst_time;
    p1->priority = p2->priority;

    p2->pid = temp_pid;
    p2->burst_time = temp_burst_time;
    p2->priority = temp_priority;
}

// Bubble sort to sort processes in ascending order based on priority
void sortProcesses(struct p_node *head){
    int swapped = 1;
    struct p_node *temp1;
    struct p_node *temp2 = NULL;

    // If the list is empty, return
    if (head == NULL){
        return;
    }
    
    // Bubble sort to sort processes based on their priority
    while (swapped){
        swapped = 0;
        temp1 = head;
        while (temp1->next != temp2){
            if (temp1->priority > temp1->next->priority){
                swapProcesses(temp1, temp1->next);
                swapped = 1;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct p_node *head){
    struct p_node *temp = head;

    int total_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Calculation of waiting time and turnaround time
    while (temp != NULL){
        temp->waiting_time = total_time;
        total_waiting_time += temp->waiting_time;
        total_time += temp->burst_time;
        temp->turnaround_time = total_time;
        total_turnaround_time += temp->turnaround_time;
        temp = temp->next;
    }

    // Calculation of average waiting time and turnaround time
    double avg_waiting_time = (double)total_waiting_time / (double)head->burst_time;
    double avg_turnaround_time = (double)total_turnaround_time / (double)head->burst_time;

    printf("\nAverage Waiting Time: %f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %f", avg_turnaround_time);
}

// Function to implement Priority Scheduling algorithm
void priorityScheduling(struct p_node *head){
    sortProcesses(head);
    calculateTimes(head);
    printProcesses(head);
}

// Main function to test the Priority Scheduling algorithm
int main(){
    // Seed random number generator
    srand(time(0));
    
    // Initializing the processes with random burst times and priorities
    struct p_node *p1 = createProcess(1, rand() % 10 + 1, rand() % 10 + 1);
    struct p_node *p2 = createProcess(2, rand() % 10 + 1, rand() % 10 + 1);
    struct p_node *p3 = createProcess(3, rand() % 10 + 1, rand() % 10 + 1);
    struct p_node *p4 = createProcess(4, rand() % 10 + 1, rand() % 10 + 1);
    struct p_node *p5 = createProcess(5, rand() % 10 + 1, rand() % 10 + 1);

    // Linking the processes to form a linked list
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = NULL;

    // Printing the initial details of the processes
    printf("Initial Details of the Processes:\n\n");
    printProcesses(p1);

    // Execute Priority Scheduling algorithm on the processes
    printf("\n\nExecuting Priority Scheduling on the Processes...\n\n");
    priorityScheduling(p1);

    return 0;
}