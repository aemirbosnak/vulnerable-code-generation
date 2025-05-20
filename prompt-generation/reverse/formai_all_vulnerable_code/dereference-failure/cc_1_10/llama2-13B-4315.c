//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_DELAY 5000

struct task {
    char *name;
    void (*function)(void);
    int delay;
};

void add_task(struct task *task) {
    if (task == NULL) {
        printf("Begone, foul sorcerer! Thou shalt not add naught but valid tasks.\n");
        return;
    }

    if (task->delay < TASK_DELAY) {
        task->delay = TASK_DELAY;
    }

    if (task->name == NULL) {
        printf("Thou hast forgotten to provide a name for thy task, knave!\n");
        return;
    }

    printf("Verily, thy task shall be added to the queue. Prepare thyself for glory!\n");
    task->function = NULL;
}

void run_tasks() {
    struct task tasks[MAX_TASKS];
    int i;

    for (i = 0; i < MAX_TASKS; i++) {
        tasks[i].name = NULL;
        tasks[i].function = NULL;
    }

    printf("Enter thy tasks, brave knights, or thou shalt be consumed by the void!\n");

    while (1) {
        int choice;

        printf("Choose a task to run (1-%d): ", MAX_TASKS);
        scanf("%d", &choice);

        if (choice < 1 || choice > MAX_TASKS) {
            printf("Thou hast made a grave mistake, knave! Choose again.\n");
            continue;
        }

        tasks[choice - 1].name = NULL;
        tasks[choice - 1].function = NULL;

        if (tasks[choice - 1].delay > 0) {
            tasks[choice - 1].delay -= 1;
            printf("Thy task shall be run in %d milliseconds. Prepare thyself for glory!\n", tasks[choice - 1].delay);
        } else {
            tasks[choice - 1].function();
            printf("Thy task hath been run. Thou art victorious!\n");
        }
    }
}

int main() {
    struct task tasks[MAX_TASKS];

    add_task(tasks);

    run_tasks();

    return 0;
}