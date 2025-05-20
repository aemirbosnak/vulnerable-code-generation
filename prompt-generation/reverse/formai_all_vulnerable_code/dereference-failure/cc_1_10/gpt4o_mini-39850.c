//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a simple task struct
typedef struct Task {
    char name[50];
    struct Task* next;
} Task;

// Function to create a new task
Task* createTask(char* name) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->next = NULL;
    return newTask;
}

// Function to insert a task at the end
void insertTask(Task** head, char* name) {
    Task* newTask = createTask(name);
    if (*head == NULL) {
        *head = newTask;
        printf("Task '%s' added as the first task!\n", name);
        return;
    }
    Task* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTask;
    printf("Task '%s' added to the list!\n", name);
}

// Function to display all tasks
void displayTasks(Task* head) {
    if (head == NULL) {
        printf("No tasks in the list yet!\n");
        return;
    }
    printf("Here are your tasks:\n");
    Task* temp = head;
    while (temp != NULL) {
        printf("- %s\n", temp->name);
        temp = temp->next;
    }
}

// Function to delete a task by name
void deleteTask(Task** head, char* name) {
    if (*head == NULL) {
        printf("No tasks to delete!\n");
        return;
    }
    Task* temp = *head;
    Task* prev = NULL;

    // Check if the task to delete is the head
    if (strcmp(temp->name, name) == 0) {
        *head = temp->next; // Change head
        free(temp);
        printf("Task '%s' deleted from the list!\n", name);
        return;
    }

    // Search for the task to delete
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the task was not found
    if (temp == NULL) {
        printf("Task '%s' not found!\n", name);
        return;
    }

    // Unlink the task from the list
    prev->next = temp->next;
    free(temp);
    printf("Task '%s' deleted from the list!\n", name);
}

// Main function for user interaction
int main() {
    Task* taskList = NULL;
    int choice;
    char taskName[50];

    do {
        printf("\n*** Task Manager ***\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(taskName, sizeof(taskName), stdin);
                taskName[strcspn(taskName, "\n")] = 0; // Remove newline
                insertTask(&taskList, taskName);
                break;

            case 2:
                printf("Enter task name to delete: ");
                fgets(taskName, sizeof(taskName), stdin);
                taskName[strcspn(taskName, "\n")] = 0; // Remove newline
                deleteTask(&taskList, taskName);
                break;

            case 3:
                displayTasks(taskList);
                break;

            case 4:
                printf("Exiting Task Manager. Bye!\n");
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    // Free allocated memory
    while (taskList != NULL) {
        Task* temp = taskList;
        taskList = taskList->next;
        free(temp);
    }

    return 0;
}