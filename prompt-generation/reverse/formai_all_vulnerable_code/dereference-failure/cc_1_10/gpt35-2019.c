//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char date[10]; // format: MM/DD/YYYY
    char time[6]; // format: HH:MM
} Appointment;

void addAppointment(Appointment *appointments, int *size);
void displayAppointments(Appointment *appointments, int size);
void deleteAppointment(Appointment *appointments, int *size);

int main() {
    int choice, size = 0;
    char buffer[50];
    Appointment *appointments = malloc(sizeof(Appointment) * 100);

    do {
        printf("\nC Appointment Scheduler\n");
        printf("-----------------------\n");
        printf("1. Add an Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Delete an Appointment\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        if (fgets(buffer, sizeof(buffer), stdin)) {
            choice = atoi(buffer);
        } else {
            choice = 0;
        }

        switch (choice) {
            case 1:
                addAppointment(appointments, &size);
                break;
            case 2:
                displayAppointments(appointments, size);
                break;
            case 3:
                deleteAppointment(appointments, &size);
                break;
            case 4:
                printf("\nExiting Program...");
                break;
            default:
                printf("\nInvalid Choice. Please try again.");
        }
    } while (choice != 4);

    free(appointments);

    return 0;
}

void addAppointment(Appointment *appointments, int *size) {
    char buffer[50];

    printf("\nEnter Name: ");
    fgets(appointments[*size].name, sizeof(appointments[*size].name), stdin);
    appointments[*size].name[strcspn(appointments[*size].name, "\n")] = 0; // remove newline character

    printf("Enter Age: ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        appointments[*size].age = atoi(buffer);
    } else {
        appointments[*size].age = 0;
    }

    printf("Enter Date (MM/DD/YYYY): ");
    fgets(appointments[*size].date, sizeof(appointments[*size].date), stdin);
    appointments[*size].date[strcspn(appointments[*size].date, "\n")] = 0;

    printf("Enter Time (HH:MM): ");
    fgets(appointments[*size].time, sizeof(appointments[*size].time), stdin);
    appointments[*size].time[strcspn(appointments[*size].time, "\n")] = 0;

    printf("\nAppointment added successfully.\n");
    (*size)++;
}

void displayAppointments(Appointment *appointments, int size) {
    if (size == 0) {
        printf("\nNo appointments to display.\n");
    } else {
        printf("\nAppointments:\n");
        printf("Name\tAge\tDate\tTime\n");
        printf("----\t---\t----\t----\n");
        for (int i = 0; i < size; i++) {
            printf("%s\t%d\t%s\t%s\n", appointments[i].name, appointments[i].age, appointments[i].date, appointments[i].time);
        }
    }
}

void deleteAppointment(Appointment *appointments, int *size) {
    char buffer[50], name[50];
    int index = -1;

    printf("\nEnter the name of the appointment to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < *size; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nAppointment not found.\n");
    } else {
        for (int i = index; i < *size - 1; i++) {
            appointments[i] = appointments[i+1];
        }
        (*size)--;
        printf("\nAppointment deleted successfully.\n");
    }
}