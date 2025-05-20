//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the appointment structure
typedef struct appointment {
    char *name;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

// Create a new appointment
appointment *create_appointment(char *name, char *description, int day, int month, int year, int hour, int minute) {
    appointment *appt = malloc(sizeof(appointment));
    appt->name = strdup(name);
    appt->description = strdup(description);
    appt->day = day;
    appt->month = month;
    appt->year = year;
    appt->hour = hour;
    appt->minute = minute;
    return appt;
}

// Print an appointment
void print_appointment(appointment *appt) {
    printf("%s: %s\n", appt->name, appt->description);
    printf("Date: %d/%d/%d\n", appt->day, appt->month, appt->year);
    printf("Time: %d:%d\n", appt->hour, appt->minute);
}

// Compare two appointments
int compare_appointments(appointment *appt1, appointment *appt2) {
    if (appt1->year != appt2->year) {
        return appt1->year - appt2->year;
    }
    if (appt1->month != appt2->month) {
        return appt1->month - appt2->month;
    }
    if (appt1->day != appt2->day) {
        return appt1->day - appt2->day;
    }
    if (appt1->hour != appt2->hour) {
        return appt1->hour - appt2->hour;
    }
    return appt1->minute - appt2->minute;
}

// Sort an array of appointments
void sort_appointments(appointment **appts, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compare_appointments(appts[i], appts[j]) > 0) {
                appointment *temp = appts[i];
                appts[i] = appts[j];
                appts[j] = temp;
            }
        }
    }
}

// Print a list of appointments
void print_appointments(appointment **appts, int n) {
    for (int i = 0; i < n; i++) {
        print_appointment(appts[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create an array of appointments
    appointment *appts[] = {
        create_appointment("John Doe", "Doctor's appointment", 1, 1, 2023, 10, 0),
        create_appointment("Jane Doe", "Dentist appointment", 5, 1, 2023, 11, 0),
        create_appointment("Bob Smith", "Haircut", 10, 1, 2023, 12, 0),
        create_appointment("Alice Jones", "Massage", 15, 1, 2023, 13, 0),
        create_appointment("Tom Davis", "Yoga class", 20, 1, 2023, 14, 0),
    };

    // Sort the appointments
    sort_appointments(appts, 5);

    // Print the appointments
    print_appointments(appts, 5);

    // Free the appointments
    for (int i = 0; i < 5; i++) {
        free(appts[i]->name);
        free(appts[i]->description);
        free(appts[i]);
    }

    return 0;
}