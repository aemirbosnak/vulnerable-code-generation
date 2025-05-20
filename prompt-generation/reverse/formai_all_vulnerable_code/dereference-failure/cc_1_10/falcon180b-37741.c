//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct appointment {
    time_t date;
    char name[MAX_NAME_LENGTH];
    char reason[MAX_NAME_LENGTH];
} Appointment;

Appointment* create_appointment(time_t date, char* name, char* reason) {
    Appointment* appt = (Appointment*) malloc(sizeof(Appointment));
    appt->date = date;
    strncpy(appt->name, name, MAX_NAME_LENGTH);
    strncpy(appt->reason, reason, MAX_NAME_LENGTH);
    return appt;
}

void print_appointment(Appointment* appt) {
    printf("Name: %s\n", appt->name);
    printf("Reason: %s\n", appt->reason);
    printf("Date: %s\n", ctime(&appt->date));
}

int compare_appointments(const void* a, const void* b) {
    const Appointment* appt_a = (const Appointment*) a;
    const Appointment* appt_b = (const Appointment*) b;
    return difftime(appt_a->date, appt_b->date);
}

int main() {
    int num_appointments;
    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    Appointment* appointments[MAX_APPOINTMENTS];
    for (int i = 0; i < num_appointments; i++) {
        time_t date;
        printf("Enter the appointment date (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime_r(&date, ""));
        char name[MAX_NAME_LENGTH];
        printf("Enter the name: ");
        scanf("%s", name);
        char reason[MAX_NAME_LENGTH];
        printf("Enter the reason: ");
        scanf("%s", reason);
        Appointment* appt = create_appointment(date, name, reason);
        appointments[i] = appt;
    }

    qsort(appointments, num_appointments, sizeof(Appointment*), compare_appointments);

    printf("Upcoming appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}