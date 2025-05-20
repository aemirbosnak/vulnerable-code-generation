//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char *description;
    time_t start_time;
    time_t end_time;
};

struct appointment_scheduler {
    struct appointment *appointments[MAX_APPOINTMENTS];
    int num_appointments;
};

struct appointment_scheduler *create_appointment_scheduler() {
    struct appointment_scheduler *scheduler = malloc(sizeof(struct appointment_scheduler));
    scheduler->num_appointments = 0;
    return scheduler;
}

void destroy_appointment_scheduler(struct appointment_scheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]->description);
        free(scheduler->appointments[i]);
    }
    free(scheduler);
}

int add_appointment(struct appointment_scheduler *scheduler, char *description, time_t start_time, time_t end_time) {
    if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
        return -1;
    }

    struct appointment *appointment = malloc(sizeof(struct appointment));
    appointment->description = strdup(description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;

    scheduler->appointments[scheduler->num_appointments++] = appointment;

    return 0;
}

void print_appointments(struct appointment_scheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s: %s - %s\n", scheduler->appointments[i]->description, ctime(&scheduler->appointments[i]->start_time), ctime(&scheduler->appointments[i]->end_time));
    }
}

int main() {
    struct appointment_scheduler *scheduler = create_appointment_scheduler();

    add_appointment(scheduler, "Meeting with the client", time(NULL) + 3600, time(NULL) + 4800);
    add_appointment(scheduler, "Conference call with the team", time(NULL) + 7200, time(NULL) + 8400);
    add_appointment(scheduler, "Lunch with the boss", time(NULL) + 10800, time(NULL) + 12000);

    print_appointments(scheduler);

    destroy_appointment_scheduler(scheduler);

    return 0;
}