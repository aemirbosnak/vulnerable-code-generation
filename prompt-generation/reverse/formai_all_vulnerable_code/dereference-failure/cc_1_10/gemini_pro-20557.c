//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
// Watson, we must plan meticulously to apprehend the elusive Professor Moriarty. Our task scheduler will be our trusty ally in this endeavor.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A task representing a clue or lead in our investigation.
typedef struct {
    char* description;
    int priority;
    int deadline;
} Task;

// Our task scheduler, a veritable Swiss Army knife for our investigations.
typedef struct {
    Task* tasks;
    int numTasks;
    int capacity;
} TaskScheduler;

// Invoke the great detective's keen eye to create a new task scheduler.
TaskScheduler* createTaskScheduler() {
    TaskScheduler* scheduler = (TaskScheduler*)malloc(sizeof(TaskScheduler));
    scheduler->tasks = NULL;
    scheduler->numTasks = 0;
    scheduler->capacity = 0;
    return scheduler;
}

// Add a new clue to our ever-growing list of tasks.
void addTask(TaskScheduler* scheduler, Task task) {
    // Watson, resize our array if necessary.
    if (scheduler->numTasks == scheduler->capacity) {
        scheduler->capacity *= 2;
        scheduler->tasks = (Task*)realloc(scheduler->tasks, scheduler->capacity * sizeof(Task));
    }

    scheduler->tasks[scheduler->numTasks++] = task;
}

// Sort our tasks in descending order of priority using the meticulous methods of a true detective.
void sortTasks(TaskScheduler* scheduler) {
    for (int i = 0; i < scheduler->numTasks - 1; i++) {
        for (int j = i + 1; j < scheduler->numTasks; j++) {
            if (scheduler->tasks[i].priority < scheduler->tasks[j].priority) {
                Task temp = scheduler->tasks[i];
                scheduler->tasks[i] = scheduler->tasks[j];
                scheduler->tasks[j] = temp;
            }
        }
    }
}

// Execute the tasks in order of priority, ensuring the most urgent clues are addressed promptly.
void executeTasks(TaskScheduler* scheduler) {
    for (int i = 0; i < scheduler->numTasks; i++) {
        printf("Investigating clue: %s\n", scheduler->tasks[i].description);
    }
}

// The grand finale, where our meticulous planning comes to fruition and Moriarty's schemes are laid bare.
int main() {
    // Watson, let us create our task scheduler.
    TaskScheduler* scheduler = createTaskScheduler();

    // Add our first clue, a mysterious cipher found in a secret meeting place.
    Task cipherClue = {"Decipher the enigmatic cipher found at the Diogenes Club", 10, 3};
    addTask(scheduler, cipherClue);

    // Another clue emerges, a coded message intercepted from Moriarty's henchmen.
    Task codedMessageClue = {"Intercept and decode the coded message from the Pinkerton thugs", 8, 5};
    addTask(scheduler, codedMessageClue);

    // A third clue, a witness sighting of Moriarty himself at a clandestine gathering.
    Task witnessSightingClue = {"Track down and interview the elusive witness who claims to have seen Moriarty", 7, 2};
    addTask(scheduler, witnessSightingClue);

    // Time is of the essence, Watson. Let us sort our tasks by priority.
    sortTasks(scheduler);

    // Execute the tasks, one by one, until Moriarty's web of deception is unravelled.
    executeTasks(scheduler);

    printf("\nElementary, my dear Watson. Moriarty's nefarious plot has been thwarted, thanks to our meticulous task scheduling.");
    return 0;
}