//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *phone;
    char *email;
    char *date;
    char *time;
    char *notes;
} Appointment;

Appointment *create_appointment(char *name, char *phone, char *email, char *date, char *time, char *notes) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->phone = strdup(phone);
    appointment->email = strdup(email);
    appointment->date = strdup(date);
    appointment->time = strdup(time);
    appointment->notes = strdup(notes);
    return appointment;
}

void destroy_appointment(Appointment *appointment) {
    free(appointment->name);
    free(appointment->phone);
    free(appointment->email);
    free(appointment->date);
    free(appointment->time);
    free(appointment->notes);
    free(appointment);
}

void print_appointment(Appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Phone: %s\n", appointment->phone);
    printf("Email: %s\n", appointment->email);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
    printf("Notes: %s\n", appointment->notes);
}

int main() {
    Appointment *appointment = create_appointment("John Doe", "555-123-4567", "john.doe@example.com", "2023-03-08", "10:00 AM", "This is a test appointment.");

    print_appointment(appointment);

    destroy_appointment(appointment);

    return 0;
}