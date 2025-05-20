//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_APPOINTMENT_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char appointment[MAX_APPOINTMENT_LENGTH];
    struct Appointment *next;
} Appointment;

Appointment *appointment_list = NULL;

void display_menu() {
    printf("\n============= Appointment Scheduler =============\n");
    printf("1. Schedule an appointment\n");
    printf("2. View scheduled appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Quit\n");
}

void schedule_appointment() {
    Appointment *new_appointment = (Appointment *)malloc(sizeof(Appointment));

    printf("Enter your name: ");
    fgets(new_appointment->name, MAX_NAME_LENGTH, stdin);
    new_appointment->name[strcspn(new_appointment->name, "\n")] = '\0'; // Remove newline character

    printf("Enter appointment details: ");
    fgets(new_appointment->appointment, MAX_APPOINTMENT_LENGTH, stdin);
    new_appointment->appointment[strcspn(new_appointment->appointment, "\n")] = '\0'; // Remove newline character

    new_appointment->next = appointment_list;
    appointment_list = new_appointment;
}

void view_appointments() {
    Appointment *current = appointment_list;

    if (appointment_list == NULL) {
        printf("\nNo appointments scheduled.\n");
        return;
    }

    printf("\n=========== Schedule ============\n");
    printf("| Name          | Appointment          |\n");
    printf("|---------------|----------------------|\n");

    while (current != NULL) {
        printf("| %-15s | %-30s |\n", current->name, current->appointment);
        current = current->next;
    }
}

void delete_appointment() {
    char name[MAX_NAME_LENGTH];
    Appointment *prev, *current;

    printf("Enter name to delete: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    prev = NULL;
    current = appointment_list;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nAppointment not found.\n");
        return;
    }

    if (prev == NULL) {
        appointment_list = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("\nThanks for using the Appointment Scheduler! Bye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}