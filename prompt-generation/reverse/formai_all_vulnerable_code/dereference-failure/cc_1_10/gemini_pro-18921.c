//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    int id;
    char *name;
    char *description;
    int start_time;
    int end_time;
} Appointment;

typedef struct AppointmentScheduler {
    Appointment *appointments;
    int num_appointments;
} AppointmentScheduler;

AppointmentScheduler *create_appointment_scheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->appointments = NULL;
    scheduler->num_appointments = 0;
    return scheduler;
}

void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i].name);
        free(scheduler->appointments[i].description);
    }
    free(scheduler->appointments);
    free(scheduler);
}

int add_appointment(AppointmentScheduler *scheduler, Appointment appointment) {
    scheduler->appointments = realloc(scheduler->appointments, (scheduler->num_appointments + 1) * sizeof(Appointment));
    scheduler->appointments[scheduler->num_appointments] = appointment;
    scheduler->num_appointments++;
    return 0;
}

int remove_appointment(AppointmentScheduler *scheduler, int id) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i].id == id) {
            for (int j = i; j < scheduler->num_appointments - 1; j++) {
                scheduler->appointments[j] = scheduler->appointments[j + 1];
            }
            scheduler->num_appointments--;
            return 0;
        }
    }
    return -1;
}

Appointment *get_appointment(AppointmentScheduler *scheduler, int id) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i].id == id) {
            return &scheduler->appointments[i];
        }
    }
    return NULL;
}

int main() {
    AppointmentScheduler *scheduler = create_appointment_scheduler();

    Appointment appointment1 = {
        .id = 1,
        .name = "John Doe",
        .description = "Meeting to discuss project",
        .start_time = 1000,
        .end_time = 1100
    };

    Appointment appointment2 = {
        .id = 2,
        .name = "Jane Doe",
        .description = "Meeting to discuss marketing",
        .start_time = 1200,
        .end_time = 1300
    };

    add_appointment(scheduler, appointment1);
    add_appointment(scheduler, appointment2);

    Appointment *appointment = get_appointment(scheduler, 1);
    printf("Appointment: %s, %s, %d, %d\n", appointment->name, appointment->description, appointment->start_time, appointment->end_time);

    remove_appointment(scheduler, 1);

    destroy_appointment_scheduler(scheduler);

    return 0;
}