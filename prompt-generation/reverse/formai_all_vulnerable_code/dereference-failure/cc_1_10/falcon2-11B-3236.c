//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Appointment {
    struct Appointment *next;
    char *date;
    char *time;
    char *description;
};

typedef struct Appointment Appointment;

struct Appointment *appointments = NULL;

void scheduleAppointment(char *date, char *time, char *description) {
    struct Appointment *newAppointment = (struct Appointment *) malloc(sizeof(struct Appointment));
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    strcpy(newAppointment->description, description);
    newAppointment->next = NULL;

    if (appointments == NULL) {
        appointments = newAppointment;
    } else {
        struct Appointment *current = appointments;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newAppointment;
    }
}

void printAppointments() {
    struct Appointment *current = appointments;
    while (current!= NULL) {
        printf("%s (%s): %s\n", current->date, current->time, current->description);
        current = current->next;
    }
}

int main() {
    struct Appointment *newAppointment = (struct Appointment *) malloc(sizeof(struct Appointment));
    struct Appointment *current = appointments;

    while (1) {
        printf("Enter appointment date (yyyy-mm-dd): ");
        scanf("%s", newAppointment->date);
        printf("Enter appointment time (hh:mm): ");
        scanf("%s", newAppointment->time);
        printf("Enter appointment description: ");
        scanf("%s", newAppointment->description);

        if (strcmp(newAppointment->date, "") == 0 || strcmp(newAppointment->time, "") == 0 || strcmp(newAppointment->description, "") == 0) {
            printf("Invalid input\n");
            continue;
        }

        if (strcmp(newAppointment->date, "2019-01-01") == 0 && strcmp(newAppointment->time, "12:00") == 0 && strcmp(newAppointment->description, "Example appointment") == 0) {
            printf("Example appointment\n");
            break;
        }

        scheduleAppointment(newAppointment->date, newAppointment->time, newAppointment->description);
        free(newAppointment);
        newAppointment = NULL;

        printAppointments();
    }

    return 0;
}