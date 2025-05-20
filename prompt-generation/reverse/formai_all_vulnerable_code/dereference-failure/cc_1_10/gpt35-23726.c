//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct process{
    int pid; // process ID
    int burst_time; // time required to complete the process
    int priority; // priority of the process (lower priority value indicates higher priority)
    struct process* next; // pointer to the next process in the queue
}process_t;

process_t* head = NULL; // pointer to the head of the queue
process_t* tail = NULL; // pointer to the tail of the queue

// function to add a new process to the queue
void add_process(int pid, int burst_time, int priority){
    process_t* new_process = (process_t*) malloc(sizeof(process_t));
    new_process->pid = pid;
    new_process->burst_time = burst_time;
    new_process->priority = priority;
    new_process->next = NULL;
    if(head == NULL){
        head = new_process;
    } else {
        tail->next = new_process;
    }
    tail = new_process;
}

// function to remove the process with the highest priority from the queue
process_t* remove_highest_priority_process(){
    process_t* temp = head;
    process_t* highest_priority_process = head;
    while(temp != NULL){
        if(temp->priority < highest_priority_process->priority){
            highest_priority_process = temp;
        }
        temp = temp->next;
    }
    if(highest_priority_process == head){
        head = head->next;
    } else {
        temp = head;
        while(temp->next != highest_priority_process){
            temp = temp->next;
        }
        temp->next = highest_priority_process->next;
    }
    return highest_priority_process;
}

int main(){
    srand(time(NULL)); // seed the random number generator
    int i = 0;
    
    // add 10 random processes to the queue
    for(i=0;i<10;i++){
        int pid = i+1;
        int burst_time = rand()%10+1;
        int priority = rand()%10+1;
        add_process(pid,burst_time,priority);
    }
    
    printf("Process ID\tBurst Time\tPriority\n");
    process_t* temp = head;
    while(temp != NULL){ // display the contents of the queue
        printf("%d\t\t%d\t\t%d\n",temp->pid,temp->burst_time,temp->priority);
        temp = temp->next;
    }
    
    printf("\nExecuting processes in priority order:\n");
    int time_elapsed = 0;
    while(head != NULL){ // execute the processes in priority order
        process_t* current_process = remove_highest_priority_process();
        printf("\nProcess %d started execution.\n",current_process->pid);
        time_elapsed += current_process->burst_time;
        printf("Process %d completed execution after %d units of time.\n",current_process->pid,current_process->burst_time);
        free(current_process);
    }
    printf("\nAll processes completed execution in %d units of time.\n",time_elapsed);
    return 0;
}