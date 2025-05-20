//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char *location;
    char *notes;
} appointment;

appointment *create_appointment(char *name, int day, int month, int year, int hour, int minute, char *location, char *notes) {
    appointment *new_appointment = malloc(sizeof(appointment));
    new_appointment->name = malloc(strlen(name) + 1);
    strcpy(new_appointment->name, name);
    new_appointment->day = day;
    new_appointment->month = month;
    new_appointment->year = year;
    new_appointment->hour = hour;
    new_appointment->minute = minute;
    new_appointment->location = malloc(strlen(location) + 1);
    strcpy(new_appointment->location, location);
    new_appointment->notes = malloc(strlen(notes) + 1);
    strcpy(new_appointment->notes, notes);
    return new_appointment;
}

void print_appointment(appointment *appt) {
    printf("Appointment: %s\n", appt->name);
    printf("Date: %d/%d/%d\n", appt->day, appt->month, appt->year);
    printf("Time: %d:%d\n", appt->hour, appt->minute);
    printf("Location: %s\n", appt->location);
    printf("Notes: %s\n", appt->notes);
    printf("\n");
}

int main() {
    appointment *appt1 = create_appointment("Doctor's Appointment", 15, 3, 2023, 10, 30, "Doctor's Office", "Bring insurance card");
    appointment *appt2 = create_appointment("Meeting with Boss", 20, 3, 2023, 14, 0, "Conference Room", "Prepare presentation");
    appointment *appt3 = create_appointment("Dinner with Friends", 25, 3, 2023, 19, 0, "Friend's House", "Bring wine");

    print_appointment(appt1);
    print_appointment(appt2);
    print_appointment(appt3);

    return 0;
}