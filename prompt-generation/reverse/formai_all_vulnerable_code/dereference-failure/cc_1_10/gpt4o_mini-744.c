//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    int id;
    char date[11];
    char time[6]; // HH:MM
    char description[256];
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;
int appointmentCounter = 0;

void addAppointment() {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->id = ++appointmentCounter;
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", newAppointment->date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", newAppointment->time);
    printf("Enter appointment description: ");
    getchar(); // to consume newline character
    fgets(newAppointment->description, 256, stdin);
    newAppointment->description[strcspn(newAppointment->description, "\n")] = 0; // Remove newline

    newAppointment->next = head;
    head = newAppointment;

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }
    Appointment* current = head;
    printf("Scheduled Appointments:\n");
    while (current) {
        printf("ID: %d | Date: %s | Time: %s | Description: %s\n",
               current->id, current->date, current->time, current->description);
        current = current->next;
    }
}

void deleteAppointment() {
    int id;
    printf("Enter the appointment ID to delete: ");
    scanf("%d", &id);
    
    Appointment* current = head;
    Appointment* previous = NULL;

    while (current && current->id != id) {
        previous = current;
        current = current->next;
    }
    
    if (!current) {
        printf("No appointment found with ID %d.\n", id);
        return;
    }

    if (previous) {
        previous->next = current->next;
    } else {
        head = current->next;
    }
    
    free(current);
    printf("Appointment with ID %d deleted successfully!\n", id);
}

void searchAppointment() {
    char date[11];
    printf("Enter the date of the appointment to search (YYYY-MM-DD): ");
    scanf("%s", date);
    
    Appointment* current = head;
    int found = 0;
    printf("Searching for appointments on %s:\n", date);
    while (current) {
        if (strcmp(current->date, date) == 0) {
            printf("ID: %d | Date: %s | Time: %s | Description: %s\n",
                   current->id, current->date, current->time, current->description);
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("No appointments found on %s.\n", date);
    }
}

void showMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Search Appointment by Date\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                searchAppointment();
                break;
            case 5:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    // Free allocated memory before exit
    while (head) {
        Appointment* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}