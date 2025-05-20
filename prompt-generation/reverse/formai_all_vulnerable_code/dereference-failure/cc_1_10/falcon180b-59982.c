//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int age;
    time_t appointment_time;
} appointment;

void add_appointment(appointment* appointments, int num_appointments, char* name, int age, time_t appointment_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the schedule is full.\n");
        return;
    }
    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].age = age;
    appointments[num_appointments].appointment_time = appointment_time;
    num_appointments++;
}

void display_appointments(appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%d years old) - %s\n", appointments[i].name, appointments[i].age, ctime(&appointments[i].appointment_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char input[100];

    while (1) {
        printf("Enter name: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        printf("Enter age: ");
        scanf("%d", &num_appointments);
        time_t appointment_time = time(NULL) + 60*60*24*7; // one week from now
        add_appointment(appointments, num_appointments, input, num_appointments, appointment_time);
    }

    display_appointments(appointments, num_appointments);

    return 0;
}