//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A structure to represent a task
typedef struct task {
    int id;             // The ID of the task
    int arrival_time;  // The time at which the task arrives
    int service_time;  // The time required to service the task
} task;

// A structure to represent a task queue
typedef struct task_queue {
    task *tasks;      // An array of tasks
    int num_tasks;    // The number of tasks in the queue
    int head;         // The index of the first task in the queue
    int tail;         // The index of the last task in the queue
} task_queue;

// Create a new task queue
task_queue *create_task_queue() {
    task_queue *queue = (task_queue *)malloc(sizeof(task_queue));
    queue->tasks = (task *)malloc(100 * sizeof(task));
    queue->num_tasks = 0;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

// Add a task to the queue
void enqueue_task(task_queue *queue, task *t) {
    queue->tasks[queue->tail] = *t;
    queue->tail = (queue->tail + 1) % 100;
    queue->num_tasks++;
}

// Remove a task from the queue
task *dequeue_task(task_queue *queue) {
    if (queue->num_tasks == 0) {
        return NULL;
    }
    task *t = &queue->tasks[queue->head];
    queue->head = (queue->head + 1) % 100;
    queue->num_tasks--;
    return t;
}

// Get the number of tasks in the queue
int get_num_tasks(task_queue *queue) {
    return queue->num_tasks;
}

// Get the average arrival time of the tasks in the queue
double get_avg_arrival_time(task_queue *queue) {
    double avg_arrival_time = 0;
    for (int i = 0; i < queue->num_tasks; i++) {
        avg_arrival_time += queue->tasks[i].arrival_time;
    }
    avg_arrival_time /= queue->num_tasks;
    return avg_arrival_time;
}

// Get the average service time of the tasks in the queue
double get_avg_service_time(task_queue *queue) {
    double avg_service_time = 0;
    for (int i = 0; i < queue->num_tasks; i++) {
        avg_service_time += queue->tasks[i].service_time;
    }
    avg_service_time /= queue->num_tasks;
    return avg_service_time;
}

// Get the total time required to service all the tasks in the queue
int get_total_service_time(task_queue *queue) {
    int total_service_time = 0;
    for (int i = 0; i < queue->num_tasks; i++) {
        total_service_time += queue->tasks[i].service_time;
    }
    return total_service_time;
}

// Create a new task
task *create_task(int id, int arrival_time, int service_time) {
    task *t = (task *)malloc(sizeof(task));
    t->id = id;
    t->arrival_time = arrival_time;
    t->service_time = service_time;
    return t;
}

// Print the tasks in the queue
void print_tasks(task_queue *queue) {
    for (int i = 0; i < queue->num_tasks; i++) {
        printf("Task %d: arrives at %d, service time %d\n", queue->tasks[i].id, queue->tasks[i].arrival_time, queue->tasks[i].service_time);
    }
}

// Simulate the execution of the tasks in the queue
void simulate_task_execution(task_queue *queue) {
    int current_time = 0;
    int completed_tasks = 0;
    int total_service_time = get_total_service_time(queue);

    while (completed_tasks < total_service_time) {
        // Get the next task to be executed
        task *t = dequeue_task(queue);
        if (t == NULL) {
            break;
        }

        // Execute the task
        current_time += t->service_time;
        completed_tasks += t->service_time;

        // Print the task execution statistics
        printf("Task %d completed at time %d\n", t->id, current_time);
    }
}

// Main function
int main() {
    // Create a task queue
    task_queue *queue = create_task_queue();

    // Add tasks to the queue
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int arrival_time = rand() % 100;
        int service_time = rand() % 100;
        task *t = create_task(i, arrival_time, service_time);
        enqueue_task(queue, t);
    }

    // Print the tasks in the queue
    print_tasks(queue);

    // Simulate the execution of the tasks in the queue
    simulate_task_execution(queue);

    // Get the average arrival time of the tasks in the queue
    double avg_arrival_time = get_avg_arrival_time(queue);

    // Get the average service time of the tasks in the queue
    double avg_service_time = get_avg_service_time(queue);

    // Print the average arrival time and service time of the tasks in the queue
    printf("Average arrival time: %.2f\n", avg_arrival_time);
    printf("Average service time: %.2f\n", avg_service_time);

    return 0;
}