//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCHEDULE 100

typedef struct {
    char *name;
    int start_time;
    int end_time;
} appointment;

appointment schedule[MAX_SCHEDULE];
int num_appointments = 0;

void add_appointment(char *name, int start_time, int end_time) {
    if (num_appointments >= MAX_SCHEDULE) {
        printf("Sorry, schedule is full.\n");
        return;
    }
    appointment *new_appointment = &schedule[num_appointments];
    strcpy(new_appointment->name, name);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    num_appointments++;
}

void delete_appointment(int index) {
    if (index >= num_appointments) {
        printf("Invalid appointment index.\n");
        return;
    }
    num_appointments--;
    for (int i = index; i < num_appointments; i++) {
        appointment *appt = &schedule[i];
        strcpy(appt->name, &schedule[i+1].name);
        appt->start_time = &schedule[i+1].start_time;
        appt->end_time = &schedule[i+1].end_time;
    }
}

void display_schedule() {
    if (num_appointments == 0) {
        printf("Schedule is empty.\n");
        return;
    }
    for (int i = 0; i < num_appointments; i++) {
        appointment *appt = &schedule[i];
        printf("%s - %d to %d\n", appt->name, appt->start_time, appt->end_time);
    }
}

int main() {
    add_appointment("Meeting with boss", 900, 1000);
    add_appointment("Lunch with colleague", 1200, 1300);
    display_schedule();
    delete_appointment(0);
    display_schedule();
    return 0;
}