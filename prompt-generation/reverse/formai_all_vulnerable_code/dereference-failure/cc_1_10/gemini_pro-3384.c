//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct AppointmentScheduler {
    struct Appointment *appointments;
    int numAppointments;
};

struct AppointmentScheduler* createAppointmentScheduler() {
    struct AppointmentScheduler *scheduler = malloc(sizeof(struct AppointmentScheduler));
    scheduler->appointments = NULL;
    scheduler->numAppointments = 0;
    return scheduler;
}

void addAppointment(struct AppointmentScheduler *scheduler, char *description, int day, int month, int year, int hour, int minute) {
    scheduler->appointments = realloc(scheduler->appointments, (scheduler->numAppointments + 1) * sizeof(struct Appointment));
    scheduler->appointments[scheduler->numAppointments].description = strdup(description);
    scheduler->appointments[scheduler->numAppointments].day = day;
    scheduler->appointments[scheduler->numAppointments].month = month;
    scheduler->appointments[scheduler->numAppointments].year = year;
    scheduler->appointments[scheduler->numAppointments].hour = hour;
    scheduler->appointments[scheduler->numAppointments].minute = minute;
    scheduler->numAppointments++;
}

void printAppointments(struct AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        printf("%s: %d/%d/%d, %d:%d\n", scheduler->appointments[i].description,
               scheduler->appointments[i].day, scheduler->appointments[i].month, scheduler->appointments[i].year,
               scheduler->appointments[i].hour, scheduler->appointments[i].minute);
    }
}

void freeAppointmentScheduler(struct AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        free(scheduler->appointments[i].description);
    }
    free(scheduler->appointments);
    free(scheduler);
}

int main() {
    struct AppointmentScheduler *scheduler = createAppointmentScheduler();

    addAppointment(scheduler, "Doctor's appointment", 15, 3, 2023, 10, 30);
    addAppointment(scheduler, "Dentist appointment", 18, 4, 2023, 14, 0);
    addAppointment(scheduler, "Haircut", 25, 5, 2023, 16, 30);

    printAppointments(scheduler);

    freeAppointmentScheduler(scheduler);

    return 0;
}