//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

// A task node represents a task to be executed
// at a certain time interval
struct task_node {
    void (*task)();
    int interval;
    struct task_node* next;
};

// Create a new task node
struct task_node* new_task_node(void (*task)(), int interval) {
    struct task_node* node = (struct task_node*) malloc(sizeof(struct task_node));
    node->task = task;
    node->interval = interval;
    node->next = NULL;
    return node;
}

// The task list is a linked list of task nodes
struct task_list {
    struct task_node* head;
    struct task_node* tail;
};

// Create a new task list
struct task_list* new_task_list() {
    struct task_list* list = (struct task_list*) malloc(sizeof(struct task_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Add a new task to the task list
void add_task(struct task_list* list, void (*task)(), int interval) {
    struct task_node* node = new_task_node(task, interval);
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// The task scheduler keeps track of the current tick count
// and executes tasks at the appropriate intervals
struct task_scheduler {
    int tick_count;
    struct task_list* task_list;
};

// Create a new task scheduler
struct task_scheduler* new_task_scheduler() {
    struct task_scheduler* scheduler = (struct task_scheduler*) malloc(sizeof(struct task_scheduler));
    scheduler->tick_count = 0;
    scheduler->task_list = new_task_list();
    return scheduler;
}

// The task scheduler handler function is called every time
// the timer expires. It updates the tick count and executes
// tasks that are due to run.
void task_scheduler_handler(int signum) {
    struct task_scheduler* scheduler = (struct task_scheduler*) signum;
    scheduler->tick_count++;
    struct task_node* node = scheduler->task_list->head;
    while (node != NULL) {
        if (scheduler->tick_count % node->interval == 0) {
            node->task();
        }
        node = node->next;
    }
}

// Start the task scheduler
void start_task_scheduler(struct task_scheduler* scheduler) {
    struct sigaction sa;
    struct itimerval timer;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &task_scheduler_handler;
    sigaction(SIGALRM, &sa, NULL);
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval = timer.it_value;
    setitimer(ITIMER_REAL, &timer, NULL);
    while (1) {}
}

// Test function 1
void test_function_1() {
    printf("Test function 1 running\n");
}

// Test function 2
void test_function_2() {
    printf("Test function 2 running\n");
}

// Test program main function
int main() {
    struct task_scheduler* scheduler = new_task_scheduler();
    add_task(scheduler->task_list, &test_function_1, 1); // Execute every 1 second
    add_task(scheduler->task_list, &test_function_2, 2); // Execute every 2 seconds
    start_task_scheduler(scheduler);
    return 0;
}