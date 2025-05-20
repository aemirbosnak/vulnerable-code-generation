//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60

typedef struct {
    int hour;
    int minute;
    char *description;
} Appointment;

void add_appointment(Appointment *appointments, int num_appointments, int hour, int minute, char *description) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    int index = num_appointments;
    while (index > 0 && appointments[index - 1].hour > hour) {
        appointments[index] = appointments[index - 1];
        index--;
    }

    appointments[index].hour = hour;
    appointments[index].minute = minute;
    appointments[index].description = description;
    num_appointments++;
}

void print_appointments(Appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%02d:%02d - %s\n", appointments[i].hour, appointments[i].minute, appointments[i].description);
    }
}

int main() {
    time_t now = time(NULL);
    struct tm *time_info = localtime(&now);

    int hour = time_info->tm_hour;
    int minute = time_info->tm_min;

    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments, 9, 0, "Meeting with boss");
    add_appointment(appointments, num_appointments, 12, 0, "Lunch with coworkers");
    add_appointment(appointments, num_appointments, 15, 0, "Deadline for project");

    print_appointments(appointments, num_appointments);

    return 0;
}