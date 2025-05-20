//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointmentTime;
    int appointmentDuration;
    int appointmentID;
} appointment;

int getNextAppointmentID() {
    static int lastID = 1;
    return lastID++;
}

void addAppointment(appointment* appointments, int numAppointments, int appointmentTime, int appointmentDuration, char* name) {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    appointment newAppointment;
    strcpy(newAppointment.name, name);
    newAppointment.appointmentTime = appointmentTime;
    newAppointment.appointmentDuration = appointmentDuration;
    newAppointment.appointmentID = getNextAppointmentID();

    int i;
    for (i = 0; i < numAppointments; i++) {
        if (appointments[i].appointmentTime > newAppointment.appointmentTime) {
            memmove(&appointments[i+1], &appointments[i], sizeof(appointment) * (numAppointments - i - 1));
            appointments[i] = newAppointment;
            return;
        }
    }

    appointments[numAppointments-1] = newAppointment;
    numAppointments++;
}

void printAppointments(appointment* appointments, int numAppointments) {
    printf("Appointments:\n");
    printf("ID\tName\tAppointment Time\tDuration\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d\t%s\t%d\t%d\n", appointments[i].appointmentID, appointments[i].name, appointments[i].appointmentTime, appointments[i].appointmentDuration);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    addAppointment(appointments, numAppointments, 1000, 60, "John");
    addAppointment(appointments, numAppointments, 1200, 90, "Jane");
    addAppointment(appointments, numAppointments, 1400, 120, "Bob");

    printAppointments(appointments, numAppointments);

    return 0;
}