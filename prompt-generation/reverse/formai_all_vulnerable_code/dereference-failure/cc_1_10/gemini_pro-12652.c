//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char *name;
    char *time;
    char *date;
    char *location;
} Appointment;

Appointment *createAppointment(char *name, char *time, char *date, char *location) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->time = strdup(time);
    appointment->date = strdup(date);
    appointment->location = strdup(location);
    return appointment;
}

void printAppointment(Appointment *appointment) {
    printf("Appointment with %s at %s on %s at %s\n", appointment->name, appointment->time, appointment->date, appointment->location);
}

int main() {
    Appointment *appointments[100];
    int numAppointments = 0;

    while (1) {
        printf("What do you want to do?\n");
        printf("1. Add an appointment\n");
        printf("2. Print all appointments\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the person you're meeting: ");
                char name[100];
                scanf("%s", name);

                printf("Enter the time of the appointment (e.g., 10:00 AM): ");
                char time[100];
                scanf("%s", time);

                printf("Enter the date of the appointment (e.g., 2023-03-08): ");
                char date[100];
                scanf("%s", date);

                printf("Enter the location of the appointment: ");
                char location[100];
                scanf("%s", location);

                Appointment *appointment = createAppointment(name, time, date, location);
                appointments[numAppointments++] = appointment;

                printf("Appointment added!\n");
                break;
            case 2:
                for (int i = 0; i < numAppointments; i++) {
                    printAppointment(appointments[i]);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}