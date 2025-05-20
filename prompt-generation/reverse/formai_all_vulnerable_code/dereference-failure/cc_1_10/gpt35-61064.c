//FormAI DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Task struct to hold task information
typedef struct {
    int id;
    int priority;
    float execution_time;
} Task;

// Define a Schedule struct to hold the schedule information
typedef struct {
    Task* tasks;
    int num_tasks;
    float total_execution_time;
    float average_execution_time;
    float total_priority;
    float average_priority;
} Schedule;

// Define a function to create a new Task
Task create_task(int id, int priority, float execution_time) {
    Task task;
    task.id = id;
    task.priority = priority;
    task.execution_time = execution_time;
    return task;
}

// Define a function to generate a random Task with a random execution time
Task generate_random_task(int id) {
    int priority = rand() % 10 + 1;
    float execution_time = (float)(rand() % 100) / 10.0;
    return create_task(id, priority, execution_time);
}

// Define a function to create a new Schedule
Schedule create_schedule() {
    Schedule schedule;
    schedule.tasks = NULL;
    schedule.num_tasks = 0;
    schedule.total_execution_time = 0;
    schedule.average_execution_time = 0;
    schedule.total_priority = 0;
    schedule.average_priority = 0;
    return schedule;
}

// Define a function to add a Task to a Schedule
void add_task_to_schedule(Task task, Schedule* schedule) {
    schedule->num_tasks++;
    schedule->tasks = (Task*)realloc(schedule->tasks, schedule->num_tasks * sizeof(Task));
    schedule->tasks[schedule->num_tasks - 1] = task;

    schedule->total_execution_time += task.execution_time;
    schedule->average_execution_time = schedule->total_execution_time / schedule->num_tasks;

    schedule->total_priority += task.priority;
    schedule->average_priority = schedule->total_priority / schedule->num_tasks;
}

// Define a function to print the details of a Schedule
void print_schedule_details(Schedule schedule) {
    printf("Number of tasks: %d\n", schedule.num_tasks);
    printf("Total execution time: %f\n", schedule.total_execution_time);
    printf("Average execution time: %f\n", schedule.average_execution_time);
    printf("Total priority: %f\n", schedule.total_priority);
    printf("Average priority: %f\n", schedule.average_priority);

    printf("Task details:\n");
    for (int i = 0; i < schedule.num_tasks; i++) {
        printf("ID: %d | Priority: %d | Execution Time: %f\n", schedule.tasks[i].id, schedule.tasks[i].priority, schedule.tasks[i].execution_time);
    }
}

int main() {
    srand(time(NULL)); // set seed for rand() function

    Schedule schedule = create_schedule();

    // Generate and add 10 random tasks to the schedule
    for (int i = 1; i <= 10; i++) {
        Task task = generate_random_task(i);
        add_task_to_schedule(task, &schedule);
    }

    // Print the details of the schedule
    print_schedule_details(schedule);

    return 0;
}