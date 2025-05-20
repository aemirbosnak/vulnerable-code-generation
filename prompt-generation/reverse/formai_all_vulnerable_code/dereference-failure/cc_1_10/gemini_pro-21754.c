//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char *name;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment *createAppointment(char *name, int day, int month, int year, int hour, int minute) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->day = day;
    appointment->month = month;
    appointment->year = year;
    appointment->hour = hour;
    appointment->minute = minute;
    return appointment;
}

void printAppointment(Appointment *appointment) {
    printf("%s's appointment is on %d/%d/%d at %d:%d.\n", appointment->name, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
}

int main() {
    Appointment *appointments[100];
    int numAppointments = 0;

    while (1) {
        printf("Enter the name of the person you want to schedule an appointment for (or \"quit\" to quit):\n");
        char name[100];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter the day of the appointment (1-31):\n");
        int day;
        scanf("%d", &day);

        printf("Enter the month of the appointment (1-12):\n");
        int month;
        scanf("%d", &month);

        printf("Enter the year of the appointment (YYYY):\n");
        int year;
        scanf("%d", &year);

        printf("Enter the hour of the appointment (0-23):\n");
        int hour;
        scanf("%d", &hour);

        printf("Enter the minute of the appointment (0-59):\n");
        int minute;
        scanf("%d", &minute);

        appointments[numAppointments] = createAppointment(name, day, month, year, hour, minute);
        numAppointments++;
    }

    printf("\nYour appointments are:\n");
    for (int i = 0; i < numAppointments; i++) {
        printAppointment(appointments[i]);
    }

    return 0;
}