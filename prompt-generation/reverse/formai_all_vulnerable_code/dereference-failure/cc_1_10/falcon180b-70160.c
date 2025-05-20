//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    char phone[15];
    char email[50];
    time_t appointment_time;
} appointment;

void print_appointment(appointment app) {
    printf("Name: %s\n", app.name);
    printf("Age: %d\n", app.age);
    printf("Phone: %s\n", app.phone);
    printf("Email: %s\n", app.email);
    printf("Appointment Time: %s\n", ctime(&app.appointment_time));
}

int compare_appointments(const void *a, const void *b) {
    appointment *app1 = (appointment *)a;
    appointment *app2 = (appointment *)b;

    time_t diff = difftime(app2->appointment_time, app1->appointment_time);

    if (diff < 0)
        return 1;
    else if (diff > 0)
        return -1;
    else
        return 0;
}

void schedule_appointment(appointment *appointments, int num_appointments) {
    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }
}

int main() {
    int num_appointments;
    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    appointment *appointments = (appointment *)malloc(num_appointments * sizeof(appointment));

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter appointment details for appointment %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Age: ");
        scanf("%d", &appointments[i].age);
        printf("Phone: ");
        scanf("%s", appointments[i].phone);
        printf("Email: ");
        scanf("%s", appointments[i].email);
        printf("Appointment Time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].appointment_time);
        appointments[i].appointment_time = strptime(appointments[i].appointment_time, "%Y-%m-%d %H:%M:%S");
    }

    schedule_appointment(appointments, num_appointments);

    free(appointments);

    return 0;
}