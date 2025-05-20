//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the task
struct task {
    int id;
    int priority;
    int runtime;
};

// Define a struct for the node in the task queue
struct node {
    struct task *data;
    struct node *next;
};

// Define the task queue and its operations
struct node *head = NULL;
struct node *tail = NULL;

void enqueue(struct task *task) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = task;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

struct task* dequeue() {
    if (head == NULL) {
        return NULL;
    } else {
        struct node *temp = head;
        struct task *data = temp->data;
        head = head->next;
        free(temp);
        return data;
    }
}

int isEmpty() {
    return head == NULL;
}

// Define a function to execute a task
void executeTask(struct task *task) {
    printf("Executing task %d...\n", task->id);
    for (int i = 0; i < task->runtime; i++) {
        // Do some work here
    }
    printf("Task %d complete!\n", task->id);
}

// Define a function to schedule the tasks
void scheduleTasks() {
    while (!isEmpty()) {
        struct task *task = dequeue();
        executeTask(task);
        free(task);
    }
}

// Define the main function for testing
int main() {
    // Create some tasks and add them to the queue
    struct task *task1 = (struct task*) malloc(sizeof(struct task));
    task1->id = 1;
    task1->priority = 1;
    task1->runtime = 5;
    enqueue(task1);

    struct task *task2 = (struct task*) malloc(sizeof(struct task));
    task2->id = 2;
    task2->priority = 2;
    task2->runtime = 10;
    enqueue(task2);

    struct task *task3 = (struct task*) malloc(sizeof(struct task));
    task3->id = 3;
    task3->priority = 1;
    task3->runtime = 7;
    enqueue(task3);

    // Schedule and execute the tasks
    scheduleTasks();

    return 0;
}