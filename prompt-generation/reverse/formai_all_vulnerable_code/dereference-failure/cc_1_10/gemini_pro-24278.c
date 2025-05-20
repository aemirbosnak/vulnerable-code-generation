//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment structure
typedef struct Appointment {
    char *name;
    char *date;
    char *time;
    char *location;
    char *description;
} Appointment;

// Appointment book structure
typedef struct AppointmentBook {
    int numAppointments;
    Appointment **appointments;
} AppointmentBook;

// Function to create a new appointment
Appointment *createAppointment(char *name, char *date, char *time, char *location, char *description) {
    Appointment *newAppointment = malloc(sizeof(Appointment));
    newAppointment->name = malloc(strlen(name) + 1);
    strcpy(newAppointment->name, name);
    newAppointment->date = malloc(strlen(date) + 1);
    strcpy(newAppointment->date, date);
    newAppointment->time = malloc(strlen(time) + 1);
    strcpy(newAppointment->time, time);
    newAppointment->location = malloc(strlen(location) + 1);
    strcpy(newAppointment->location, location);
    newAppointment->description = malloc(strlen(description) + 1);
    strcpy(newAppointment->description, description);
    return newAppointment;
}

// Function to add an appointment to the appointment book
void addAppointment(AppointmentBook *book, Appointment *appointment) {
    book->appointments = realloc(book->appointments, sizeof(Appointment *) * (book->numAppointments + 1));
    book->appointments[book->numAppointments++] = appointment;
}

// Function to print the appointment book
void printAppointmentBook(AppointmentBook *book) {
    for (int i = 0; i < book->numAppointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", book->appointments[i]->name);
        printf("Date: %s\n", book->appointments[i]->date);
        printf("Time: %s\n", book->appointments[i]->time);
        printf("Location: %s\n", book->appointments[i]->location);
        printf("Description: %s\n", book->appointments[i]->description);
        printf("\n");
    }
}

// Function to free the memory allocated for the appointment book
void freeAppointmentBook(AppointmentBook *book) {
    for (int i = 0; i < book->numAppointments; i++) {
        free(book->appointments[i]->name);
        free(book->appointments[i]->date);
        free(book->appointments[i]->time);
        free(book->appointments[i]->location);
        free(book->appointments[i]->description);
        free(book->appointments[i]);
    }
    free(book->appointments);
    free(book);
}

// Main function
int main() {
    // Create a new appointment book
    AppointmentBook *book = malloc(sizeof(AppointmentBook));
    book->numAppointments = 0;
    book->appointments = NULL;

    // Add some appointments to the appointment book
    addAppointment(book, createAppointment("John Doe", "2023-03-08", "10:00 AM", "My Office", "Meeting to discuss project"));
    addAppointment(book, createAppointment("Jane Smith", "2023-03-15", "2:00 PM", "Conference Room A", "Presentation on new marketing campaign"));
    addAppointment(book, createAppointment("Bob Jones", "2023-03-22", "11:00 AM", "My Office", "Interview for new position"));

    // Print the appointment book
    printAppointmentBook(book);

    // Free the memory allocated for the appointment book
    freeAppointmentBook(book);

    return 0;
}