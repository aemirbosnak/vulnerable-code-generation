//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Appointment {
    char *name;
    int date;
    int time;
};

struct Node {
    struct Appointment appointment;
    struct Node *next;
};

struct List {
    char *name;
    struct Node *head;
};

void displayMenu() {
    printf("\n\n");
    printf("Menu\n");
    printf("====\n");
    printf("1. Add appointment\n");
    printf("2. Delete appointment\n");
    printf("3. View appointments\n");
    printf("4. Exit program\n");
}

void addAppointment(struct List *lists, int numLists) {
    // get list name
    char name[20];
    printf("\nEnter name of list to add appointment to: ");
    scanf("%s", name);
    
    // search for list index
    int listIndex = -1;
    for (int i = 0; i < numLists; i++) {
        if (strcmp(lists[i].name, name) == 0) {
            listIndex = i;
            break;
        }
    }
    
    // check if list exists
    if (listIndex == -1) {
        printf("List does not exist.\n");
        return;
    }
    
    // get name, date, and time of appointment
    char *appointmentName = malloc(sizeof(char) * 50);
    printf("Enter name of appointment: ");
    scanf("%s", appointmentName);
    
    int date, time;
    printf("Enter date (mmdd): ");
    scanf("%d", &date);
    
    printf("Enter time (hhmm): ");
    scanf("%d", &time);
    
    // add appointment to list
    struct Appointment newAppointment = {appointmentName, date, time};
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->appointment = newAppointment;
    newNode->next = NULL;
    
    if (lists[listIndex].head == NULL) {
        lists[listIndex].head = newNode;
    } else {
        struct Node *current = lists[listIndex].head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteAppointment(struct List *lists, int numLists) {
    // get list name
    char name[20];
    printf("\nEnter name of list to delete appointment from: ");
    scanf("%s", name);
    
    // search for list index
    int listIndex = -1;
    for (int i = 0; i < numLists; i++) {
        if (strcmp(lists[i].name, name) == 0) {
            listIndex = i;
            break;
        }
    }
    
    // check if list exists
    if (listIndex == -1) {
        printf("List does not exist.\n");
        return;
    }
    
    // get name of appointment to delete
    char appointmentName[50];
    printf("Enter name of appointment to delete: ");
    scanf("%s", appointmentName);
    
    // search for appointment to delete
    struct Node *current = lists[listIndex].head;
    struct Node *previous = NULL;
    bool found = false;
    while (current != NULL) {
        if (strcmp(current->appointment.name, appointmentName) == 0) {
            found = true;
            break;
        }
        previous = current;
        current = current->next;
    }
    
    // check if appointment exists
    if (!found) {
        printf("Appointment does not exist.\n");
        return;
    }
    
    // delete appointment
    if (previous == NULL) {
        lists[listIndex].head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current->appointment.name);
    free(current);
}

void viewAppointments(struct List *lists, int numLists) {
    // get list name
    char name[20];
    printf("\nEnter name of list to view appointments: ");
    scanf("%s", name);
    
    // search for list index
    int listIndex = -1;
    for (int i = 0; i < numLists; i++) {
        if (strcmp(lists[i].name, name) == 0) {
            listIndex = i;
            break;
        }
    }
    
    // check if list exists
    if (listIndex == -1) {
        printf("List does not exist.\n");
        return;
    }
    
    // display appointments
    printf("\nAppointments:\n");
    struct Node *current = lists[listIndex].head;
    while (current != NULL) {
        printf("%s - %d/%d - %d:%d\n", current->appointment.name, current->appointment.date % 100, current->appointment.date / 100, current->appointment.time / 100, current->appointment.time % 100);
        current = current->next;
    }
}

int main() {
    // initialize lists
    struct List personalList = {"Personal", NULL};
    struct List workList = {"Work", NULL};
    struct List shoppingList = {"Shopping", NULL};
    struct List *lists = malloc(sizeof(struct List) * 3);
    lists[0] = personalList;
    lists[1] = workList;
    lists[2] = shoppingList;
    int numLists = 3;
    
    // run program
    int choice;
    do {
        displayMenu();
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment(lists, numLists);
                break;
            case 2:
                deleteAppointment(lists, numLists);
                break;
            case 3:
                viewAppointments(lists, numLists);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    // free memory
    for (int i = 0; i < numLists; i++) {
        struct Node *current = lists[i].head;
        while (current != NULL) {
            struct Node *temp = current;
            current = current->next;
            free(temp->appointment.name);
            free(temp);
        }
    }
    free(lists);
    
    return 0;
}