//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

void task1(void);
void task2(void);
void task3(void);

typedef struct {
    void (*function)(void);
    int interval;
    time_t last_execution;
} task_t;

task_t tasks[MAX_TASKS];

int main() {
    tasks[0].function = &task1;
    tasks[0].interval = 1;
    
    tasks[1].function = &task2;
    tasks[1].interval = 2;
    
    tasks[2].function = &task3;
    tasks[2].interval = 3;

    time_t current_time;
    int i;

    while(1) {
        current_time = time(NULL);

        for(i = 0; i < MAX_TASKS; i++) {
            if(difftime(current_time, tasks[i].last_execution) >= tasks[i].interval) {
                tasks[i].function();
                tasks[i].last_execution = current_time;
            }
        }
    }

    return 0;
}

void task1(void) {
    printf("Executing Task 1...\n");
}

void task2(void) {
    printf("Executing Task 2...\n");
}

void task3(void) {
    printf("Executing Task 3...\n");
}