//FormAI DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep() function

// structure to hold details of each task
typedef struct {
    int id;
    int delay_time;
    int repeat_interval;
    int is_running;
} Task;

// function to execute a task
void run_task(Task* t) {
    printf("Task %d started\n", t->id);
    t->is_running = 1; // set flag to indicate the task is running
    sleep(t->delay_time); // simulate the task running for some time
    printf("Task %d completed\n", t->id);
    t->is_running = 0; // set flag to indicate the task has completed
}

int main() {
    Task tasks[5]; // create an array of 5 tasks

    // initialize each task with some values
    for (int i = 0; i < 5; i++) {
        tasks[i].id = i;
        tasks[i].delay_time = i * 2;
        tasks[i].repeat_interval = i * 3;
        tasks[i].is_running = 0;
    }

    // simulate the task scheduler running every second
    for (int time = 0; time < 10; time++) {
        printf("Time %d\n", time);

        // check each task to see if it should be run
        for (int i = 0; i < 5; i++) {
            Task* t = &tasks[i];

            // check if the task is due to run
            if (!t->is_running && (time % t->repeat_interval == 0)) {
                // execute the task
                run_task(t);
            }
        }

        sleep(1); // wait for 1 second before checking tasks again
    }

    exit(EXIT_SUCCESS);
}