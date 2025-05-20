//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Appointment struct
typedef struct Appointment {
    char name[50];
    char description[100];
    time_t start_time;
    time_t end_time;
} Appointment;

// Appointment list struct
typedef struct AppointmentList {
    Appointment *appointments;
    int size;
    int capacity;
} AppointmentList;

// Initialize an appointment list
AppointmentList *initialize_list() {
    AppointmentList *list = (AppointmentList *)malloc(sizeof(AppointmentList));
    list->appointments = (Appointment *)malloc(sizeof(Appointment) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

// Add an appointment to the list
void add_appointment(AppointmentList *list, Appointment *app) {
    if (list->size == list->capacity) {
        list->appointments = (Appointment *)realloc(list->appointments, sizeof(Appointment) * (list->capacity * 2));
        list->capacity *= 2;
    }
    list->appointments[list->size++] = *app;
}

// Print the appointments in the list
void print_appointments(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        Appointment app = list->appointments[i];
        printf("Appointment: %s\n", app.name);
        printf("Description: %s\n", app.description);
        printf("Start time: %s\n", ctime(&app.start_time));
        printf("End time: %s\n", ctime(&app.end_time));
        printf("\n");
    }
}

// Free the memory allocated for the list
void free_list(AppointmentList *list) {
    free(list->appointments);
    free(list);
}

// Main function
int main() {
    // Initialize the appointment list
    AppointmentList *list = initialize_list();

    // Create some appointments
    Appointment app1 = {"John Doe", "Meeting with the client", time(NULL) + 3600, time(NULL) + 7200};
    Appointment app2 = {"Jane Doe", "Doctor's appointment", time(NULL) + 10800, time(NULL) + 12600};
    Appointment app3 = {"Peter Jones", "Lunch with friends", time(NULL) + 14400, time(NULL) + 16200};

    // Add the appointments to the list
    add_appointment(list, &app1);
    add_appointment(list, &app2);
    add_appointment(list, &app3);

    // Print the appointments
    print_appointments(list);

    // Free the memory allocated for the list
    free_list(list);

    return 0;
}