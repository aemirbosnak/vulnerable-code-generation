//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    char *desc;
    time_t start_time;
    time_t end_time;
} Appointment;

Appointment *appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void addAppointment(char *desc, time_t start_time, time_t end_time) {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Error: Appointment database is full.\n");
        return;
    }

    Appointment *appt = malloc(sizeof(Appointment));
    appt->desc = strdup(desc);
    appt->start_time = start_time;
    appt->end_time = end_time;

    appointments[numAppointments++] = appt;
}

void printAppointments() {
    for (int i = 0; i < numAppointments; i++) {
        Appointment *appt = appointments[i];
        printf("%s: %s - %s\n", appt->desc, ctime(&appt->start_time), ctime(&appt->end_time));
    }
}

void findAppointments(time_t start_time, time_t end_time) {
    for (int i = 0; i < numAppointments; i++) {
        Appointment *appt = appointments[i];
        if (appt->start_time >= start_time && appt->end_time <= end_time) {
            printf("%s: %s - %s\n", appt->desc, ctime(&appt->start_time), ctime(&appt->end_time));
        }
    }
}

void clearAppointments() {
    for (int i = 0; i < numAppointments; i++) {
        Appointment *appt = appointments[i];
        free(appt->desc);
        free(appt);
    }

    numAppointments = 0;
}

bool validateTime(time_t time) {
    return time >= 0 && time < 24 * 60 * 60;
}

int main() {
    time_t now = time(NULL);
    time_t end_of_day = now + 24 * 60 * 60 - 1;

    addAppointment("Doctor's appointment", now + 60 * 60, now + 2 * 60 * 60);
    addAppointment("Meeting with boss", now + 3 * 60 * 60, now + 4 * 60 * 60);
    addAppointment("Dinner with friends", now + 6 * 60 * 60, now + 8 * 60 * 60);

    printf("Current appointments:\n");
    printAppointments();

    printf("\nAppointments between 10:00 AM and 12:00 PM:\n");
    findAppointments(now + 10 * 60 * 60, now + 12 * 60 * 60);

    printf("\nClearing all appointments.\n");
    clearAppointments();

    printf("\nCurrent appointments:\n");
    printAppointments();

    return 0;
}