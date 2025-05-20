//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
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

struct AppointmentScheduler *createAppointmentScheduler() {
    struct AppointmentScheduler *scheduler = malloc(sizeof(struct AppointmentScheduler));
    scheduler->appointments = NULL;
    scheduler->numAppointments = 0;
    return scheduler;
}

void destroyAppointmentScheduler(struct AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        free(scheduler->appointments[i].description);
    }
    free(scheduler->appointments);
    free(scheduler);
}

void addAppointment(struct AppointmentScheduler *scheduler, struct Appointment appointment) {
    scheduler->appointments = realloc(scheduler->appointments, (scheduler->numAppointments + 1) * sizeof(struct Appointment));
    scheduler->appointments[scheduler->numAppointments] = appointment;
    scheduler->numAppointments++;
}

void printAppointments(struct AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        printf("%s: %d/%d/%d %d:%d\n", scheduler->appointments[i].description, scheduler->appointments[i].day, scheduler->appointments[i].month, scheduler->appointments[i].year, scheduler->appointments[i].hour, scheduler->appointments[i].minute);
    }
}

int main() {
    struct AppointmentScheduler *scheduler = createAppointmentScheduler();

    struct Appointment appointment1 = {
        .description = "Doctor's appointment",
        .day = 15,
        .month = 3,
        .year = 2023,
        .hour = 10,
        .minute = 30
    };

    struct Appointment appointment2 = {
        .description = "Dentist appointment",
        .day = 22,
        .month = 3,
        .year = 2023,
        .hour = 14,
        .minute = 0
    };

    addAppointment(scheduler, appointment1);
    addAppointment(scheduler, appointment2);

    printAppointments(scheduler);

    destroyAppointmentScheduler(scheduler);

    return 0;
}