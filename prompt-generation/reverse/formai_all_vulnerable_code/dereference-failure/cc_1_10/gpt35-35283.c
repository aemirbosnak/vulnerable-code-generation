//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int day;
    int month;
    int year;
    char* name;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void scheduleAppointment() {
    int day, month, year;
    char name[100];

    printf("Enter the date of the appointment (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Enter the name of the appointment: ");
    scanf("%s", name);

    appointments[numAppointments].day = day;
    appointments[numAppointments].month = month;
    appointments[numAppointments].year = year;
    appointments[numAppointments].name = malloc(sizeof(char) * 100);
    strcpy(appointments[numAppointments].name, name);

    printf("Appointment added on %d/%d/%d for %s!\n", day, month, year, name);

    numAppointments++;
}

void displayAppointments() {
    printf("List of Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %d/%d/%d - %s\n", i+1, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].name);
    }
}

void deleteAppointment() {
    int index;

    displayAppointments();
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > numAppointments) {
        printf("Invalid appointment index %d\n", index);
        return;
    }

    printf("Deleting appointment:\n");
    printf("%d/%d/%d - %s\n", appointments[index-1].day, appointments[index-1].month, appointments[index-1].year, appointments[index-1].name);

    free(appointments[index-1].name);

    for (int i = index-1; i < numAppointments-1; i++) {
        appointments[i] = appointments[i+1];
    }

    numAppointments--;
}

void displayMenu() {
    printf("Appointment Scheduling Menu:\n");
    printf("1. Schedule Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice %d\n", choice);
        }
    } while (choice != 4);

    return 0;
}