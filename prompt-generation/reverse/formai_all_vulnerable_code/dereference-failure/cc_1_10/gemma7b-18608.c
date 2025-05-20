//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NR_CORES 4

struct task {
    int id;
    char name[20];
    int cpu_time;
    struct task* next;
};

struct task* head = NULL;

void schedule_task() {
    struct task* current_task = head;
    int current_core = 0;

    while (current_task) {
        // Calculate the next available core for the task
        int next_core = (current_core + 1) % NR_CORES;

        // If the core is available, execute the task
        if (current_task->cpu_time > 0) {
            printf("Task %d is running on core %d\n", current_task->id, next_core);
            current_task->cpu_time--;
        } else {
            // Move to the next task
            current_task = current_task->next;
        }
    }

    sleep(1);
}

int main() {
    // Create a few tasks
    struct task* task1 = malloc(sizeof(struct task));
    task1->id = 1;
    strcpy(task1->name, "Task 1");
    task1->cpu_time = 5;

    struct task* task2 = malloc(sizeof(struct task));
    task2->id = 2;
    strcpy(task2->name, "Task 2");
    task2->cpu_time = 3;

    struct task* task3 = malloc(sizeof(struct task));
    task3->id = 3;
    strcpy(task3->name, "Task 3");
    task3->cpu_time = 2;

    head = task1;
    task1->next = task2;
    task2->next = task3;

    // Schedule the tasks
    while (1) {
        schedule_task();
    }

    return 0;
}