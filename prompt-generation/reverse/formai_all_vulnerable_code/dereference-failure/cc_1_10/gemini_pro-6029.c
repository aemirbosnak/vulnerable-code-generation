//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char name[50];
    char date[20];
    char time[20];
    char description[100];
} appointment;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler;

// Create a new appointment scheduler
appointment_scheduler *create_appointment_scheduler() {
    appointment_scheduler *scheduler = malloc(sizeof(appointment_scheduler));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler *scheduler, appointment *new_appointment) {
    if (scheduler->num_appointments == MAX_APPOINTMENTS) {
        printf("Error: The appointment scheduler is full.\n");
        return;
    }
    scheduler->appointments[scheduler->num_appointments++] = *new_appointment;
}

// Remove an appointment from the scheduler
void remove_appointment(appointment_scheduler *scheduler, int index) {
    if (index < 0 || index >= scheduler->num_appointments) {
        printf("Error: Invalid appointment index.\n");
        return;
    }
    for (int i = index; i < scheduler->num_appointments - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }
    scheduler->num_appointments--;
}

// Find an appointment by name
appointment *find_appointment_by_name(appointment_scheduler *scheduler, char *name) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].name, name) == 0) {
            return &scheduler->appointments[i];
        }
    }
    return NULL;
}

// Find an appointment by date
appointment *find_appointment_by_date(appointment_scheduler *scheduler, char *date) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].date, date) == 0) {
            return &scheduler->appointments[i];
        }
    }
    return NULL;
}

// Find an appointment by time
appointment *find_appointment_by_time(appointment_scheduler *scheduler, char *time) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].time, time) == 0) {
            return &scheduler->appointments[i];
        }
    }
    return NULL;
}

// Print the appointment scheduler
void print_appointment_scheduler(appointment_scheduler *scheduler) {
    printf("Appointments:\n");
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s, %s, %s, %s\n", scheduler->appointments[i].name, scheduler->appointments[i].date, scheduler->appointments[i].time, scheduler->appointments[i].description);
    }
}

// Main function
int main() {
    // Create a new appointment scheduler
    appointment_scheduler *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    appointment appointment1 = {"John Doe", "2023-03-08", "10:00 AM", "Meeting with the boss"};
    add_appointment(scheduler, &appointment1);
    appointment appointment2 = {"Jane Doe", "2023-03-09", "11:00 AM", "Meeting with the team"};
    add_appointment(scheduler, &appointment2);
    appointment appointment3 = {"John Smith", "2023-03-10", "12:00 PM", "Meeting with the client"};
    add_appointment(scheduler, &appointment3);

    // Print the appointment scheduler
    print_appointment_scheduler(scheduler);

    // Find an appointment by name
    appointment *appointment = find_appointment_by_name(scheduler, "John Doe");
    if (appointment != NULL) {
        printf("Found appointment: %s, %s, %s, %s\n", appointment->name, appointment->date, appointment->time, appointment->description);
    } else {
        printf("Appointment not found.\n");
    }

    // Remove an appointment
    remove_appointment(scheduler, 1);

    // Print the appointment scheduler again
    print_appointment_scheduler(scheduler);

    // Free the memory allocated for the appointment scheduler
    free(scheduler);

    return 0;
}