//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char* name;
    char* date;
    char* time;
    struct appointment* next;
};

struct appointment* head = NULL;

void addAppointment(char* name, char* date, char* time) {
    struct appointment* newAppt = (struct appointment*)malloc(sizeof(struct appointment));
    newAppt->name = (char*)malloc(strlen(name) + 1);
    newAppt->date = (char*)malloc(strlen(date) + 1);
    newAppt->time = (char*)malloc(strlen(time) + 1);
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;

    // If list is empty, make new appointment the head
    if (head == NULL) {
        head = newAppt;
    }
    else {
        // Find the last appointment in the list and add new appointment after it
        struct appointment* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAppt;
    }
}

void deleteAppointment(char* name) {
    struct appointment* current = head;
    struct appointment* previous = NULL;

    // Traverse the list to find the appointment to delete
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // If appointment is the head, update head pointer
            if (previous == NULL) {
                head = current->next;
            }
            // Otherwise, update previous node's next pointer
            else {
                previous->next = current->next;
            }

            // Free memory for appointment
            free(current->name);
            free(current->date);
            free(current->time);
            free(current);
            printf("Appointment for %s has been deleted.\n", name);
            return;
        }

        previous = current;
        current = current->next;
    }

    // If appointment was not found in list
    printf("Appointment for %s not found.\n", name);
}

void printAppointments() {
    printf("Appointments:\n");
    struct appointment* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Date: %s\n", current->date);
        printf("Time: %s\n", current->time);
        current = current->next;
    }
}

int main() {
    printf("Welcome to our appointment scheduler!\n");
    int choice = 0;
    char name[50];
    char date[50];
    char time[50];

    while (choice != 4) {
        printf("\nPlease select an option:\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter date (mm-dd-yyyy): ");
            scanf("%s", date);
            printf("Enter time (hh:mm am/pm): ");
            scanf("%s", time);
            addAppointment(name, date, time);
            break;
        case 2:
            printf("Enter name of appointment to delete: ");
            scanf("%s", name);
            deleteAppointment(name);
            break;
        case 3:
            printAppointments();
            break;
        case 4:
            printf("Exiting scheduler. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}