//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task struct
typedef struct {
    char name[20];
    int priority;
    int time;
} Task;

// Function to compare two tasks based on priority
int compare_tasks(const void* a, const void* b) {
    Task* task_a = (Task*)a;
    Task* task_b = (Task*)b;
    return task_a->priority - task_b->priority;
}

// Function to sort tasks based on priority
void sort_tasks(Task* tasks, int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);
}

int main() {
    int num_players, num_tasks;
    
    // Get input from user
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);
    
    // Allocate memory for tasks
    Task* tasks = malloc(sizeof(Task) * num_tasks);
    
    // Get input for tasks from user
    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task name for task %d: ", i + 1);
        scanf("%s", tasks[i].name);
        printf("Enter priority level (1-10) for task %d: ", i + 1);
        scanf("%d", &tasks[i].priority);
        printf("Enter estimated time (in seconds) for task %d: ", i + 1);
        scanf("%d", &tasks[i].time);
    }
    
    // Sort tasks based on priority
    sort_tasks(tasks, num_tasks);
    
    // Initialize player scores and task assignments
    int* player_scores = calloc(num_players, sizeof(int));
    int* task_assignments = calloc(num_tasks, sizeof(int));
    
    // Assign tasks to players
    int current_player = 0;
    for (int i = 0; i < num_tasks; i++) {
        task_assignments[i] = current_player;
        player_scores[current_player] += tasks[i].time;
        current_player = (current_player + 1) % num_players;
    }
    
    // Print task assignments and player scores
    printf("\nTask assignments:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d assigned to Player %d\n", i + 1, task_assignments[i] + 1);
    }
    printf("\nPlayer scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d seconds\n", i + 1, player_scores[i]);
    }
    
    // Free memory
    free(tasks);
    free(player_scores);
    free(task_assignments);
    
    return 0;
}