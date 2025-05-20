//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct {
    char name[50];
    char date[11];
    char time[6];
    int duration;
} Appointment;

// Define the appointment scheduler
typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler* create_appointment_scheduler() {
    AppointmentScheduler* scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler* scheduler, Appointment appointment) {
    scheduler->appointments[scheduler->num_appointments++] = appointment;
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler* scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s %s %s %d\n", scheduler->appointments[i].name, scheduler->appointments[i].date, scheduler->appointments[i].time, scheduler->appointments[i].duration);
    }
}

// Find an appointment by name
Appointment* find_appointment_by_name(AppointmentScheduler* scheduler, char* name) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].name, name) == 0) {
            return &scheduler->appointments[i];
        }
    }
    return NULL;
}

// Find an appointment by date
Appointment* find_appointment_by_date(AppointmentScheduler* scheduler, char* date) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].date, date) == 0) {
            return &scheduler->appointments[i];
        }
    }
    return NULL;
}

// Find an appointment by time
Appointment* find_appointment_by_time(AppointmentScheduler* scheduler, char* time) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].time, time) == 0) {
            return &scheduler->appointments[i];
        }
    }
    return NULL;
}

// Delete an appointment by name
void delete_appointment_by_name(AppointmentScheduler* scheduler, char* name) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].name, name) == 0) {
            scheduler->appointments[i] = scheduler->appointments[scheduler->num_appointments - 1];
            scheduler->num_appointments--;
            return;
        }
    }
}

// Delete an appointment by date
void delete_appointment_by_date(AppointmentScheduler* scheduler, char* date) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].date, date) == 0) {
            scheduler->appointments[i] = scheduler->appointments[scheduler->num_appointments - 1];
            scheduler->num_appointments--;
            return;
        }
    }
}

// Delete an appointment by time
void delete_appointment_by_time(AppointmentScheduler* scheduler, char* time) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].time, time) == 0) {
            scheduler->appointments[i] = scheduler->appointments[scheduler->num_appointments - 1];
            scheduler->num_appointments--;
            return;
        }
    }
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler* scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    add_appointment(scheduler, (Appointment) {"John Doe", "2023-03-08", "10:00", 60});
    add_appointment(scheduler, (Appointment) {"Jane Doe", "2023-03-09", "11:00", 30});
    add_appointment(scheduler, (Appointment) {"John Smith", "2023-03-10", "12:00", 45});

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Find an appointment by name
    Appointment* appointment = find_appointment_by_name(scheduler, "John Doe");
    if (appointment != NULL) {
        printf("Found appointment for %s: %s %s %d\n", appointment->name, appointment->date, appointment->time, appointment->duration);
    } else {
        printf("Appointment not found.\n");
    }

    // Find an appointment by date
    appointment = find_appointment_by_date(scheduler, "2023-03-09");
    if (appointment != NULL) {
        printf("Found appointment for %s: %s %s %d\n", appointment->name, appointment->date, appointment->time, appointment->duration);
    } else {
        printf("Appointment not found.\n");
    }

    // Find an appointment by time
    appointment = find_appointment_by_time(scheduler, "11:00");
    if (appointment != NULL) {
        printf("Found appointment for %s: %s %s %d\n", appointment->name, appointment->date, appointment->time, appointment->duration);
    } else {
        printf("Appointment not found.\n");
    }

    // Delete an appointment by name
    delete_appointment_by_name(scheduler, "John Doe");

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Free the appointment scheduler
    free(scheduler);

    return 0;
}