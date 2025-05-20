//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// declare the Task struct
typedef struct Task {
    int id;
    int priority;
    time_t timestamp;
    void (*execute)();
} Task;

// declare the ScheduleNode struct
typedef struct ScheduleNode {
    Task* task;
    struct ScheduleNode* next;
} ScheduleNode;

// declare the Scheduler struct
typedef struct Scheduler {
    ScheduleNode* head;
    ScheduleNode* tail;
    int length;
    bool isExecuting;
} Scheduler;

// function to create a new Task
Task* newTask(int id, int priority, time_t timestamp, void (*execute)()) {
    Task* task = malloc(sizeof(Task));
    task->id = id;
    task->priority = priority;
    task->timestamp = timestamp;
    task->execute = execute;
    return task;
}

// function to create a new ScheduleNode
ScheduleNode* newScheduleNode(Task* task) {
    ScheduleNode* node = malloc(sizeof(ScheduleNode));
    node->task = task;
    node->next = NULL;
    return node;
}

// function to create a new Scheduler
Scheduler* newScheduler() {
    Scheduler* scheduler = malloc(sizeof(Scheduler));
    scheduler->head = NULL;
    scheduler->tail = NULL;
    scheduler->length = 0;
    scheduler->isExecuting = false;
    return scheduler;
}

// function to add a Task to the Scheduler
void addTask(Scheduler* scheduler, Task* task) {
    ScheduleNode* node = newScheduleNode(task);
    if (scheduler->head == NULL) {
        scheduler->head = node;
        scheduler->tail = node;
    } else {
        ScheduleNode* temp = scheduler->head;
        ScheduleNode* prev = NULL;
        while (temp != NULL && temp->task->priority >= task->priority) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            node->next = scheduler->head;
            scheduler->head = node;
        } else {
            node->next = temp;
            prev->next = node;
        }
        if (node->next == NULL) {
            scheduler->tail = node;
        }
    }
    scheduler->length++;
}

// function to remove and return the highest priority Task from the Scheduler
Task* getNextTask(Scheduler* scheduler) {
    if (scheduler->head == NULL) {
        return NULL;
    }
    ScheduleNode* temp = scheduler->head;
    scheduler->head = scheduler->head->next;
    if (scheduler->head == NULL) {
        scheduler->tail = NULL;
    }
    Task* task = temp->task;
    free(temp);
    scheduler->length--;
    return task;
}

// function to execute a Task
void executeTask(Task* task) {
    printf("Executing Task %d\n", task->id);
    task->execute();
}

// function to start executing Tasks in the Scheduler
void startExecution(Scheduler* scheduler) {
    scheduler->isExecuting = true;
    while (scheduler->isExecuting && scheduler->head != NULL) {
        Task* task = getNextTask(scheduler);
        executeTask(task);
        free(task);
    }
}

// function to stop executing Tasks in the Scheduler
void stopExecution(Scheduler* scheduler) {
    scheduler->isExecuting = false;
}

// sample Task execution functions
void task1() {
    printf("Task 1 is complete\n");
}

void task2() {
    printf("Task 2 is complete\n");
}

void task3() {
    printf("Task 3 is complete\n");
}

int main() {
    // create the Scheduler
    Scheduler* scheduler = newScheduler();
    
    // create some sample Tasks
    Task* task1 = newTask(1, 3, time(NULL), &task1);
    Task* task2 = newTask(2, 2, time(NULL), &task2);
    Task* task3 = newTask(3, 1, time(NULL), &task3);
    
    // add the Tasks to the Scheduler
    addTask(scheduler, task1);
    addTask(scheduler, task2);
    addTask(scheduler, task3);
    
    // start executing the Tasks in the Scheduler
    startExecution(scheduler);
    
    // clean up
    free(scheduler);
    
    return 0;
}