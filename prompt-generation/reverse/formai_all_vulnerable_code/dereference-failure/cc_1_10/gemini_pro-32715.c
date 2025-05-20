//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

struct task {
    char *cmd;
    int delay;
};

struct task_scheduler {
    struct task *tasks;
    int num_tasks;
};

int main() {
    struct task_scheduler scheduler = {
        .tasks = NULL,
        .num_tasks = 0
    };

    // Create a task that runs "ls -l" after 5 seconds
    struct task task1 = {
        .cmd = "ls -l",
        .delay = 5
    };

    // Create a task that runs "grep hello" after 10 seconds
    struct task task2 = {
        .cmd = "grep hello",
        .delay = 10
    };

    // Add the tasks to the scheduler
    scheduler.tasks = realloc(scheduler.tasks, sizeof(struct task) * (scheduler.num_tasks + 2));
    scheduler.tasks[scheduler.num_tasks++] = task1;
    scheduler.tasks[scheduler.num_tasks++] = task2;

    // Start the scheduler
    while (1) {
        // Check if any tasks are ready to run
        for (int i = 0; i < scheduler.num_tasks; i++) {
            struct task *task = &scheduler.tasks[i];
            if (task->delay <= 0) {
                // Run the task
                printf("Running task: %s\n", task->cmd);
                pid_t pid = fork();
                if (pid == 0) {
                    execlp("/bin/sh", "sh", "-c", task->cmd, NULL);
                    exit(0);
                }
                waitpid(pid, NULL, 0);

                // Remove the task from the scheduler
                for (int j = i + 1; j < scheduler.num_tasks; j++) {
                    scheduler.tasks[j - 1] = scheduler.tasks[j];
                }
                scheduler.num_tasks--;
                i--;
            }
        }

        // Decrement the delay for all tasks
        for (int i = 0; i < scheduler.num_tasks; i++) {
            scheduler.tasks[i].delay--;
        }

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}