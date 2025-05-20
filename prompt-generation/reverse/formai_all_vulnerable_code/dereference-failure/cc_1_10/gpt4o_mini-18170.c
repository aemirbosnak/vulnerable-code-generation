//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 100

typedef struct Appointment {
    int id;
    char description[MAX_DESC];
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;
int appointment_counter = 1;

void addAppointment(char* description) {
    Appointment* new_appointment = (Appointment*)malloc(sizeof(Appointment));
    new_appointment->id = appointment_counter++;
    strncpy(new_appointment->description, description, MAX_DESC - 1);
    new_appointment->description[MAX_DESC - 1] = '\0'; // null-terminate
    new_appointment->next = head;
    head = new_appointment;
    printf("Appointment added with ID: %d\n", new_appointment->id);
}

void viewAppointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }
    Appointment* current = head;
    printf("Scheduled Appointments:\n");
    while (current != NULL) {
        printf("ID: %d, Description: %s\n", current->id, current->description);
        current = current->next;
    }
}

void deleteAppointment(int id) {
    Appointment* current = head;
    Appointment* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Appointment with ID: %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Remove the first appointment
    } else {
        previous->next = current->next; // Bypass the current node
    }
    free(current);
    printf("Appointment with ID: %d deleted.\n", id);
}

void freeAppointments() {
    Appointment* current = head;
    while (current != NULL) {
        Appointment* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int choice;
    char description[MAX_DESC];
    int id;

    do {
        printf("\n--- Appointment Scheduler Menu ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter appointment description: ");
                fgets(description, MAX_DESC, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline character
                addAppointment(description);
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Enter appointment ID to delete: ");
                scanf("%d", &id);
                deleteAppointment(id);
                break;
            case 4:
                printf("Exiting...\n");
                freeAppointments();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}