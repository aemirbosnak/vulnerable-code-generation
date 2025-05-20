//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Appointment {
    char *name;
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

typedef struct AppointmentScheduler {
    Appointment **appointments;
    int num_appointments;
    int capacity;
} AppointmentScheduler;

AppointmentScheduler *create_appointment_scheduler(int initial_capacity) {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->appointments = malloc(initial_capacity * sizeof(Appointment *));
    scheduler->num_appointments = 0;
    scheduler->capacity = initial_capacity;
    return scheduler;
}

void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]->name);
        free(scheduler->appointments[i]->description);
        free(scheduler->appointments[i]);
    }
    free(scheduler->appointments);
    free(scheduler);
}

int add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    if (scheduler->num_appointments == scheduler->capacity) {
        scheduler->appointments = realloc(scheduler->appointments, scheduler->capacity * 2 * sizeof(Appointment *));
        scheduler->capacity *= 2;
    }
    scheduler->appointments[scheduler->num_appointments++] = appointment;
    return 0;
}

int remove_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i] == appointment) {
            for (int j = i + 1; j < scheduler->num_appointments; j++) {
                scheduler->appointments[j - 1] = scheduler->appointments[j];
            }
            scheduler->num_appointments--;
            return 0;
        }
    }
    return -1;
}

int find_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i] == appointment) {
            return i;
        }
    }
    return -1;
}

void print_appointment_scheduler(AppointmentScheduler *scheduler) {
    printf("Appointments:\n");
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("  %s: %s from %s to %s\n",
            scheduler->appointments[i]->name,
            scheduler->appointments[i]->description,
            ctime(&scheduler->appointments[i]->start_time),
            ctime(&scheduler->appointments[i]->end_time)
        );
    }
}

int main() {
    AppointmentScheduler *scheduler = create_appointment_scheduler(10);

    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->name = strdup("Doctor's Appointment");
    appointment1->description = strdup("Checkup");
    appointment1->start_time = time(NULL) + 3600;  // 1 hour from now
    appointment1->end_time = appointment1->start_time + 3600;  // 1 hour later

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->name = strdup("Dentist Appointment");
    appointment2->description = strdup("Cleaning");
    appointment2->start_time = time(NULL) + 7200;  // 2 hours from now
    appointment2->end_time = appointment2->start_time + 3600;  // 1 hour later

    Appointment *appointment3 = malloc(sizeof(Appointment));
    appointment3->name = strdup("Haircut");
    appointment3->description = strdup("Trim");
    appointment3->start_time = time(NULL) + 10800;  // 3 hours from now
    appointment3->end_time = appointment3->start_time + 1800;  // 30 minutes later

    add_appointment(scheduler, appointment1);
    add_appointment(scheduler, appointment2);
    add_appointment(scheduler, appointment3);

    print_appointment_scheduler(scheduler);

    remove_appointment(scheduler, appointment2);

    print_appointment_scheduler(scheduler);

    destroy_appointment_scheduler(scheduler);

    return 0;
}