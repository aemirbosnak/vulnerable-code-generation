//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Time unit: 500 milliseconds
#define TIME_UNIT 500

// Task structure
typedef struct task {
    int id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    int priority;
} task;

// Queue node structure
typedef struct node {
    task data;
    struct node *next;
} node;

// Queue structure
typedef struct queue {
    node *head;
    node *tail;
} queue;

// Function to initialize a queue
queue *init_queue() {
    queue *q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

// Function to enqueue a task in a queue
void enqueue(queue *q, task *t) {
    node *new_node = malloc(sizeof(node));
    new_node->data = *t;
    new_node->next = NULL;

    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

// Function to dequeue a task from a queue
task *dequeue(queue *q) {
    if (q->head == NULL) {
        return NULL;
    }

    task *t = &q->head->data;
    node *temp = q->head;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return t;
}

// Function to sort the queue based on priority
void sort_queue(queue *q) {
    node *curr = q->head;
    node *prev = NULL;

    while (curr != NULL) {
        node *min = curr;
        node *min_prev = prev;

        for (node *i = curr->next; i != NULL; i = i->next) {
            if (i->data.priority < min->data.priority) {
                min = i;
                min_prev = i->next;
            }
        }

        if (min != curr) {
            if (prev == NULL) {
                q->head = min;
            } else {
                min_prev->next = min;
            }

            curr->next = min->next;
            min->next = curr;

            if (curr == q->tail) {
                q->tail = min;
            }
        }

        prev = curr;
        curr = curr->next;
    }
}

// Function to simulate the execution of tasks in a time-based manner
void simulate(queue *q) {
    int time = 0;

    while (q->head != NULL) {
        task *t = dequeue(q);

        // Execute the task for the remaining time
        while (t->remaining_time > 0) {
            printf("[Time %d] Executing task %d with priority %d\n", time, t->id, t->priority);
            sleep(TIME_UNIT);
            time += TIME_UNIT;
            t->remaining_time -= TIME_UNIT;
        }

        // Task is completed
        printf("[Time %d] Task %d completed\n", time, t->id);
    }
}

int main() {
    // Create a queue of tasks
    queue *q = init_queue();

    // Add tasks to the queue
    task t1 = {1, 0, 10, 10, 5};
    enqueue(q, &t1);
    task t2 = {2, 5, 5, 5, 10};
    enqueue(q, &t2);
    task t3 = {3, 10, 15, 15, 1};
    enqueue(q, &t3);

    // Sort the queue based on priority
    sort_queue(q);

    // Simulate the execution of tasks
    simulate(q);

    return 0;
}