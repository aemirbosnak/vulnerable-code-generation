//FormAI DATASET v1.0 Category: Task Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 20

typedef struct {
    int task_id;
    char task_name[30];
    int priority;
    int duration;
    int time_remaining;
    time_t start_time;
    time_t end_time;
} Task;

Task **task_list;
int num_tasks = 0;

void add_task() {
    if(num_tasks == MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    Task *new_task = (Task*) malloc(sizeof(Task));
    new_task->task_id = num_tasks;
    printf("Enter task name: ");
    scanf("%s", new_task->task_name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &new_task->priority);
    printf("Enter task duration (in minutes): ");
    scanf("%d", &new_task->duration);
    new_task->time_remaining = new_task->duration;
    new_task->start_time = 0;
    new_task->end_time = 0;
    task_list[num_tasks] = new_task;
    num_tasks++;
}

void remove_task(int task_id) {
    if(task_id >= num_tasks) {
        printf("Invalid task id!\n");
        return;
    }
    free(task_list[task_id]);
    for(int i = task_id; i < num_tasks-1; i++) {
        task_list[i] = task_list[i+1];
        task_list[i]->task_id--;
    }
    num_tasks--;
    printf("Task removed successfully!\n");
}

void display_tasks() {
    printf("\nTask List\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("| Task ID | Task Name                | Priority | Duration | Time Remaining | Status |\n");
    printf("------------------------------------------------------------------------------------\n");
    for(int i = 0; i < num_tasks; i++) {
        char status[30] = "Not Started";
        if(task_list[i]->start_time != 0) {
            strcpy(status, "In Progress");
            if(task_list[i]->time_remaining == 0)
                strcpy(status, "Completed");
        }
        printf("| %7d | %-24s | %8d | %8d | %14d | %-13s |\n", task_list[i]->task_id, task_list[i]->task_name, task_list[i]->priority,
                    task_list[i]->duration, task_list[i]->time_remaining, status);
    }
    printf("------------------------------------------------------------------------------------\n");
}

void start_task(int task_id) {
    if(task_id >= num_tasks) {
        printf("Invalid task id!\n");
        return;
    }
    if(task_list[task_id]->start_time != 0) {
        printf("Task has already started!\n");
        return;
    }
    time(&task_list[task_id]->start_time);
    printf("Task started successfully!\n");
}

void update_task_status() {
    for(int i = 0; i < num_tasks; i++) {
        if(task_list[i]->start_time != 0) {
            time_t current_time;
            time(&current_time);
            int elapsed_time = (int) (current_time - task_list[i]->start_time) / 60;
            task_list[i]->time_remaining = task_list[i]->duration - elapsed_time;
            if(task_list[i]->time_remaining == 0) {
                task_list[i]->end_time = current_time;
            }
        }
    }
}

void display_task_statistics() {
    int total_tasks = num_tasks;
    int total_time = 0;
    int completed_tasks = 0;
    int in_progress_tasks = 0;
    for(int i = 0; i < num_tasks; i++) {
        if(task_list[i]->start_time != 0) {
            if(task_list[i]->time_remaining == 0)
                completed_tasks++;
            else
                in_progress_tasks++;
            total_time += task_list[i]->duration;
        }
    }
    printf("\nTask Statistics\n");
    printf("-------------------------------------------------------\n");
    printf("| Total Tasks | Total Time | Completed Tasks | In Progress Tasks |\n");
    printf("-------------------------------------------------------\n");
    printf("| %11d | %10d | %15d | %18d |\n", total_tasks, total_time, completed_tasks, in_progress_tasks);
    printf("-------------------------------------------------------\n");
}

void sort_tasks_by_priority() {
    for(int i = 0; i < num_tasks-1; i++) {
        for(int j = 0; j < num_tasks-i-1; j++) {
            if(task_list[j]->priority < task_list[j+1]->priority) {
                Task *temp = task_list[j];
                task_list[j] = task_list[j+1];
                task_list[j+1] = temp;
            }
        }
    }
    printf("Task list sorted by priority!\n");
}

int main() {
    task_list = (Task**) malloc(MAX_TASKS * sizeof(Task*));
    int choice, task_id;
    do {
        printf("\n-------------------\nTask Scheduler Menu\n-------------------\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Start Task\n");
        printf("5. Display Task Statistics\n");
        printf("6. Sort Tasks by Priority\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_task();
                break;
            case 2:
                printf("Enter task id: ");
                scanf("%d", &task_id);
                remove_task(task_id);
                break;
            case 3:
                update_task_status();
                display_tasks();
                break;
            case 4:
                printf("Enter task id: ");
                scanf("%d", &task_id);
                start_task(task_id);
                break;
            case 5:
                update_task_status();
                display_task_statistics();
                break;
            case 6:
                sort_tasks_by_priority();
                break;
            case 7:
                printf("Exiting Task Scheduler...");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 7);
    for(int i = 0; i < num_tasks; i++)
        free(task_list[i]);
    free(task_list);
    return 0;
}