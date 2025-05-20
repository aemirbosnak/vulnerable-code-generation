//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct appointment {
    char *name;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int duration;
} appointment;

appointment *appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *name, int day, int month, int year, int hour, int minute, int duration) {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Appointment book is full.\n");
        return;
    }

    appointments[num_appointments] = malloc(sizeof(appointment));
    appointments[num_appointments]->name = strdup(name);
    appointments[num_appointments]->day = day;
    appointments[num_appointments]->month = month;
    appointments[num_appointments]->year = year;
    appointments[num_appointments]->hour = hour;
    appointments[num_appointments]->minute = minute;
    appointments[num_appointments]->duration = duration;

    num_appointments++;
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %d/%d/%d %d:%d for %d minutes\n",
            appointments[i]->name,
            appointments[i]->day,
            appointments[i]->month,
            appointments[i]->year,
            appointments[i]->hour,
            appointments[i]->minute,
            appointments[i]->duration);
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Add some sample appointments
    add_appointment("John Doe", 1, 1, 2023, 10, 0, 30);
    add_appointment("Jane Doe", 2, 1, 2023, 11, 0, 60);
    add_appointment("Bill Smith", 3, 1, 2023, 12, 0, 90);
    add_appointment("Mary Johnson", 4, 1, 2023, 13, 0, 120);

    // Print the appointments
    print_appointments();

    return 0;
}