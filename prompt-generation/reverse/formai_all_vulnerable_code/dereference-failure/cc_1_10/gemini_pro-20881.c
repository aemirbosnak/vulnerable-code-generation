//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task structure
typedef struct Task {
    int id;
    int priority;
    int arrival_time;
    int execution_time;
    int remaining_time;
    int completed;
} Task;

// Task queue
struct Node {
    Task task;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to create a new task
Task create_task(int id, int priority, int arrival_time, int execution_time) {
    Task task;
    task.id = id;
    task.priority = priority;
    task.arrival_time = arrival_time;
    task.execution_time = execution_time;
    task.remaining_time = execution_time;
    task.completed = 0;
    return task;
}

// Function to add a task to the queue
void enqueue(Task task) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->task = task;
    new_node->next = NULL;
    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

// Function to remove a task from the queue
Task dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return create_task(-1, -1, -1, -1);
    }
    Task task = front->task;
    struct Node *temp = front;
    front = front->next;
    free(temp);
    return task;
}

// Function to print the tasks in the queue
void print_queue() {
    struct Node *temp = front;
    while (temp != NULL) {
        printf("Task ID: %d, Priority: %d, Arrival Time: %d, Execution Time: %d, Remaining Time: %d, Completed: %d\n", temp->task.id, temp->task.priority, temp->task.arrival_time, temp->task.execution_time, temp->task.remaining_time, temp->task.completed);
        temp = temp->next;
    }
}

// Function to simulate the task scheduler
void task_scheduler() {
    int current_time = 0;
    while (front != NULL) {
        Task task = dequeue();
        if (task.arrival_time > current_time) {
            current_time = task.arrival_time;
        }
        printf("Executing task %d at time %d\n", task.id, current_time);
        while (task.remaining_time > 0) {
            current_time++;
            task.remaining_time--;
        }
        task.completed = 1;
        print_queue();
    }
}

// Main function
int main() {
    // Create a set of tasks
    Task task1 = create_task(1, 1, 0, 5);
    Task task2 = create_task(2, 2, 2, 3);
    Task task3 = create_task(3, 3, 4, 4);
    Task task4 = create_task(4, 4, 6, 2);
    Task task5 = create_task(5, 5, 8, 1);

    // Add the tasks to the queue
    enqueue(task1);
    enqueue(task2);
    enqueue(task3);
    enqueue(task4);
    enqueue(task5);

    // Print the tasks in the queue
    printf("Tasks in the queue:\n");
    print_queue();

    // Simulate the task scheduler
    task_scheduler();

    return 0;
}