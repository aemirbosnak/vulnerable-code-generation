//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7
#define MINUTES_IN_HOUR 60
#define HOURS_IN_DAY 24
#define DAYS_IN_YEAR 365
#define MONTHS_IN_YEAR 12

typedef struct {
    char name[50];
    int age;
    int phone_number;
    time_t appointment_time;
} appointment;

void print_appointment(appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("Age: %d\n", appt.age);
    printf("Phone Number: %d\n", appt.phone_number);
    printf("Appointment Time: %s", ctime(&appt.appointment_time));
}

int compare_appointments(const void *a, const void *b) {
    appointment *appt1 = (appointment *)a;
    appointment *appt2 = (appointment *)b;

    return difftime(appt2->appointment_time, appt1->appointment_time);
}

int main() {
    int num_appointments;
    scanf("%d", &num_appointments);

    appointment *appointments = malloc(num_appointments * sizeof(appointment));

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter name for appointment %d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Enter age for appointment %d: ", i + 1);
        scanf("%d", &appointments[i].age);

        printf("Enter phone number for appointment %d: ", i + 1);
        scanf("%d", &appointments[i].phone_number);

        printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].appointment_time);
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    free(appointments);
    return 0;
}