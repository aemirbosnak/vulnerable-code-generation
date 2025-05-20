//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char *name;
    char *description;
    int start_time;
    int end_time;
} appointment;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
    appointment *appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler;

// Create a new appointment scheduler
appointment_scheduler *create_appointment_scheduler() {
    appointment_scheduler *scheduler = malloc(sizeof(appointment_scheduler));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler *scheduler, appointment *appointment) {
    scheduler->appointments[scheduler->num_appointments] = appointment;
    scheduler->num_appointments++;
}

// Remove an appointment from the scheduler
void remove_appointment(appointment_scheduler *scheduler, appointment *appointment) {
    int i;
    for (i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i] == appointment) {
            scheduler->appointments[i] = scheduler->appointments[scheduler->num_appointments - 1];
            scheduler->num_appointments--;
            break;
        }
    }
}

// Find an appointment by name
appointment *find_appointment_by_name(appointment_scheduler *scheduler, char *name) {
    int i;
    for (i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i]->name, name) == 0) {
            return scheduler->appointments[i];
        }
    }
    return NULL;
}

// Find an appointment by description
appointment *find_appointment_by_description(appointment_scheduler *scheduler, char *description) {
    int i;
    for (i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i]->description, description) == 0) {
            return scheduler->appointments[i];
        }
    }
    return NULL;
}

// Find an appointment by start time
appointment *find_appointment_by_start_time(appointment_scheduler *scheduler, int start_time) {
    int i;
    for (i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i]->start_time == start_time) {
            return scheduler->appointments[i];
        }
    }
    return NULL;
}

// Find an appointment by end time
appointment *find_appointment_by_end_time(appointment_scheduler *scheduler, int end_time) {
    int i;
    for (i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i]->end_time == end_time) {
            return scheduler->appointments[i];
        }
    }
    return NULL;
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler *scheduler) {
    int i;
    for (i = 0; i < scheduler->num_appointments; i++) {
        printf("%s, %s, %d, %d\n", scheduler->appointments[i]->name, scheduler->appointments[i]->description, scheduler->appointments[i]->start_time, scheduler->appointments[i]->end_time);
    }
}

// Free the memory allocated for the scheduler
void free_appointment_scheduler(appointment_scheduler *scheduler) {
    int i;
    for (i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]);
    }
    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    appointment_scheduler *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    appointment *appointment1 = malloc(sizeof(appointment));
    appointment1->name = "John Doe";
    appointment1->description = "Meeting with the boss";
    appointment1->start_time = 1000;
    appointment1->end_time = 1100;
    add_appointment(scheduler, appointment1);

    appointment *appointment2 = malloc(sizeof(appointment));
    appointment2->name = "Jane Doe";
    appointment2->description = "Lunch with a friend";
    appointment2->start_time = 1200;
    appointment2->end_time = 1300;
    add_appointment(scheduler, appointment2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Find an appointment by name
    appointment *appointment3 = find_appointment_by_name(scheduler, "John Doe");
    printf("Found appointment: %s, %s, %d, %d\n", appointment3->name, appointment3->description, appointment3->start_time, appointment3->end_time);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, appointment1);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Free the memory allocated for the scheduler
    free_appointment_scheduler(scheduler);

    return 0;
}