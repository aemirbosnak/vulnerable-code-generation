//FormAI DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>

struct Task {
    char* name;
    int priority;
    int duration;
};

struct Node {
    struct Task* task;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct Scheduler {
    struct LinkedList* highPriorityList;
    struct LinkedList* mediumPriorityList;
    struct LinkedList* lowPriorityList;
};

void displayMenu() {
    printf("Task Scheduler Menu\n");
    printf("1. Add Task\n");
    printf("2. Print Schedule\n");
    printf("3. Quit\n");
}

struct Task* createTask(char* name, int priority, int duration) {
    struct Task* task = (struct Task*)malloc(sizeof(struct Task));
    task->name = name;
    task->priority = priority;
    task->duration = duration;

    return task;
}

void addTask(struct Scheduler* scheduler, char* name, int priority, int duration) {
    struct Task* task = createTask(name, priority, duration);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->task = task;
    node->next = NULL;

    if (priority == 1) {
        if (scheduler->highPriorityList->head == NULL) {
            scheduler->highPriorityList->head = node;
        } else {
            struct Node* current = scheduler->highPriorityList->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    } else if (priority == 2) {
        if (scheduler->mediumPriorityList->head == NULL) {
            scheduler->mediumPriorityList->head = node;
        } else {
            struct Node* current = scheduler->mediumPriorityList->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    } else {
        if (scheduler->lowPriorityList->head == NULL) {
            scheduler->lowPriorityList->head = node;
        } else {
            struct Node* current = scheduler->lowPriorityList->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    }

    printf("Task '%s' added to the scheduler.\n", name);
}

void printTask(struct Task* task) {
    printf("| %-15s | %d             | %-14d |\n", task->name, task->priority, task->duration);
}

void printLinkedList(struct Node* head) {
    printf("| Task Name       | Priority Level | Estimated Time |\n");
    printf("|----------------|----------------|----------------|\n");
    struct Node* current = head;
    while (current != NULL) {
        printTask(current->task);
        current = current->next;
    }
}

void printSchedule(struct Scheduler* scheduler) {
    printf("High Priority Task List\n");
    printLinkedList(scheduler->highPriorityList->head);
    printf("\n");

    printf("Medium Priority Task List\n");
    printLinkedList(scheduler->mediumPriorityList->head);
    printf("\n");

    printf("Low Priority Task List\n");
    printLinkedList(scheduler->lowPriorityList->head);
    printf("\n");
}

int main() {
    struct Scheduler* scheduler = (struct Scheduler*)malloc(sizeof(struct Scheduler));
    scheduler->highPriorityList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    scheduler->highPriorityList->head = NULL;
    scheduler->mediumPriorityList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    scheduler->mediumPriorityList->head = NULL;
    scheduler->lowPriorityList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    scheduler->lowPriorityList->head = NULL;

    int choice = 0;
    while (choice != 3) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                char* name;
                scanf("%s", name);
                printf("Enter priority level (1 = High, 2 = Medium, 3 = Low): ");
                int priority;
                scanf("%d", &priority);
                printf("Enter estimated time in minutes: ");
                int duration;
                scanf("%d", &duration);
                addTask(scheduler, name, priority, duration);
                break;
            case 2:
                printSchedule(scheduler);
                break;
            case 3:
                printf("Quitting Task Scheduler...");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}