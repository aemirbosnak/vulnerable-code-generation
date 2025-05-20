//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_TASKS 10
#define MAX_CMD_LEN 100

typedef struct task {
    char *cmd;
    int interval;
    int next_run;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *cmd, int interval) {
    if (num_tasks == MAX_TASKS) {
        fprintf(stderr, "Too many tasks\n");
        return;
    }

    tasks[num_tasks].cmd = strdup(cmd);
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].next_run = time(NULL);
    num_tasks++;
}

void run_tasks() {
    int i;

    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].next_run <= time(NULL)) {
            system(tasks[i].cmd);
            tasks[i].next_run = time(NULL) + tasks[i].interval;
        }
    }
}

void signal_handler(int signum) {
    run_tasks();
}

int main(int argc, char *argv[]) {
    int i;

    signal(SIGALRM, signal_handler);

    for (i = 1; i < argc; i++) {
        char *cmd = argv[i];
        int interval = 60;

        if (strncmp(cmd, "every ", 6) == 0) {
            cmd += 6;
            interval = atoi(cmd);
            cmd = strchr(cmd, ' ') + 1;
        }

        add_task(cmd, interval);
    }

    while (1) {
        alarm(1);
        pause();
    }

    return 0;
}