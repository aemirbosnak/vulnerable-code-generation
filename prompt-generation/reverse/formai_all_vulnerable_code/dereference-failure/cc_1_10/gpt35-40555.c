//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold exercise information
typedef struct Exercise {
    char name[50];
    int duration;
    int calories_burned;
    struct Exercise* next;
} Exercise;

// Add a new exercise node to the linked list
void addExercise(Exercise** head_ref, char name[], int duration, int calories_burned) {
    Exercise* new_node = (Exercise*) malloc(sizeof(Exercise));
    strcpy(new_node->name, name);
    new_node->duration = duration;
    new_node->calories_burned = calories_burned;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        Exercise* ptr = *head_ref;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

// Display all exercises in the linked list and calculate
// total duration and calories burned
void displayExercises(Exercise* head) {
    Exercise* ptr = head;
    int total_duration = 0;
    int total_calories = 0;

    printf("%-30s %-10s %-15s\n", "Name", "Duration", "Calories Burned");
    printf("---------------------------------------------------------\n");

    while (ptr != NULL) {
        printf("%-30s %-10d %-15d\n", ptr->name, ptr->duration, ptr->calories_burned);
        total_duration += ptr->duration;
        total_calories += ptr->calories_burned;
        ptr = ptr->next;
    }

    printf("---------------------------------------------------------\n");
    printf("%-30s %-10d %-15d\n", "TOTAL", total_duration, total_calories);
}

int main() {
    int choice;
    Exercise* head = NULL;

    do {
        printf("\nSelect an option:\n");
        printf("1) Add new exercise\n");
        printf("2) Display exercises\n");
        printf("3) Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                int duration;
                int calories_burned;

                printf("Enter exercise name: ");
                scanf("%s", name);

                printf("Enter duration (in minutes): ");
                scanf("%d", &duration);

                printf("Enter calories burned: ");
                scanf("%d", &calories_burned);

                addExercise(&head, name, duration, calories_burned);
                break;
            }
            case 2: {
                displayExercises(head);
                break;
            }
            case 3: {
                printf("Exiting program...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } while (choice != 3);

    return 0;
}