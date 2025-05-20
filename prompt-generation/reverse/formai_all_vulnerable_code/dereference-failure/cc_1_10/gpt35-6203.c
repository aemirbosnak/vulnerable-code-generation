//FormAI DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define task struct
typedef struct {
    int id;
    char* name;
    int execute_time;
} task;

// define node struct for linked list
typedef struct node {
    task* task_data;
    struct node* next;
} node;

// function to create new task
task* create_task(int task_id, char* task_name, int execute_time) {
    task* new_task = malloc(sizeof(task));
    new_task->id = task_id;
    new_task->name = task_name;
    new_task->execute_time = execute_time;
    return new_task;
}

// function to create new node
node* create_node(task* task_data) {
    node* new_node = malloc(sizeof(node));
    new_node->task_data = task_data;
    new_node->next = NULL;
    return new_node;
}

// function to add new task to linked list
void add_task(node** head, task* new_task) {
    node* current = *head;
    if (current == NULL) {
        *head = create_node(new_task);
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(new_task);
}

// function to print all the tasks in linked list
void print_tasks(node** head) {
    node* current = *head;
    while (current != NULL) {
        printf("Task ID: %d | Name: %s | Execute Time: %d seconds\n", current->task_data->id, current->task_data->name, current->task_data->execute_time);
        current = current->next;
    }
}

// main function
int main() {
    // seeding random number generator
    srand(time(NULL));
    
    // initializing linked list
    node* head = NULL;
    
    // adding tasks to linked list
    task* task1 = create_task(1, "Send Email", 2);
    add_task(&head, task1);
    
    task* task2 = create_task(2, "Scrape Website", 4);
    add_task(&head, task2);
    
    task* task3 = create_task(3, "Backup Database", 8);
    add_task(&head, task3);
    
    // printing all tasks in linked list
    printf("Scheduled Tasks:\n");
    print_tasks(&head);
    
    // simulate task scheduler
    printf("\nRunning task scheduler...\n\n");
    while (head != NULL) {
        node* current = head;
        int total_time = 0;
        while (current != NULL) {
            total_time += current->task_data->execute_time;
            current = current->next;
        }
        int random_execution_time = rand() % (total_time + 1);
        current = head;
        while (random_execution_time > current->task_data->execute_time) {
            random_execution_time -= current->task_data->execute_time;
            current = current->next;
        }
        printf("Executing task: %s | Execution Time: %d seconds\n", current->task_data->name, current->task_data->execute_time);
        head = current->next;
        free(current->task_data);
        free(current);
        printf("Task complete!\n\n");
    }
    
    printf("All tasks completed.\n");
    
    return 0;
}