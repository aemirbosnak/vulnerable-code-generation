//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdlib.h>
#include <stdio.h>

// A task is represented as a structure with a priority and a burst time
struct Task {
    int priority;
    int burst_time;
};

// A queue is represented as a linked list of tasks
struct QueueNode {
    struct Task task;
    struct QueueNode *next;
};

// Create a new task
struct Task *createTask(int priority, int burst_time) {
    struct Task *task = malloc(sizeof(struct Task));
    task->priority = priority;
    task->burst_time = burst_time;
    return task;
}

// Create a new queue
struct QueueNode *createQueue() {
    struct QueueNode *queue = malloc(sizeof(struct QueueNode));
    queue->next = NULL;
    return queue;
}

// Enqueue a task into the queue
void enqueue(struct QueueNode *queue, struct Task *task) {
    struct QueueNode *new_node = malloc(sizeof(struct QueueNode));
    new_node->task = *task;
    new_node->next = queue->next;
    queue->next = new_node;
}

// Dequeue a task from the queue
struct Task *dequeue(struct QueueNode *queue) {
    if (queue->next == NULL) {
        return NULL;
    }
    struct QueueNode *temp = queue->next;
    queue->next = temp->next;
    struct Task *task = malloc(sizeof(struct Task));
    task->priority = temp->task.priority;
    task->burst_time = temp->task.burst_time;
    free(temp);
    return task;
}

// Check if the queue is empty
int isQueueEmpty(struct QueueNode *queue) {
    return queue->next == NULL;
}

// Print the queue
void printQueue(struct QueueNode *queue) {
    struct QueueNode *temp = queue->next;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->task.priority, temp->task.burst_time);
        temp = temp->next;
    }
    printf("\n");
}

// Get the number of tasks in the queue
int getQueueSize(struct QueueNode *queue) {
    int size = 0;
    struct QueueNode *temp = queue->next;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

// Schedule tasks using the Round Robin algorithm
void roundRobin(struct QueueNode *queue, int time_quantum) {
    int time = 0;
    while (!isQueueEmpty(queue)) {
        struct Task *task = dequeue(queue);
        if (task->burst_time <= time_quantum) {
            time += task->burst_time;
            printf("Task (%d, %d) completed at time %d\n", task->priority, task->burst_time, time);
        } else {
            task->burst_time -= time_quantum;
            enqueue(queue, task);
            time += time_quantum;
        }
    }
}

// Schedule tasks using the Priority algorithm
void priority(struct QueueNode *queue) {
    int time = 0;
    while (!isQueueEmpty(queue)) {
        struct Task *task = dequeue(queue);
        time += task->burst_time;
        printf("Task (%d, %d) completed at time %d\n", task->priority, task->burst_time, time);
    }
}

// Schedule tasks using the Shortest Job First algorithm
void sjf(struct QueueNode *queue) {
    int time = 0;
    while (!isQueueEmpty(queue)) {
        struct Task *task = dequeue(queue);
        time += task->burst_time;
        printf("Task (%d, %d) completed at time %d\n", task->priority, task->burst_time, time);
    }
}

// Main function
int main() {
    // Create a queue of tasks
    struct QueueNode *queue = createQueue();

    // Add tasks to the queue
    enqueue(queue, createTask(1, 5));
    enqueue(queue, createTask(2, 3));
    enqueue(queue, createTask(3, 1));
    enqueue(queue, createTask(4, 2));

    // Print the queue
    printf("Initial queue: ");
    printQueue(queue);

    // Schedule tasks using the Round Robin algorithm
    roundRobin(queue, 2);

    // Print the queue
    printf("Round Robin: ");
    printQueue(queue);

    // Schedule tasks using the Priority algorithm
    priority(queue);

    // Print the queue
    printf("Priority: ");
    printQueue(queue);

    // Schedule tasks using the Shortest Job First algorithm
    sjf(queue);

    // Print the queue
    printf("Shortest Job First: ");
    printQueue(queue);

    return 0;
}