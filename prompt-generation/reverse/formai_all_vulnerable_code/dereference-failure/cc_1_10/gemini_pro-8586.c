//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char *start_time;
    char *end_time;
    char *doctor;
    char *patient;
    int consulted;
};

struct day {
    struct appointment *appointments[24];
};

struct month {
    struct day days[31];
};

struct year {
    struct month months[12];
};

struct appointment_scheduler {
    struct year years[10];
};

int main() {
    struct appointment_scheduler *scheduler = malloc(sizeof(struct appointment_scheduler));

    // Create an appointment for John Doe with Dr. Smith on January 1, 2023 at 10:00 AM
    struct appointment *appointment = malloc(sizeof(struct appointment));
    appointment->start_time = "10:00 AM";
    appointment->end_time = "11:00 AM";
    appointment->doctor = "Dr. Smith";
    appointment->patient = "John Doe";
    appointment->consulted = 0;

    // Add the appointment to the scheduler
    scheduler->years[0].months[0].days[0].appointments[10] = appointment;

    // Print the appointment details
    printf("Appointment details:\n");
    printf("Start Time: %s\n", appointment->start_time);
    printf("End Time: %s\n", appointment->end_time);
    printf("Doctor: %s\n", appointment->doctor);
    printf("Patient: %s\n", appointment->patient);
    printf("Consulted: %d\n", appointment->consulted);

    return 0;
}