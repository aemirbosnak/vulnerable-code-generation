//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Struct for appointment information
 */
struct appointment {
    char *name;
    int day;
    int month;
    int year;
    char *time;
};

/*
 * Function to initialize appointment
 */
void initializeAppointment(struct appointment *a, char *n, int d, int m, int y, char *t) {
    a->name = n;
    a->day = d;
    a->month = m;
    a->year = y;
    a->time = t;
}

/*
 * Function to display appointment information
 */
void displayAppointment(struct appointment a) {
    printf("Name: %s\n", a.name);
    printf("Date: %d/%d/%d\n", a.day, a.month, a.year);
    printf("Time: %s\n", a.time);
}

/*
 * Main function
 */
int main() {
    // Initialize array for appointments
    struct appointment appointments[10];

    // Set random seed
    srand(time(NULL));

    // Generate 10 random appointments
    for (int i = 0; i < 10; i++) {
        // Randomize name
        int name_length = (rand() % 10) + 1;
        char *name = calloc(name_length, sizeof(char));
        for (int j = 0; j < name_length; j++) {
            name[j] = (rand() % 26) + 97;
        }

        // Randomize date
        int day = (rand() % 30) + 1;
        int month = (rand() % 12) + 1;
        int year = 2022;

        // Randomize time
        int hour = (rand() % 12) + 1;
        int minute = (rand() % 60);
        char *time = calloc(6, sizeof(char));
        if (hour < 10) {
            sprintf(time, "0%d:%02d", hour, minute);
        } else {
            sprintf(time, "%d:%02d", hour, minute);
        }

        // Initialize appointment and store in array
        struct appointment a;
        initializeAppointment(&a, name, day, month, year, time);
        appointments[i] = a;
    }

    // Display appointments
    for (int i = 0; i < 10; i++) {
        printf("Appointment %d:\n", i+1);
        displayAppointment(appointments[i]);
        printf("\n");
    }

    return 0;
}