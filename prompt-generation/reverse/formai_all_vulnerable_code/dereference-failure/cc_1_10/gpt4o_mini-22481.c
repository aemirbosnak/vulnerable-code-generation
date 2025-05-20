//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hour; // 0-23
    int minute; // 0-59
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

void addTask(const char *name, int hour, int minute) {
    if (taskCount < MAX_TASKS) {
        strncpy(taskList[taskCount].name, name, MAX_NAME_LENGTH - 1);
        taskList[taskCount].hour = hour;
        taskList[taskCount].minute = minute;
        taskCount++;
        printf("Task '%s' added for %02d:%02d.\n", name, hour, minute);
    } else {
        printf("Task list is full! Cannot add more tasks.\n");
    }
}

void displayTasks() {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s at %02d:%02d\n", i + 1, taskList[i].name, taskList[i].hour, taskList[i].minute);
    }
}

void executeTasks() {
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    int currentHour = localTime->tm_hour;
    int currentMinute = localTime->tm_min;

    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].hour == currentHour && taskList[i].minute == currentMinute) {
            printf("Executing task: %s\n", taskList[i].name);
            // Here, we can add code to actually perform the task.
            // For example, we could call a function or system command.
        }
    }
}

int main() {
    int choice, hour, minute;
    char taskName[MAX_NAME_LENGTH];

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", taskName);
                printf("Enter hour (0-23): ");
                scanf("%d", &hour);
                printf("Enter minute (0-59): ");
                scanf("%d", &minute);
                if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60) {
                    addTask(taskName, hour, minute);
                } else {
                    printf("Invalid time input. Please enter valid hour and minute.\n");
                }
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                executeTasks();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
        
        // Sleep for a minute before checking for new tasks
        sleep(60);
    }

    return 0;
}