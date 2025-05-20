//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to hold appointment details */
typedef struct appointment {
    char patientName[50];
    char doctorName[50];
    char time[50];
    char reason[100];
} Appointment;

/* Define function to add an appointment */
void addAppointment(Appointment *appointments, int *numAppointments) {
    /* Allocate memory for a new appointment */
    appointments = (Appointment*)realloc(appointments, (*numAppointments + 1) * sizeof(Appointment));

    /* Get appointment details from user */
    printf("Enter patient name: ");
    scanf("%s", appointments[*numAppointments].patientName);

    printf("Enter doctor name: ");
    scanf("%s", appointments[*numAppointments].doctorName);

    printf("Enter appointment time: ");
    scanf("%s", appointments[*numAppointments].time);

    printf("Enter reason for visit: ");
    scanf("%s", appointments[*numAppointments].reason);

    (*numAppointments)++;
}

/* Define function to view all appointments */
void viewAppointments(Appointment *appointments, int numAppointments) {
    int i;

    /* Print header */
    printf("%-20s %-20s %-20s %-20s\n", "Patient Name", "Doctor Name", "Time", "Reason");

    /* Print each appointment */
    for (i = 0; i < numAppointments; i++) {
        printf("%-20s %-20s %-20s %-20s\n", appointments[i].patientName, appointments[i].doctorName, appointments[i].time, appointments[i].reason);
    }
}

/* Define function to delete an appointment */
void deleteAppointment(Appointment *appointments, int *numAppointments) {
    int i, index;

    /* Get index of appointment to delete */
    printf("Enter index of appointment to delete: ");
    scanf("%d", &index);

    /* Move all appointments after the index back one position */
    for (i = index; i < *numAppointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    /* Reallocate memory for appointments */
    appointments = (Appointment*)realloc(appointments, (*numAppointments - 1) * sizeof(Appointment));

    (*numAppointments)--;
}

/* Define main function */
int main() {
    Appointment *appointments;
    int numAppointments = 0;
    int choice;

    while (1) {
        /* Display menu */
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");

        /* Get user choice */
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Process user choice */
        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 4:
                /* Exit program */
                exit(0);
            default:
                /* Invalid choice */
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}