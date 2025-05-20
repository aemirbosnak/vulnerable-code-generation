//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Global variables
int taskCount = 0;
int taskDelay = 5000; // Delay between tasks in milliseconds
int taskTime = 30000; // Task duration in milliseconds
int taskID = 0;

// Function prototypes
void taskFunction(void);
void printUsage(void);
void printTasks(void);
void printTask(int taskID);
void printTime(struct timeval *t);

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        printUsage();
        exit(1);
    }

    int taskCountFromCommandLine = atoi(argv[1]);

    if (taskCountFromCommandLine < 1 || taskCountFromCommandLine > 10) {
        printf("Task count must be between 1 and 10, inclusive.\n");
        exit(1);
    }

    taskCount = taskCountFromCommandLine;

    struct timeval startTime;
    gettimeofday(&startTime, NULL);
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);

    while (taskCount > 0) {
        if (taskCount == 1) {
            printf("Task %d starting at %ld.%06ld...\n", taskID, startTime.tv_sec, startTime.tv_usec);
        } else {
            printf("Task %d starting at %ld.%06ld...\n", taskID, currentTime.tv_sec, currentTime.tv_usec);
        }

        taskFunction();

        if (taskCount == 1) {
            printf("Task %d ending at %ld.%06ld...\n", taskID, currentTime.tv_sec, currentTime.tv_usec);
        } else {
            printf("Task %d ending at %ld.%06ld...\n", taskID, currentTime.tv_sec, currentTime.tv_usec);
        }

        taskID++;
        taskCount--;

        currentTime = startTime;
        gettimeofday(&currentTime, NULL);

        sleep(taskDelay);
    }

    return 0;
}

void taskFunction(void)
{
    printf("Task Function running...\n");
    sleep(taskTime);
}

void printUsage(void)
{
    printf("Usage: task_scheduler <task_count>\n");
}

void printTasks(void)
{
    printf("Tasks: ");
    for (int i = 0; i < taskCount; i++) {
        printTask(i);
        printf(" ");
    }
    printf("\n");
}

void printTask(int taskID)
{
    printf("Task %d: ", taskID);
}

void printTime(struct timeval *t)
{
    printf("Time: %ld.%06ld\n", t->tv_sec, t->tv_usec);
}