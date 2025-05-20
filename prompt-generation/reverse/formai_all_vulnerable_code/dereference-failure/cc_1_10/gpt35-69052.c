//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct task_t {
    int id;
    int priority;
    int arrival_time;
    int execution_time;
    struct task_t *next;
} task_t;

task_t *task_list = NULL;

task_t *create_new_task(int id, int priority, int arrival_time, int execution_time) {
    task_t *new_task = (task_t *) malloc(sizeof(task_t));
    new_task->id = id;
    new_task->priority = priority;
    new_task->arrival_time = arrival_time;
    new_task->execution_time = execution_time;
    new_task->next = NULL;
    return new_task;
}

void add_task(int id, int priority, int arrival_time, int execution_time) {
    task_t *new_task = create_new_task(id, priority, arrival_time, execution_time);
    if (task_list == NULL) {
        task_list = new_task;
        return;
    }
    task_t *current_task = task_list;
    while (current_task->next != NULL) {
        current_task = current_task->next;
    }
    current_task->next = new_task;
}

void print_task_list() {
    printf("Task List:\n");
    printf("ID\tPriority\tArrival Time\tExecution Time\n");
    task_t *current_task = task_list;
    while (current_task != NULL) {
        printf("%d\t%d\t\t%d\t\t%d\n", current_task->id, current_task->priority, 
               current_task->arrival_time, current_task->execution_time);
        current_task = current_task->next;
    }
}

int get_highest_priority() {
    task_t *current_task = task_list;
    int highest_priority = 0;
    while (current_task != NULL) {
        if (current_task->priority > highest_priority) {
            highest_priority = current_task->priority;
        }
        current_task = current_task->next;
    }
    return highest_priority;
}

void schedule_tasks() {
    while (task_list != NULL) {
        // Get the highest priority task
        int highest_priority = get_highest_priority();
        task_t *current_task = task_list;
        task_t *highest_priority_task = NULL;
        while (current_task != NULL) {
            if (current_task->priority == highest_priority) {
                if (highest_priority_task == NULL) {
                    highest_priority_task = current_task;
                } else if (current_task->arrival_time < highest_priority_task->arrival_time) {
                    highest_priority_task = current_task;
                }
            }
            current_task = current_task->next;
        }
        // Execute the task
        printf("Executing task with ID %d\n", highest_priority_task->id);
        for (int i = 1; i <= highest_priority_task->execution_time; i++) {
            printf("Executing step %d of task with ID %d\n", i, highest_priority_task->id);
        }
        // Remove the task from the task list
        task_t *previous_task = NULL;
        current_task = task_list;
        while (current_task->id != highest_priority_task->id) {
            previous_task = current_task;
            current_task = current_task->next;
        }
        if (previous_task == NULL && current_task->next == NULL) {
            task_list = NULL;
        } else if (previous_task == NULL && current_task->next != NULL) {
            task_list = current_task->next;
        } else {
            previous_task->next = current_task->next;
        }
        free(highest_priority_task);
    }
}

int main() {
    // Add some tasks to the task list
    add_task(1, 1, 0, 3);
    add_task(2, 2, 1, 5);
    add_task(3, 1, 2, 2);
    add_task(4, 3, 3, 4);
    add_task(5, 2, 4, 1);
    // Print the task list
    print_task_list();
    // Schedule and execute the tasks
    schedule_tasks();
    return 0;
}