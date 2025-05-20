//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char *name;
    char *phone;
    char *email;
    char *time;
    char *date;
    char *notes;
} Appointment;

typedef struct {
    Appointment **appointments;
    int size;
} AppointmentList;

void createAppointment(AppointmentList *list, char *name, char *phone, char *email, char *time, char *date, char *notes) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->phone = strdup(phone);
    appointment->email = strdup(email);
    appointment->time = strdup(time);
    appointment->date = strdup(date);
    appointment->notes = strdup(notes);
    list->appointments[list->size++] = appointment;
}

void printAppointment(Appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Phone: %s\n", appointment->phone);
    printf("Email: %s\n", appointment->email);
    printf("Time: %s\n", appointment->time);
    printf("Date: %s\n", appointment->date);
    printf("Notes: %s\n\n", appointment->notes);
}

void printAppointmentList(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        printAppointment(list->appointments[i]);
    }
}

void freeAppointment(Appointment *appointment) {
    free(appointment->name);
    free(appointment->phone);
    free(appointment->email);
    free(appointment->time);
    free(appointment->date);
    free(appointment->notes);
    free(appointment);
}

void freeAppointmentList(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        freeAppointment(list->appointments[i]);
    }
    free(list->appointments);
    free(list);
}

int main() {
    AppointmentList *list = malloc(sizeof(AppointmentList));
    list->appointments = malloc(sizeof(Appointment *) * 10);
    list->size = 0;

    // Create some appointments
    createAppointment(list, "Alice", "555-1212", "alice@example.com", "10:00 AM", "2023-03-08", "Morning checkup");
    createAppointment(list, "Bob", "555-1213", "bob@example.com", "11:00 AM", "2023-03-08", "Afternoon checkup");
    createAppointment(list, "Charlie", "555-1214", "charlie@example.com", "12:00 PM", "2023-03-08", "Evening checkup");

    // Print the appointments
    printAppointmentList(list);

    // Free the appointments
    freeAppointmentList(list);

    return 0;
}