//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Task {
    char description[100];
    int time; // Time delay before task is executed
} Task;

typedef struct Scheduler {
    Task *tasks;
    int count;
} Scheduler;

Scheduler* createScheduler(int maxTasks) {
    Scheduler *scheduler = malloc(sizeof(Scheduler));
    scheduler->tasks = malloc(maxTasks * sizeof(Task));
    scheduler->count = 0;
    return scheduler;
}

void addTask(Scheduler *scheduler, const char* description, int time) {
    if (scheduler->count < 100) {
        strncpy(scheduler->tasks[scheduler->count].description, description, 99);
        scheduler->tasks[scheduler->count].description[99] = '\0'; // Null-terminate
        scheduler->tasks[scheduler->count].time = time;
        scheduler->count++;
    } else {
        printf("Alas! No more capacity for thy tasks.\n");
    }
}

void executeTasks(Scheduler *scheduler) {
    printf("O! Tasks to be executed, a tale unfolds:\n");
    for (int i = 0; i < scheduler->count; i++) {
        printf("In yonder bloom, task '%s' awaits for %d seconds...\n",
               scheduler->tasks[i].description, scheduler->tasks[i].time);
        sleep(scheduler->tasks[i].time);
        printf("Behold! Task '%s' hath been completed!\n", scheduler->tasks[i].description);
    }
}

void freeScheduler(Scheduler *scheduler) {
    free(scheduler->tasks);
    free(scheduler);
}

int main() {
    int maxTasks = 100;
    Scheduler *scheduler = createScheduler(maxTasks);

    // Adding tasks which symbolize beloved's declarations and duels
    addTask(scheduler, "Romeo professes his undying love to Juliet.", 2);
    addTask(scheduler, "Juliet vows to not be with another.", 3);
    addTask(scheduler, "Tybalt seeks vengeance against Romeo.", 4);
    addTask(scheduler, "The lovers exchange sweet nothings.", 1);
    addTask(scheduler, "Romeo and Juliet sneak away under the moonlight.", 5);
    addTask(scheduler, "The tragic confrontation at the Capulet tomb.", 6);
    
    // Execute the dearly scheduled tasks
    executeTasks(scheduler);
    
    // Free allocated memory
    freeScheduler(scheduler);
    return 0;
}