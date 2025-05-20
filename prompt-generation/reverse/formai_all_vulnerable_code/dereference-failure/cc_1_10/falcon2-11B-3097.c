//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct Appointment {
    int startTime;
    int duration;
    int appointmentId;
    char name[100];
};

typedef struct Appointment Appointment;

struct Appointments {
    int numAppointments;
    Appointment appointments[100];
};

typedef struct Appointments Appointments;

Appointments* createAppointments() {
    Appointments* appointments = malloc(sizeof(Appointments));
    appointments->numAppointments = 0;
    return appointments;
}

void addAppointment(Appointments* appointments, int startTime, int duration, char* name) {
    Appointment* newAppointment = malloc(sizeof(Appointment));
    newAppointment->startTime = startTime;
    newAppointment->duration = duration;
    newAppointment->appointmentId = appointments->numAppointments;
    strcpy(newAppointment->name, name);
    appointments->appointments[appointments->numAppointments] = *newAppointment;
    appointments->numAppointments++;
}

void displayAppointments(Appointments* appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < appointments->numAppointments; i++) {
        printf("Appointment %d: %s from %d to %d\n", i+1, appointments->appointments[i].name, appointments->appointments[i].startTime, appointments->appointments[i].startTime + appointments->appointments[i].duration);
    }
}

int main() {
    Appointments* appointments = createAppointments();
    addAppointment(appointments, 1000, 30, "Meeting");
    addAppointment(appointments, 1500, 60, "Lunch");
    addAppointment(appointments, 1600, 30, "Call");
    displayAppointments(appointments);
    return 0;
}