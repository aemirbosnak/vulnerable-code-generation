//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int priority;
    int execution_time;
    int arrival_time;
} task;

typedef struct {
    task *tasks;
    int num_tasks;
    int current_time;
} schedule;

task *create_task(char *name, int priority, int execution_time, int arrival_time) {
    task *new_task = malloc(sizeof(task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->arrival_time = arrival_time;
    return new_task;
}

schedule *create_schedule(task *tasks, int num_tasks) {
    schedule *new_schedule = malloc(sizeof(schedule));
    new_schedule->tasks = tasks;
    new_schedule->num_tasks = num_tasks;
    new_schedule->current_time = 0;
    return new_schedule;
}

void print_schedule(schedule *schedule) {
    printf("Schedule:\n");
    for (int i = 0; i < schedule->num_tasks; i++) {
        printf("%s %d %d %d\n", schedule->tasks[i].name, schedule->tasks[i].priority, schedule->tasks[i].execution_time, schedule->tasks[i].arrival_time);
    }
}

void run_schedule(schedule *schedule) {
    while (schedule->current_time < 100) {
        // Find the next task to run
        int next_task_index = -1;
        for (int i = 0; i < schedule->num_tasks; i++) {
            if (schedule->tasks[i].arrival_time <= schedule->current_time &&
                (next_task_index == -1 || schedule->tasks[i].priority > schedule->tasks[next_task_index].priority)) {
                next_task_index = i;
            }
        }

        // If there is no more task then exit loop.
        if (next_task_index == -1) {
            break;
        }

        // Run the task
        task *task = &schedule->tasks[next_task_index];
        printf("Running task %s at time %d\n", task->name, schedule->current_time);

        // Update the current time
        schedule->current_time += task->execution_time;

        // Remove the task from the schedule
        for (int i = next_task_index; i < schedule->num_tasks - 1; i++) {
            schedule->tasks[i] = schedule->tasks[i + 1];
        }
        schedule->num_tasks--;
    }
}

int main() {
    // Create a list of tasks
    task *tasks[] = {
        create_task("Task 1", 1, 10, 0),
        create_task("Task 2", 2, 5, 5),
        create_task("Task 3", 3, 15, 10),
        create_task("Task 4", 4, 20, 15),
        create_task("Task 5", 5, 25, 20),
    };
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    // Create a schedule
    schedule *schedule = create_schedule(tasks, num_tasks);

    // Print the schedule
    print_schedule(schedule);

    // Run the schedule
    run_schedule(schedule);

    return 0;
}