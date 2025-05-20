//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
/*
 * PROGRAM NAME: C Task Scheduler Example
 * AUTHOR: [Your Name]
 * DATE: [The date you wrote this program]
 * PURPOSE: A task scheduler program that allows users to add, edit, and delete tasks to be executed at specific times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task struct
typedef struct {
  char name[50];
  int hour;
  int minute;
} Task;

// Function declarations
void displayMenu();
Task createTask();
void saveTask(Task task);
void editTask(int taskIndex);
void deleteTask(int taskIndex);
void executeTasks();

// Global variable for storing tasks
Task tasks[100];
int numTasks = 0;

int main() {
  int choice;
  do {
    displayMenu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        // Add task
        tasks[numTasks] = createTask();
        saveTask(tasks[numTasks]);
        numTasks++;
        printf("Task added successfully.\n");
        break;
      case 2:
        // Edit task
        if (numTasks == 0) {
          printf("No tasks to edit.\n");
        } else {
          int taskIndex;
          printf("Enter task index to edit (0-%d): ", numTasks-1);
          scanf("%d", &taskIndex);
          if (taskIndex < 0 || taskIndex >= numTasks) {
            printf("Invalid task index.\n");
          } else {
            editTask(taskIndex);
          }
        }
        break;
      case 3:
        // Delete task
        if (numTasks == 0) {
          printf("No tasks to delete.\n");
        } else {
          int taskIndex;
          printf("Enter task index to delete (0-%d): ", numTasks-1);
          scanf("%d", &taskIndex);
          if (taskIndex < 0 || taskIndex >= numTasks) {
            printf("Invalid task index.\n");
          } else {
            deleteTask(taskIndex);
            numTasks--;
            printf("Task deleted successfully.\n");
          }
        }
        break;
      case 4:
        // Execute tasks
        executeTasks();
        break;
      case 5:
        // Quit
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  } while (choice != 5);

  return 0;
}

/*
 * Displays the menu of options for the user.
 */
void displayMenu() {
  printf("\nTASK SCHEDULER\n");
  printf("1. Add Task\n");
  printf("2. Edit Task\n");
  printf("3. Delete Task\n");
  printf("4. Execute Tasks\n");
  printf("5. Quit\n");
  printf("Enter choice: ");
}

/*
 * Creates a new task with user inputted name, hour, and minute.
 */
Task createTask() {
  Task task;
  printf("Enter task name: ");
  scanf("%s", task.name);
  printf("Enter hour (0-23): ");
  scanf("%d", &task.hour);
  printf("Enter minute (0-59): ");
  scanf("%d", &task.minute);
  return task;
}

/*
 * Saves the task to a text file with its name, hour, and minute.
 */
void saveTask(Task task) {
  FILE *file;
  file = fopen("tasks.txt", "a");
  fprintf(file, "%s %d %d\n", task.name, task.hour, task.minute);
  fclose(file);
}

/*
 * Edits an existing task with user inputted name, hour, and minute.
 */
void editTask(int taskIndex) {
  Task task = tasks[taskIndex];
  printf("Current task name: %s\n", task.name);
  printf("Enter new task name (leave blank to keep current): ");
  scanf("%s", task.name);
  printf("Current task time: %02d:%02d\n", task.hour, task.minute);
  printf("Enter new hour (leave blank to keep current): ");
  char hourInput[10];
  scanf("%s", hourInput);
  if (hourInput[0] != '\0') {
    task.hour = atoi(hourInput);
  }
  printf("Enter new minute (leave blank to keep current): ");
  char minuteInput[10];
  scanf("%s", minuteInput);
  if (minuteInput[0] != '\0') {
    task.minute = atoi(minuteInput);
  }
  tasks[taskIndex] = task;
  saveTask(task);
  printf("Task edited successfully.\n");
}

/*
 * Deletes an existing task and removes it from the text file.
 */
void deleteTask(int taskIndex) {
  Task task = tasks[taskIndex];
  FILE *file, *tempFile;
  char line[256];
  file = fopen("tasks.txt", "r");
  tempFile = fopen("temp.txt", "w");
  while (fgets(line, sizeof(line), file)) {
    char taskName[50];
    int taskHour, taskMinute;
    sscanf(line, "%s %d %d", taskName, &taskHour, &taskMinute);
    if (strcmp(taskName, task.name) != 0 || taskHour != task.hour || taskMinute != task.minute) {
      fprintf(tempFile, "%s", line);
    }
  }
  fclose(file);
  fclose(tempFile);
  remove("tasks.txt");
  rename("temp.txt", "tasks.txt");
}

/*
 * Executes all tasks that are scheduled for the current time.
 */
void executeTasks() {
  FILE *file;
  char line[256];
  file = fopen("tasks.txt", "r");
  time_t currentTime = time(NULL);
  struct tm *timeStruct = localtime(&currentTime);
  int currentHour = timeStruct->tm_hour;
  int currentMinute = timeStruct->tm_min;
  while (fgets(line, sizeof(line), file)) {
    int taskHour, taskMinute;
    sscanf(line, "%*s %d %d", &taskHour, &taskMinute);
    if (taskHour == currentHour && taskMinute == currentMinute) {
      printf("Executing task: %s", line);
    }
  }
  fclose(file);
}