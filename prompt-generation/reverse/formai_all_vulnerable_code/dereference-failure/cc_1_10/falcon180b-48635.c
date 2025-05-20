//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITIES 10

struct task {
    char name[20];
    int (*function)();
    int priority;
};

int main() {
    int num_tasks = 0;
    struct task *task_list = (struct task *)malloc(MAX_TASKS * sizeof(struct task));

    printf("Welcome to the Retro Task Scheduler!\n");
    printf("How many tasks would you like to schedule? ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task name: ");
        scanf("%s", task_list[i].name);
        printf("Enter task function: ");
        task_list[i].function = (int (*)())malloc(100 * sizeof(int));
        scanf("%p", &task_list[i].function);
        printf("Enter task priority (1-10): ");
        scanf("%d", &task_list[i].priority);
    }

    printf("\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %s has priority %d\n", task_list[i].name, task_list[i].priority);
    }

    int current_task = 0;
    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            if (task_list[i].priority > task_list[current_task].priority) {
                current_task = i;
            }
        }

        task_list[current_task].function();

        for (int i = 0; i < num_tasks; i++) {
            if (i!= current_task && task_list[i].priority == task_list[current_task].priority) {
                current_task = i;
                break;
            }
        }
    }

    return 0;
}