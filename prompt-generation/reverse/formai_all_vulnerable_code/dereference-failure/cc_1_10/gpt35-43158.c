//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

typedef struct {
    int hour;
    int minute;
    char command[50];
} Task;

Task tasks[10];
int task_count = 0;

void sig_handler(int signum) {
    int pid;
    waitpid(-1, NULL, WNOHANG);
}

void schedule_task(Task task) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Failed to fork process\n");
        return;
    }

    if (pid == 0) {
        printf("Task scheduled for %02d:%02d\n", task.hour, task.minute);
        sleep(task.hour * 3600 + task.minute * 60);
        printf("Executing task: %s\n", task.command);
        system(task.command);
        exit(0);
    }

    signal(SIGCHLD, sig_handler);
}

int main() {
    signal(SIGCHLD, sig_handler);

    tasks[0].hour = 12;
    tasks[0].minute = 0;
    sprintf(tasks[0].command, "%s", "echo 'Hello, World!'");

    tasks[1].hour = 14;
    tasks[1].minute = 30;
    sprintf(tasks[1].command, "%s", "echo 'Goodbye, World!'");

    task_count = 2;

    while (1) {
        time_t raw_time;
        struct tm *time_info;
        time(&raw_time);
        time_info = localtime(&raw_time);

        for (int i = 0; i < task_count; i++) {
            if (tasks[i].hour == time_info->tm_hour && tasks[i].minute == time_info->tm_min) {
                schedule_task(tasks[i]);
            }
        }

        sleep(60);
    }

    return 0;
}