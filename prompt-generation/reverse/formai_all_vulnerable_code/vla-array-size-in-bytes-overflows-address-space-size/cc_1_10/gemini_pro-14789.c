//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
// Join the CPU Carnival and Let the Tasks Dance!

#include <stdio.h>
#include <stdlib.h>

// Task struct for our lively dance partners
typedef struct Task {
    int arrivalTime;    // When the task arrives at the CPU soirée
    int burstTime;     // How long the task wants to boogie for
    int priority;      // Importance factor (higher = more important)
} Task;

// Main function: The CPU Hype Zone
int main() {
    // Gather a crowd of tasks (up to 100)
    int numTasks;
    printf("Welcome to the CPU Carnival! How many tasks want to join the fun (max 100): ");
    scanf("%d", &numTasks);
    Task tasks[numTasks];

    // Let's get to know our dance partners
    printf("Tell us about your tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Task %d\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &tasks[i].arrivalTime);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burstTime);
        printf("Priority (higher = more important!): ");
        scanf("%d", &tasks[i].priority);
    }

    // Time to choose our scheduling algorithm: FCFS (First Come, First Served) or Priority
    int choice;
    printf("Pick your scheduling groove:\n1. FCFS (First Come, First Served)\n2. Priority (Higher priority gets served first)\nYour choice: ");
    scanf("%d", &choice);

    // FCFS: Let's do this in the order they arrived
    if (choice == 1) {
        int currentTime = 0;
        printf("FCFS Scheduling:\n");
        for (int i = 0; i < numTasks; i++) {
            printf("Task %d, arriving at %d, starts at %d and ends at %d\n", i + 1, tasks[i].arrivalTime, currentTime, currentTime + tasks[i].burstTime);
            currentTime += tasks[i].burstTime;
        }
    } 

    // Priority: Important tasks get served first
    else if (choice == 2) {
        // Sort tasks by priority (descending order)
        for (int i = 0; i < numTasks; i++) {
            for (int j = i + 1; j < numTasks; j++) {
                if (tasks[i].priority < tasks[j].priority) {
                    Task temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }

        int currentTime = 0;
        printf("Priority Scheduling:\n");
        for (int i = 0; i < numTasks; i++) {
            printf("Task %d, arriving at %d, starts at %d and ends at %d\n", i + 1, tasks[i].arrivalTime, currentTime, currentTime + tasks[i].burstTime);
            currentTime += tasks[i].burstTime;
        }
    } 

    // Invalid choice: Let's throw some glitter
    else {
        printf("Oops! That's not a valid dance move. Let's just sparkle and have fun!");
    }

    return 0;
}