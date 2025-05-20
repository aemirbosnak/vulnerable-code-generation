//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void sort_tasks(Task tasks[], int n);
void execute_tasks(Task tasks[], int n);

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    for (int i = 0; i < n; i++) {
        printf("Enter task %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    sort_tasks(tasks, n);
    execute_tasks(tasks, n);

    return 0;
}

void sort_tasks(Task tasks[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void execute_tasks(Task tasks[], int n) {
    int quantum = 2;
    int current_time = 0;
    int completed_tasks = 0;
    int i = 0;

    while (completed_tasks < n) {
        if (tasks[i].burst_time > quantum) {
            tasks[i].burst_time -= quantum;
            current_time += quantum;
        } else {
            tasks[i].burst_time = 0;
            current_time += tasks[i].burst_time;
            completed_tasks++;
            i++;
            if (i == n) {
                i = 0;
            }
        }
    }

    printf("\nExecution completed in %d time units.\n", current_time);
}