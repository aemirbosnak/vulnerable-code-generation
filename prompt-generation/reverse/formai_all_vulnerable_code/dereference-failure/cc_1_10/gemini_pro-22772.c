//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment struct
typedef struct Appointment {
    char name[50];
    char date[11];
    char time[6];
    char location[50];
    struct Appointment *next;
} Appointment;

// Appointment head
Appointment *head = NULL;

// Appointment tail
Appointment *tail = NULL;

// Function to create a new appointment
Appointment *create_appointment(char *name, char *date, char *time, char *location) {
    Appointment *new_appointment = (Appointment *)malloc(sizeof(Appointment));
    strcpy(new_appointment->name, name);
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);
    strcpy(new_appointment->location, location);
    new_appointment->next = NULL;
    return new_appointment;
}

// Function to add a new appointment to the schedule
void add_appointment(char *name, char *date, char *time, char *location) {
    Appointment *new_appointment = create_appointment(name, date, time, location);
    if (head == NULL) {
        head = new_appointment;
        tail = new_appointment;
    } else {
        tail->next = new_appointment;
        tail = new_appointment;
    }
}

// Function to remove an appointment from the schedule
void remove_appointment(char *name, char *date, char *time) {
    Appointment *current_appointment = head;
    Appointment *previous_appointment = NULL;

    while (current_appointment != NULL) {
        if (strcmp(current_appointment->name, name) == 0 && strcmp(current_appointment->date, date) == 0 && strcmp(current_appointment->time, time) == 0) {
            if (previous_appointment == NULL) {
                head = current_appointment->next;
            } else {
                previous_appointment->next = current_appointment->next;
            }
            free(current_appointment);
            break;
        }
        previous_appointment = current_appointment;
        current_appointment = current_appointment->next;
    }
}

// Function to print the schedule
void print_schedule() {
    Appointment *current_appointment = head;

    while (current_appointment != NULL) {
        printf("%s %s %s %s\n", current_appointment->name, current_appointment->date, current_appointment->time, current_appointment->location);
        current_appointment = current_appointment->next;
    }
}

// Main function
int main() {
    // Add some appointments to the schedule
    add_appointment("John Doe", "2023-03-08", "10:00 AM", "Room 101");
    add_appointment("Jane Doe", "2023-03-09", "11:00 AM", "Room 102");
    add_appointment("John Smith", "2023-03-10", "12:00 PM", "Room 103");

    // Print the schedule
    printf("Schedule:\n");
    print_schedule();

    // Remove an appointment from the schedule
    remove_appointment("John Doe", "2023-03-08", "10:00 AM");

    // Print the schedule again
    printf("\nUpdated schedule:\n");
    print_schedule();

    return 0;
}