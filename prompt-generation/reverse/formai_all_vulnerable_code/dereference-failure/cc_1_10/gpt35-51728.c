//FormAI DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Structure to store information about survivors
typedef struct survivor {
    char name[20];
    int age;
    char occupation[20];
    struct survivor* next;
} survivor_t;

// Function to create a new survivor node
survivor_t* createNode(char name[], int age, char occupation[]) {
    survivor_t* newSurvivor = (survivor_t*) malloc(sizeof(survivor_t));
    strcpy(newSurvivor->name, name);
    newSurvivor->age = age;
    strcpy(newSurvivor->occupation, occupation);
    newSurvivor->next = NULL;
    return newSurvivor;
}

// Function to add a survivor to the linked list
void addSurvivor(survivor_t** head, char name[], int age, char occupation[]) {
    if (*head == NULL) {
        *head = createNode(name, age, occupation);
    }
    else {
        survivor_t* currentSurvivor = *head;
        while (currentSurvivor->next != NULL) {
            currentSurvivor = currentSurvivor->next;
        }
        currentSurvivor->next = createNode(name, age, occupation);
    }
}

// Function to remove a survivor from the linked list
void removeSurvivor(survivor_t** head, char name[]) {
    survivor_t* currentSurvivor = *head;
    survivor_t* previousSurvivor;
    if (strcmp(currentSurvivor->name, name) == 0) {
        *head = currentSurvivor->next;
        free(currentSurvivor);
        return;
    }
    while (currentSurvivor != NULL && strcmp(currentSurvivor->name, name) != 0) {
        previousSurvivor = currentSurvivor;
        currentSurvivor = currentSurvivor->next;
    }
    if (currentSurvivor == NULL) {
        printf("Survivor not found!\n");
        return;
    }
    previousSurvivor->next = currentSurvivor->next;
    free(currentSurvivor);
}

// Function to print the list of survivors
void printList(survivor_t* head) {
    printf("\n");

    if (head == NULL) {
        printf("No survivors found.\n");
        return;
    }
    while (head != NULL) {
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("Occupation: %s\n\n", head->occupation);
        head = head->next;
    }
}

// Function to empty the list of survivors
void deleteList(survivor_t** head) {
    survivor_t* currentSurvivor = *head;
    survivor_t* nextSurvivor;
    while (currentSurvivor != NULL) {
        nextSurvivor = currentSurvivor->next;
        free(currentSurvivor);
        currentSurvivor = nextSurvivor;
    }
    *head = NULL;
    printf("All survivors have been eliminated.\n");
}

int main() {
    int choice;
    survivor_t* list = NULL;
    char name[20], occupation[20];
    int age;

    do {
        printf("\nWelcome to the Apocalypse Survivor Tracker\n");
        printf("1) Add survivor\n");
        printf("2) Remove survivor\n");
        printf("3) Print list of survivors\n");
        printf("4) Eliminate all survivors\n");
        printf("5) Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter survivor name: ");
                scanf("%s", name);
                printf("Enter survivor age: ");
                scanf("%d", &age);
                printf("Enter survivor occupation: ");
                scanf("%s", occupation);
                addSurvivor(&list, name, age, occupation);
                printf("Survivor added to the list.\n");
                break;
            }
            case 2: {
                printf("Enter survivor name to remove: ");
                scanf("%s", name);
                removeSurvivor(&list, name);
                break;
            }
            case 3: {
                printList(list);
                break;
            }
            case 4: {
                deleteList(&list);
                break;
            }
            case 5: {
                printf("Thank you for using the Apocalypse Survivor Tracker!\n");
                break;
            }
            default: {
                printf("Invalid choice, please try again.\n");
            }
        }
    } while (choice != 5);

    return 0;
}