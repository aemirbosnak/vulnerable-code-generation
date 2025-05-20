//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a task with a deadline and profit
typedef struct {
    int id;         // Task ID
    int deadline;   // Deadline for the task
    int profit;     // Profit of completing the task
} Task;

// Comparison function to sort tasks by profit in descending order
int compare(const void *a, const void *b) {
    return ((Task *)b)->profit - ((Task *)a)->profit;
}

// Function to perform the job scheduling
void jobScheduling(Task tasks[], int n) {
    // Sort the tasks by profit
    qsort(tasks, n, sizeof(Task), compare);

    // Create an array to keep track of free time slots
    int result[n]; // Resultant array to store job IDs
    int timeSlot[n]; // To keep track of free time slots
    for (int i = 0; i < n; i++) {
        timeSlot[i] = 0; // Initialize all time slots as free
    }

    // Iterate through all tasks
    for (int i = 0; i < n; i++) {
        // Find a time slot for this task (from its deadline to 1)
        for (int j = (tasks[i].deadline < n ? tasks[i].deadline : n); j > 0; j--) {
            if (timeSlot[j] == 0) { // If the time slot is free
                timeSlot[j] = 1; // Mark the slot as filled
                result[j] = tasks[i].id; // Store the job ID
                break;
            }
        }
    }

    // Print the result
    printf("Scheduled Jobs:\n");
    for (int i = 1; i < n; i++) {
        if (result[i] != 0) {
            printf("Job ID: %d\n", result[i]);
        }
    }
}

// Main function to drive the program
int main() {
    int n;

    // Enter the number of tasks
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    Task *tasks = (Task *)malloc(n * sizeof(Task)); // Dynamically allocate memory for tasks

    // Enter the task details
    for (int i = 0; i < n; i++) {
        printf("Enter task ID, deadline and profit for Task %d: ", i + 1);
        scanf("%d %d %d", &tasks[i].id, &tasks[i].deadline, &tasks[i].profit);
    }

    // Perform job scheduling using greedy algorithm
    jobScheduling(tasks, n);
    
    // Free the allocated memory
    free(tasks);
    
    return 0;
}