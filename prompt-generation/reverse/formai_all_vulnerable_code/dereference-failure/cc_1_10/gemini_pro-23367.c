//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    int day;
    int month;
    int year;
    char *notes;
} Appointment;

Appointment *create_appointment(char *name, char *email, char *phone, int day, int month, int year, char *notes) {
    Appointment *appt = malloc(sizeof(Appointment));
    appt->name = strdup(name);
    appt->email = strdup(email);
    appt->phone = strdup(phone);
    appt->day = day;
    appt->month = month;
    appt->year = year;
    appt->notes = strdup(notes);
    return appt;
}

void print_appointment(Appointment *appt) {
    printf("Name: %s\n", appt->name);
    printf("Email: %s\n", appt->email);
    printf("Phone: %s\n", appt->phone);
    printf("Date: %d/%d/%d\n", appt->day, appt->month, appt->year);
    printf("Notes: %s\n", appt->notes);
}

int main() {
    // Create a few appointments
    Appointment *appt1 = create_appointment("John Doe", "john.doe@example.com", "555-123-4567", 1, 1, 2023, "Initial consultation");
    Appointment *appt2 = create_appointment("Jane Smith", "jane.smith@example.com", "555-234-5678", 15, 1, 2023, "Follow-up appointment");

    // Print the appointments
    printf("Appointment 1:\n");
    print_appointment(appt1);
    printf("\n");
    printf("Appointment 2:\n");
    print_appointment(appt2);

    // Free the appointments
    free(appt1->name);
    free(appt1->email);
    free(appt1->phone);
    free(appt1);
    free(appt2->name);
    free(appt2->email);
    free(appt2->phone);
    free(appt2);

    return 0;
}