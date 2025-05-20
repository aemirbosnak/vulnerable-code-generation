//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// struct to represent an appointment
typedef struct {
    char date[11]; // format YYYY-MM-DD
    char time[6]; // format HH:MM (24 hour clock)
    char name[50];
} Appointment;

// function to check if two appointments overlap
bool isOverlapping(Appointment apt1, Appointment apt2) {
    // check if the dates are the same
    if (strcmp(apt1.date, apt2.date) == 0) {
        // convert appointment times to minutes past midnight
        int apt1Start = atoi(strtok(apt1.time, ":")) * 60 + atoi(strtok(NULL, ":"));
        int apt1End = apt1Start + 30; // assume 30 minute appointments
        int apt2Start = atoi(strtok(apt2.time, ":")) * 60 + atoi(strtok(NULL, ":"));
        int apt2End = apt2Start + 30;
        // check for overlap
        if (apt1Start < apt2End && apt2Start < apt1End) {
            return true;
        }
    }
    return false;
}

int main() {
    int numAppointments = 0;
    Appointment appointments[100]; // assume no more than 100 appointments
    printf("Welcome to the Appointment Scheduler!\n\n");

    while (true) {
        printf("Please enter your name: ");
        char name[50];
        fgets(name, 50, stdin);

        // remove newline character from end of name
        name[strcspn(name, "\n")] = '\0';

        printf("Please enter the date of your appointment (YYYY-MM-DD): ");
        char date[11];
        fgets(date, 11, stdin);

        // remove newline character from end of date
        date[strcspn(date, "\n")] = '\0';

        printf("Please enter the time of your appointment (HH:MM, 24 hour clock): ");
        char time[6];
        fgets(time, 6, stdin);

        // remove newline character from end of time
        time[strcspn(time, "\n")] = '\0';

        // create new appointment object
        Appointment newAppointment;
        strcpy(newAppointment.name, name);
        strcpy(newAppointment.date, date);
        strcpy(newAppointment.time, time);

        // check for overlapping appointments
        bool overlap = false;
        for (int i = 0; i < numAppointments; i++) {
            if (isOverlapping(newAppointment, appointments[i])) {
                overlap = true;
                printf("Sorry, that time slot is already taken by %s.\n\n", appointments[i].name);
                break;
            }
        }
        if (!overlap) {
            // add new appointment to array and increment count
            appointments[numAppointments] = newAppointment;
            numAppointments++;
            printf("Appointment scheduled for %s on %s at %s.\n\n", name, date, time);
        }

        // ask if user wants to schedule another appointment
        printf("Would you like to schedule another appointment? (y/n) ");
        char response[2];
        fgets(response, 2, stdin);

        // remove newline character from end of response
        response[strcspn(response, "\n")] = '\0';

        if (strcmp(response, "n") == 0) {
            // print list of all appointments
            printf("Scheduled Appointments:\n");
            for (int i = 0; i < numAppointments; i++) {
                printf("%s - %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
            }
            printf("Thank you for using the Appointment Scheduler!\n");
            break;
        }
    }

    return 0;
}