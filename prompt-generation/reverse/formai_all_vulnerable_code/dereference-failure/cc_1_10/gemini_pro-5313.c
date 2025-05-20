//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct appointment {
    char *name;
    char *description;
    int start_time;
    int end_time;
} appointment_t;

appointment_t *appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *name, char *description, int start_time, int end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    appointments[num_appointments] = malloc(sizeof(appointment_t));
    appointments[num_appointments]->name = strdup(name);
    appointments[num_appointments]->description = strdup(description);
    appointments[num_appointments]->start_time = start_time;
    appointments[num_appointments]->end_time = end_time;
    num_appointments++;
}

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("  - %s: %s (%d - %d)\n", appointments[i]->name, appointments[i]->description, appointments[i]->start_time, appointments[i]->end_time);
    }
}

void free_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        free(appointments[i]->name);
        free(appointments[i]->description);
        free(appointments[i]);
    }
}

int main() {
    add_appointment("John Smith", "Meeting", 9, 10);
    add_appointment("Jane Doe", "Interview", 10, 11);
    add_appointment("Mark Jones", "Call", 11, 12);

    print_appointments();

    free_appointments();

    return 0;
}