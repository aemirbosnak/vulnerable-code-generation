//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char *title;
    char *location;
    char *date;
    char *time;
} appointment_t;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
    appointment_t *appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler_t;

// Create a new appointment scheduler
appointment_scheduler_t *create_appointment_scheduler() {
    appointment_scheduler_t *scheduler = malloc(sizeof(appointment_scheduler_t));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler_t *scheduler, appointment_t *appointment) {
    if (scheduler->num_appointments < MAX_APPOINTMENTS) {
        scheduler->appointments[scheduler->num_appointments] = appointment;
        scheduler->num_appointments++;
    } else {
        printf("Error: The appointment scheduler is full.\n");
    }
}

// Remove an appointment from the scheduler
void remove_appointment(appointment_scheduler_t *scheduler, appointment_t *appointment) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i] == appointment) {
            scheduler->appointments[i] = NULL;
            scheduler->num_appointments--;
            break;
        }
    }
}

// Find an appointment in the scheduler
appointment_t *find_appointment(appointment_scheduler_t *scheduler, char *title) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i]->title, title) == 0) {
            return scheduler->appointments[i];
        }
    }
    return NULL;
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler_t *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s\n", scheduler->appointments[i]->title);
    }
}

// Free the memory allocated for the appointment scheduler
void free_appointment_scheduler(appointment_scheduler_t *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]);
    }
    free(scheduler);
}

// Main function
int main() {
    // Create an appointment scheduler
    appointment_scheduler_t *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    appointment_t *appointment1 = malloc(sizeof(appointment_t));
    appointment1->title = "Meeting with Bob";
    appointment1->location = "Conference Room A";
    appointment1->date = "2023-03-08";
    appointment1->time = "10:00 AM";
    add_appointment(scheduler, appointment1);

    appointment_t *appointment2 = malloc(sizeof(appointment_t));
    appointment2->title = "Lunch with Alice";
    appointment2->location = "The Grill";
    appointment2->date = "2023-03-09";
    appointment2->time = "12:00 PM";
    add_appointment(scheduler, appointment2);

    appointment_t *appointment3 = malloc(sizeof(appointment_t));
    appointment3->title = "Phone call with Charlie";
    appointment3->location = "My office";
    appointment3->date = "2023-03-10";
    appointment3->time = "2:00 PM";
    add_appointment(scheduler, appointment3);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, appointment2);

    // Print the appointments in the scheduler again
    print_appointments(scheduler);

    // Free the memory allocated for the appointment scheduler
    free_appointment_scheduler(scheduler);

    return 0;
}