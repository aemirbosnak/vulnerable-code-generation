//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char name[50];
    time_t date;
    int duration;
};

void addAppointment(struct Appointment *appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[numAppointments].date);
    appointments[numAppointments].duration = 0;
    numAppointments++;
}

void displayAppointments(struct Appointment *appointments, int numAppointments) {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %s\n", appointments[i].name, appointments[i].date);
    }
}

void scheduleAppointment(struct Appointment *appointments, int numAppointments) {
    time_t now;
    time(&now);
    int year, month, day, hour, minute, second;

    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter minute: ");
    scanf("%d", &minute);
    printf("Enter second: ");
    scanf("%d", &second);

    struct tm *appt = localtime(&now);
    appt->tm_year = year;
    appt->tm_mon = month - 1;
    appt->tm_mday = day;
    appt->tm_hour = hour;
    appt->tm_min = minute;
    appt->tm_sec = second;

    int apptDuration = mktime(appt) - now;

    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].date == now) {
            printf("Appointment already scheduled at this time.\n");
            return;
        }
        if (appointments[i].duration > 0) {
            if (mktime(appt) - appointments[i].date < appointments[i].duration) {
                printf("Appointment conflicts with existing appointment.\n");
                return;
            }
        }
    }

    appointments[numAppointments].date = now;
    appointments[numAppointments].duration = apptDuration;
    numAppointments++;

    printf("Appointment scheduled.\n");
}

void cancelAppointment(struct Appointment *appointments, int numAppointments) {
    printf("Enter name to cancel appointment: ");
    scanf("%s", appointments[0].name);
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, appointments[0].name) == 0) {
            appointments[i].date = 0;
            appointments[i].duration = 0;
            printf("Appointment cancelled.\n");
            return;
        }
    }
    printf("Appointment not found.\n");
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    addAppointment(appointments, numAppointments);
    addAppointment(appointments, numAppointments);

    displayAppointments(appointments, numAppointments);

    scheduleAppointment(appointments, numAppointments);
    displayAppointments(appointments, numAppointments);

    cancelAppointment(appointments, numAppointments);
    displayAppointments(appointments, numAppointments);

    return 0;
}