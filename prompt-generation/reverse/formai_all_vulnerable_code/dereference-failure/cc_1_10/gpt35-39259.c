//FormAI DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct task {
    int id;        // ID of task
    int priority;  // Priority of task
    int time;      // Time it takes to complete task
    struct task *next;  // Link to next task in queue
};

// Function to generate a random task
struct task *generate_task(int id) {
    struct task *t = malloc(sizeof(struct task));
    t->id = id;
    t->priority = rand() % 10;
    t->time = rand() % 5 + 1;
    t->next = NULL;
    return t;
}

// Function to add task to the end of the queue
void enqueue(struct task **queue, struct task *t) {
    if (*queue == NULL) {
        *queue = t;
    } else {
        struct task *ptr = *queue;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = t;
    }
}

// Function to remove task from the front of the queue
struct task *dequeue(struct task **queue) {
    struct task *t = *queue;
    if (t != NULL) {
        *queue = t->next;
    }
    return t;
}

// Function to print queue
void print_queue(struct task *queue) {
    printf("Task Queue:\n");
    while (queue != NULL) {
        printf(" Task %d (priority %d, time %d)\n", queue->id, queue->priority, queue->time);
        queue = queue->next;
    }
    printf("\n");
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create queue
    struct task *queue = NULL;

    // Generate 10 tasks and add them to queue
    for (int i = 1; i <= 10; i++) {
        struct task *t = generate_task(i);
        enqueue(&queue, t);
    }

    // Print initial queue
    print_queue(queue);

    // Run task scheduler
    printf("Running tasks:\n");
    while (queue != NULL) {
        // Get highest priority task
        struct task *current = queue;
        struct task *highest = queue;
        while (current != NULL) {
            if (current->priority > highest->priority) {
                highest = current;
            }
            current = current->next;
        }

        // Execute task
        printf(" Task %d (priority %d, time %d) is running\n", highest->id, highest->priority, highest->time);
        highest->time--;
        if (highest->time == 0) {
            dequeue(&queue);
            printf("  Task %d (priority %d) is complete\n", highest->id, highest->priority);
        } else {
            // Re-add task to end of queue with updated priority
            highest->priority = rand() % 10;
            struct task *next = highest->next;
            highest->next = NULL;
            enqueue(&queue, highest);
            highest->next = next;
        }

        // Print updated queue
        print_queue(queue);
    }

    return 0;
}