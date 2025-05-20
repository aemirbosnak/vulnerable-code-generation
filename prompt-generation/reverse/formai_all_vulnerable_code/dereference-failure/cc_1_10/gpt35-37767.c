//FormAI DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Define a Task struct to hold important task information */
typedef struct {
    int id;
    int priority;
    int time_required;
    int time_left;
} Task;

/* Define a SchedulerQueue struct to hold a linked list of tasks */
typedef struct SchedulerQueue {
    Task task;
    struct SchedulerQueue* next;
} SchedulerQueue;

/* Function to add a task to the SchedulerQueue linked list, given the head of the list */
void add_task(SchedulerQueue** head, Task task) {
    /* Create a new SchedulerQueue node */
    SchedulerQueue* new_node = (SchedulerQueue*) malloc(sizeof(SchedulerQueue));
    new_node->task = task;
    new_node->next = NULL;
    
    /* If the list is empty, set the head */
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    /* Find the end of the list and add the new node */
    SchedulerQueue* current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

/* Function to remove a task from the SchedulerQueue linked list, given the head of the list */
void remove_task(SchedulerQueue** head, int id) {
    /* If the list is empty, do nothing */
    if (*head == NULL) {
        return;
    }
    
    /* If the task to remove is the head of the list */
    if ((*head)->task.id == id) {
        SchedulerQueue* temp_node = *head;
        *head = (*head)->next;
        free(temp_node);
        return;
    }
    
    /* Search for the task to remove and remove it */
    SchedulerQueue* current_node = *head;
    while (current_node->next != NULL && current_node->next->task.id != id) {
        current_node = current_node->next;
    }
    if (current_node->next != NULL) {
        SchedulerQueue* temp_node = current_node->next;
        current_node->next = temp_node->next;
        free(temp_node);
    }
}

/* Function to print the tasks currently in the SchedulerQueue linked list */
void print_tasks(SchedulerQueue* head) {
    printf("|----------------------------|\n");
    printf("| ID | Priority | Time Left |\n");
    printf("|----------------------------|\n");
    SchedulerQueue* current_node = head;
    while (current_node != NULL) {
        printf("| %2d |    %3d   |    %3d    |\n", current_node->task.id, current_node->task.priority, current_node->task.time_left);
        current_node = current_node->next;
    }
    printf("|----------------------------|\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    /* Generate some tasks with random priorities and time requirements */
    Task task1 = { .id = 1, .priority = rand() % 100, .time_required = rand() % 30 + 1, .time_left = task1.time_required };
    Task task2 = { .id = 2, .priority = rand() % 100, .time_required = rand() % 30 + 1, .time_left = task1.time_required };
    Task task3 = { .id = 3, .priority = rand() % 100, .time_required = rand() % 30 + 1, .time_left = task1.time_required };
    Task task4 = { .id = 4, .priority = rand() % 100, .time_required = rand() % 30 + 1, .time_left = task1.time_required };
    Task task5 = { .id = 5, .priority = rand() % 100, .time_required = rand() % 30 + 1, .time_left = task1.time_required };
    
    /* Add the tasks to the SchedulerQueue */
    SchedulerQueue* head = NULL;
    add_task(&head, task1);
    add_task(&head, task2);
    add_task(&head, task3);
    add_task(&head, task4);
    add_task(&head, task5);
    
    /* Simulate the execution of tasks until all tasks are complete */
    int time = 0;
    while (head != NULL) {
        printf("Time: %d\n", time);
        
        /* Print the current tasks in the SchedulerQueue */
        print_tasks(head);
        
        /* Find the highest priority task that still needs to be executed */
        SchedulerQueue* current_node = head;
        Task* highest_priority_task = NULL;
        while (current_node != NULL) {
            if (current_node->task.time_left > 0) {
                if (highest_priority_task == NULL || current_node->task.priority > highest_priority_task->priority) {
                    highest_priority_task = &(current_node->task);
                }
            }
            current_node = current_node->next;
        }
        
        /* Subtract one second from the time left for the highest priority task */
        if (highest_priority_task != NULL) {
            highest_priority_task->time_left--;
        }
        
        /* Remove any tasks that are complete */
        current_node = head;
        while (current_node != NULL) {
            if (current_node->task.time_left == 0) {
                printf("Task %d complete.\n", current_node->task.id);
                remove_task(&head, current_node->task.id);
            }
            current_node = current_node->next;
        }
        
        /* Increment the time */
        time++;
        printf("\n");
    }
    
    printf("All tasks complete.\n");
    
    return 0;
}