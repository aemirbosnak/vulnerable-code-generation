//FormAI DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME 20

typedef struct task {
    char name[MAX_NAME];
    int priority;
    int burst;
    pid_t pid;
    int status;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char* name, int priority, int burst) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }
    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].burst = burst;
    tasks[num_tasks].pid = 0;
    tasks[num_tasks].status = 0;
    num_tasks++;
}

void remove_task(int index) {
    if (index < 0 || index >= num_tasks) {
        printf("Error: Invalid task index.\n");
        return;
    }
    if (tasks[index].pid > 0) {
        kill(tasks[index].pid, SIGTERM);
    }
    for (int i = index; i < num_tasks-1; i++) {
        tasks[i] = tasks[i+1];
    }
    num_tasks--;
}

void print_tasks() {
    printf("Task\tPriority\tBurst\tStatus\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%d\t%s\n", tasks[i].name, tasks[i].priority,
               tasks[i].burst, tasks[i].status == 0 ? "READY" : "RUNNING");
    }
}

void start_scheduler(int interval) {
    int current_task = 0;
    time_t start, end;
    while (num_tasks > 0) {
        start = time(NULL);
        if (tasks[current_task].status == 0) {
            printf("Starting task %s...\n", tasks[current_task].name);
            tasks[current_task].status = 1;
            tasks[current_task].pid = fork();
            if (tasks[current_task].pid == -1) {
                printf("Error: Could not fork task.\n");
                tasks[current_task].status = 0;
                continue;
            } else if (tasks[current_task].pid == 0) {
                execlp("./task", "./task", tasks[current_task].name, 
                       NULL);
                printf("Error: Could not exec task.\n");
                exit(1);
            }
        } else if (tasks[current_task].status == 1) {
            printf("Continuing task %s...\n", tasks[current_task].name);
        } else if (tasks[current_task].status == 2) {
            printf("Waiting for task %s...\n", tasks[current_task].name);
            waitpid(tasks[current_task].pid, NULL, 0);
            printf("Task %s completed.\n", tasks[current_task].name);
            remove_task(current_task);
            current_task %= num_tasks;
            continue;
        } else {
            printf("Error: Invalid task status.\n");
            continue;
        }
        tasks[current_task].status = 1;
        sleep(tasks[current_task].burst);
        end = time(NULL);
        double diff = difftime(end, start);
        if (diff < tasks[current_task].burst) {
            sleep(tasks[current_task].burst - (int) diff);
        }
        tasks[current_task].status = 2;
        current_task = (current_task + 1) % num_tasks;
        printf("Switching to next task...\n");
        sleep(interval);
    }
    printf("All tasks completed.\n");
}

int main() {
    add_task("task1", 5, 2);
    add_task("task2", 3, 4);
    add_task("task3", 1, 6);
    print_tasks();
    start_scheduler(3);
    return 0;
}