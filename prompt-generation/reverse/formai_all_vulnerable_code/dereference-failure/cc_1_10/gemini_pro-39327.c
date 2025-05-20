//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: modular
// Appointment Scheduler in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct Appointment {
    char *name;
    char *time;
    char *date;
    char *notes;
} Appointment;

typedef struct AppointmentList {
    Appointment *appointments;
    int size;
    int capacity;
} AppointmentList;

// Function prototypes
AppointmentList *create_appointment_list(int capacity);
void add_appointment(AppointmentList *list, Appointment *appointment);
void print_appointment(Appointment *appointment);
void print_appointment_list(AppointmentList *list);
void free_appointment_list(AppointmentList *list);

// Main function
int main() {
    // Create an empty appointment list
    AppointmentList *list = create_appointment_list(10);

    // Add some appointments to the list
    Appointment *appointment1 = (Appointment *)malloc(sizeof(Appointment));
    appointment1->name = "John Doe";
    appointment1->time = "10:00 AM";
    appointment1->date = "2023-03-08";
    appointment1->notes = "Initial consultation";
    add_appointment(list, appointment1);

    Appointment *appointment2 = (Appointment *)malloc(sizeof(Appointment));
    appointment2->name = "Jane Doe";
    appointment2->time = "11:00 AM";
    appointment2->date = "2023-03-08";
    appointment2->notes = "Follow-up appointment";
    add_appointment(list, appointment2);

    // Print the list of appointments
    print_appointment_list(list);

    // Free the appointment list
    free_appointment_list(list);

    return 0;
}

// Function definitions

// Create an empty appointment list with the specified capacity
AppointmentList *create_appointment_list(int capacity) {
    AppointmentList *list = (AppointmentList *)malloc(sizeof(AppointmentList));
    list->appointments = (Appointment *)malloc(sizeof(Appointment) * capacity);
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// Add an appointment to the list
void add_appointment(AppointmentList *list, Appointment *appointment) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->appointments = (Appointment *)realloc(list->appointments, sizeof(Appointment) * list->capacity);
    }
    list->appointments[list->size] = *appointment;
    list->size++;
}

// Print an appointment
void print_appointment(Appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Time: %s\n", appointment->time);
    printf("Date: %s\n", appointment->date);
    printf("Notes: %s\n\n", appointment->notes);
}

// Print the list of appointments
void print_appointment_list(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        print_appointment(&list->appointments[i]);
    }
}

// Free the memory allocated for the appointment list
void free_appointment_list(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->appointments[i].name);
        free(list->appointments[i].time);
        free(list->appointments[i].date);
        free(list->appointments[i].notes);
    }
    free(list->appointments);
    free(list);
}