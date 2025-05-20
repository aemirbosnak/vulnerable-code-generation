//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char* name;
    char* description;
    char* date;
    char* time;
    int duration;
    int priority;
};

struct appointment *new_appointment(char* name, char* description, char* date, char* time, int duration, int priority) {
    struct appointment *appointment = malloc(sizeof(struct appointment));
    appointment->name = strdup(name);
    appointment->description = strdup(description);
    appointment->date = strdup(date);
    appointment->time = strdup(time);
    appointment->duration = duration;
    appointment->priority = priority;
    return appointment;
}

void print_appointment(struct appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Description: %s\n", appointment->description);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
    printf("Duration: %d minutes\n", appointment->duration);
    printf("Priority: %d\n", appointment->priority);
    printf("\n");
}

int main() {
    struct appointment *appointment1 = new_appointment("John Doe", "Meeting with Client", "2022-03-15", "10:00", 30, 1);
    struct appointment *appointment2 = new_appointment("Jane Smith", "Presentation", "2022-03-16", "14:00", 60, 2);

    print_appointment(appointment1);
    print_appointment(appointment2);

    free(appointment1->name);
    free(appointment1->description);
    free(appointment1->date);
    free(appointment1->time);
    free(appointment1);

    free(appointment2->name);
    free(appointment2->description);
    free(appointment2->date);
    free(appointment2->time);
    free(appointment2);

    return 0;
}