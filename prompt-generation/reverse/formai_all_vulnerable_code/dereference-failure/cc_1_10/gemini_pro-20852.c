//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Appointment {
    char *name;
    char *description;
    time_t start_time;
    time_t end_time;
};

struct AppointmentScheduler {
    struct Appointment *appointments;
    int num_appointments;
    int max_appointments;
};

struct AppointmentScheduler *create_appointment_scheduler(int max_appointments) {
    struct AppointmentScheduler *scheduler = malloc(sizeof(struct AppointmentScheduler));
    scheduler->appointments = malloc(max_appointments * sizeof(struct Appointment));
    scheduler->num_appointments = 0;
    scheduler->max_appointments = max_appointments;
    return scheduler;
}

void destroy_appointment_scheduler(struct AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i].name);
        free(scheduler->appointments[i].description);
    }
    free(scheduler->appointments);
    free(scheduler);
}

int add_appointment(struct AppointmentScheduler *scheduler, struct Appointment *appointment) {
    if (scheduler->num_appointments == scheduler->max_appointments) {
        return -1;
    }
    scheduler->appointments[scheduler->num_appointments++] = *appointment;
    return 0;
}

int remove_appointment(struct AppointmentScheduler *scheduler, struct Appointment *appointment) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (&scheduler->appointments[i] == appointment) {
            scheduler->appointments[i] = scheduler->appointments[scheduler->num_appointments - 1];
            scheduler->num_appointments--;
            return 0;
        }
    }
    return -1;
}

void print_appointment(struct Appointment *appointment) {
    printf("Appointment:\n");
    printf("  Name: %s\n", appointment->name);
    printf("  Description: %s\n", appointment->description);
    printf("  Start time: %s\n", ctime(&appointment->start_time));
    printf("  End time: %s\n", ctime(&appointment->end_time));
}

void print_appointment_scheduler(struct AppointmentScheduler *scheduler) {
    printf("Appointment Scheduler:\n");
    for (int i = 0; i < scheduler->num_appointments; i++) {
        print_appointment(&scheduler->appointments[i]);
    }
}

int main() {
    struct AppointmentScheduler *scheduler = create_appointment_scheduler(10);

    struct Appointment appointment1 = {
        .name = "Doctor's appointment",
        .description = "Annual checkup",
        .start_time = time(NULL) + 3600,
        .end_time = time(NULL) + 4200,
    };

    struct Appointment appointment2 = {
        .name = "Lunch with friends",
        .description = "Catching up",
        .start_time = time(NULL) + 7200,
        .end_time = time(NULL) + 8400,
    };

    add_appointment(scheduler, &appointment1);
    add_appointment(scheduler, &appointment2);

    print_appointment_scheduler(scheduler);

    remove_appointment(scheduler, &appointment1);

    print_appointment_scheduler(scheduler);

    destroy_appointment_scheduler(scheduler);

    return 0;
}