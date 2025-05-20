//FormAI DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char name[20];
    int burst_time;
} Task;

void scheduler(Task* tasks, int num_tasks);
void print_greeting();
void print_goodbye();

int main() {
    // create tasks
    Task tasks[5] = {
        {"Task 1", 10},
        {"Task 2", 5},
        {"Task 3", 20},
        {"Task 4", 15},
        {"Task 5", 7}
    };
    
    print_greeting();
    
    // execute task scheduler
    scheduler(tasks, 5);
    
    print_goodbye();
    
    return 0;
}

void scheduler(Task* tasks, int num_tasks) {
    int total_time = 0;
    int current_time = 0;
    bool busy = false;
    int current_task_index = -1;
    
    // calculate total time needed for all tasks
    for (int i = 0; i < num_tasks; i++) {
        total_time += tasks[i].burst_time;
    }
    
    // execute tasks
    while (current_time < total_time) {
        // print current time
        printf("Time: %d\n", current_time);
        
        // check if current task is completed
        if (busy && current_time - tasks[current_task_index].burst_time == 0) {
            printf("Task %s completed!\n", tasks[current_task_index].name);
            busy = false;
        }
        
        // check if there is an available task
        if (!busy) {
            // find task with shortest burst time
            int shortest_burst_time = total_time;
            for (int i = 0; i < num_tasks; i++) {
                if (tasks[i].burst_time < shortest_burst_time && tasks[i].burst_time > 0) {
                    shortest_burst_time = tasks[i].burst_time;
                    current_task_index = i;
                }
            }
            
            // execute task
            printf("Executing Task %s...\n", tasks[current_task_index].name);
            busy = true;
        }
        
        // increase current time
        current_time++;
        
        // subtract burst time of current task
        if (busy) {
            tasks[current_task_index].burst_time--;
        }
        
        // add idle time
        if (!busy) {
            printf("Idle time...\n");
        }
    }
}

void print_greeting() {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    int hour = timeinfo->tm_hour;
    
    if (hour < 12) {
        printf("Good morning! Welcome to the Task Scheduler.\n\n");
    } else if (hour < 18) {
        printf("Good afternoon! Welcome to the Task Scheduler.\n\n");
    } else {
        printf("Good evening! Welcome to the Task Scheduler.\n\n");
    }
}

void print_goodbye() {
    printf("\nAll tasks completed! Thank you for using the Task Scheduler.\n");
}