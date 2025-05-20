//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    char *title;
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

Appointment *appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *title, char *description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Too many appointments.\n");
        return;
    }

    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->title = strdup(title);
    appointment->description = strdup(description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;

    appointments[num_appointments++] = appointment;
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        Appointment *appointment = appointments[i];
        printf("%s: %s (%s - %s)\n", appointment->title, appointment->description, ctime(&appointment->start_time), ctime(&appointment->end_time));
    }
}

int main() {
    // Add some sample appointments
    add_appointment("Meeting with John", "Discuss project plans", time(NULL) + 3600, time(NULL) + 4200);
    add_appointment("Doctor's appointment", "Annual checkup", time(NULL) + 86400, time(NULL) + 90000);
    add_appointment("Lunch with Mary", "Catch up", time(NULL) + 172800, time(NULL) + 180000);

    // Print the appointments
    print_appointments();

    return 0;
}