//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

struct task {
    int task_id;
    int priority;
    int time;
};

void execute_task(struct task task) {
    printf("Executing task #%d with priority %d for %d seconds\n", task.task_id, task.priority, task.time);
}

int main() {

    int n, i, j;
    
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    
    struct task tasks[n];
    
    for(i=0; i<n; i++) {
        printf("\nTask %d", i+1);
        printf("\nEnter Task ID: ");
        scanf("%d", &tasks[i].task_id);
        printf("Enter Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Enter Execution Time (in seconds): ");
        scanf("%d", &tasks[i].time);
    }
    
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(tasks[i].priority < tasks[j].priority) {
                struct task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    
    printf("\nExecuting tasks...\n");
    
    for(i=0; i<n; i++) {
        execute_task(tasks[i]);
    }
    
    printf("\nAll tasks done!");
    
    return 0;
}