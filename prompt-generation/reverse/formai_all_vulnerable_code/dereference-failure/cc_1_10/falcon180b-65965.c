//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    char phone[15];
    char email[50];
    time_t appointment_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    printf("Enter the name of the patient: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter the age of the patient: ");
    scanf("%d", &appointments[num_appointments].age);

    printf("Enter the phone number of the patient: ");
    scanf("%s", appointments[num_appointments].phone);

    printf("Enter the email address of the patient: ");
    scanf("%s", appointments[num_appointments].email);

    printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);
}

void print_appointments(Appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%d years old)\n", appointments[i].name, appointments[i].age);
        printf("Phone: %s\n", appointments[i].phone);
        printf("Email: %s\n", appointments[i].email);
        printf("Appointment Time: %s\n\n", ctime(&appointments[i].appointment_time));
    }
}

int main() {
    int num_appointments;

    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    Appointment* appointments = (Appointment*) malloc(num_appointments * sizeof(Appointment));

    for (int i = 0; i < num_appointments; i++) {
        add_appointment(appointments, i);
    }

    print_appointments(appointments, num_appointments);

    free(appointments);

    return 0;
}