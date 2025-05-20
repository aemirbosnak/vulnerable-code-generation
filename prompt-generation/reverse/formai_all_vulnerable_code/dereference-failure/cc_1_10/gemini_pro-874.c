//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char description[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler;

// Create a new appointment scheduler
appointment_scheduler* create_appointment_scheduler() {
    appointment_scheduler* scheduler = (appointment_scheduler*)malloc(sizeof(appointment_scheduler));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler* scheduler, char* description, int day, int month, int year, int hour, int minute) {
    // Check if the scheduler is full
    if (scheduler->num_appointments == MAX_APPOINTMENTS) {
        printf("Error: The appointment scheduler is full.\n");
        return;
    }

    // Create a new appointment
    appointment new_appointment;
    strcpy(new_appointment.description, description);
    new_appointment.day = day;
    new_appointment.month = month;
    new_appointment.year = year;
    new_appointment.hour = hour;
    new_appointment.minute = minute;

    // Add the new appointment to the scheduler
    scheduler->appointments[scheduler->num_appointments] = new_appointment;
    scheduler->num_appointments++;
}

// Remove an appointment from the scheduler
void remove_appointment(appointment_scheduler* scheduler, int index) {
    // Check if the index is valid
    if (index < 0 || index >= scheduler->num_appointments) {
        printf("Error: The index is invalid.\n");
        return;
    }

    // Remove the appointment from the scheduler
    for (int i = index; i < scheduler->num_appointments - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }

    // Decrement the number of appointments
    scheduler->num_appointments--;
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler* scheduler) {
    // Check if the scheduler is empty
    if (scheduler->num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    // Print the appointments
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%d. %s - %d/%d/%d %d:%d\n", i + 1, scheduler->appointments[i].description, scheduler->appointments[i].day, scheduler->appointments[i].month, scheduler->appointments[i].year, scheduler->appointments[i].hour, scheduler->appointments[i].minute);
    }
}

// Get the current date and time
void get_current_date_and_time(int* day, int* month, int* year, int* hour, int* minute) {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    *day = tm->tm_mday;
    *month = tm->tm_mon + 1;
    *year = tm->tm_year + 1900;
    *hour = tm->tm_hour;
    *minute = tm->tm_min;
}

// Main function
int main() {
    // Create an appointment scheduler
    appointment_scheduler* scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    add_appointment(scheduler, "Dentist appointment", 10, 3, 2023, 9, 0);
    add_appointment(scheduler, "Doctor's appointment", 15, 3, 2023, 10, 30);
    add_appointment(scheduler, "Meeting with boss", 20, 3, 2023, 14, 0);

    // Print the appointments
    print_appointments(scheduler);

    // Get the current date and time
    int day, month, year, hour, minute;
    get_current_date_and_time(&day, &month, &year, &hour, &minute);

    // Check if there are any appointments today
    int found = 0;
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i].day == day && scheduler->appointments[i].month == month && scheduler->appointments[i].year == year) {
            found = 1;
            break;
        }
    }

    // Print a message if there are no appointments today
    if (!found) {
        printf("No appointments scheduled for today.\n");
    }

    // Free the memory allocated for the scheduler
    free(scheduler);

    return 0;
}