//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    int duration;
} appointment;

void print_appointment(appointment* appt) {
    printf("Name: %s\n", appt->name);
    printf("Phone: %s\n", appt->phone);
    printf("Email: %s\n", appt->email);
    printf("Appointment time: %s\n", ctime(&appt->appointment_time));
    printf("Duration: %d minutes\n\n", appt->duration);
}

int compare_appointments(const void* a, const void* b) {
    const appointment* appt_a = (const appointment*)a;
    const appointment* appt_b = (const appointment*)b;

    time_t diff = difftime(appt_a->appointment_time, appt_b->appointment_time);

    if (diff < 0) {
        return -1;
    } else if (diff > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_appointments;
    printf("How many appointments do you have? ");
    scanf("%d", &num_appointments);

    appointment* appointments = malloc(num_appointments * sizeof(appointment));

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter appointment information for appointment #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Phone: ");
        scanf("%s", appointments[i].phone);
        printf("Email: ");
        scanf("%s", appointments[i].email);
        printf("Appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].appointment_time);
        appointments[i].duration = 0;
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    free(appointments);

    return 0;
}