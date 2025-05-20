//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int duration;
} appointment;

appointment *create_appointment(char *name, char *description, int day, int month, int year, int hour, int minute, int duration) {
    appointment *appt = malloc(sizeof(appointment));
    appt->name = strdup(name);
    appt->description = strdup(description);
    appt->day = day;
    appt->month = month;
    appt->year = year;
    appt->hour = hour;
    appt->minute = minute;
    appt->duration = duration;
    return appt;
}

void print_appointment(appointment *appt) {
    printf("%s (%s): %02d/%02d/%04d %02d:%02d for %d minutes\n",
        appt->name, appt->description,
        appt->day, appt->month, appt->year,
        appt->hour, appt->minute, appt->duration);
}

int compare_appointments(const void *a, const void *b) {
    const appointment *appt1 = *(const appointment **)a;
    const appointment *appt2 = *(const appointment **)b;
    int result = appt1->year - appt2->year;
    if (result == 0) {
        result = appt1->month - appt2->month;
        if (result == 0) {
            result = appt1->day - appt2->day;
            if (result == 0) {
                result = appt1->hour - appt2->hour;
                if (result == 0) {
                    result = appt1->minute - appt2->minute;
                }
            }
        }
    }
    return result;
}

int main() {
    // Create an array of appointments
    appointment *appts[] = {
        create_appointment("John Doe", "Doctor's appointment", 15, 3, 2023, 10, 30, 60),
        create_appointment("Jane Smith", "Meeting with boss", 17, 3, 2023, 14, 0, 30),
        create_appointment("Bob Jones", "Dinner with friends", 20, 3, 2023, 18, 30, 120)
    };
    
    // Sort the appointments by date and time
    qsort(appts, sizeof(appts) / sizeof(appointment *), sizeof(appointment *), compare_appointments);

    // Print the sorted appointments
    for (int i = 0; i < sizeof(appts) / sizeof(appointment *); i++) {
        print_appointment(appts[i]);
    }

    // Free the memory allocated for the appointments
    for (int i = 0; i < sizeof(appts) / sizeof(appointment *); i++) {
        free(appts[i]->name);
        free(appts[i]->description);
        free(appts[i]);
    }

    return 0;
}