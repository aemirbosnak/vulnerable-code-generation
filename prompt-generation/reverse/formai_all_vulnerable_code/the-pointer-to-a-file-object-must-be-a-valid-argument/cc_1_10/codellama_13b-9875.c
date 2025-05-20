//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define APPOINTMENT_FILE "appointments.txt"

struct Appointment {
    char name[50];
    char date[11];
    char time[9];
    char location[50];
};

void printAppointment(struct Appointment appointment) {
    printf("%s - %s at %s in %s\n", appointment.name, appointment.date, appointment.time, appointment.location);
}

void addAppointment(struct Appointment appointment) {
    FILE *fp = fopen(APPOINTMENT_FILE, "a");
    fprintf(fp, "%s - %s at %s in %s\n", appointment.name, appointment.date, appointment.time, appointment.location);
    fclose(fp);
}

void scheduleAppointment() {
    struct Appointment appointment;
    printf("Enter the name of the appointment: ");
    scanf("%s", appointment.name);
    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    scanf("%s", appointment.date);
    printf("Enter the time of the appointment (HH:MM): ");
    scanf("%s", appointment.time);
    printf("Enter the location of the appointment: ");
    scanf("%s", appointment.location);
    addAppointment(appointment);
}

void listAppointments() {
    FILE *fp = fopen(APPOINTMENT_FILE, "r");
    char line[100];
    while (fgets(line, 100, fp)) {
        struct Appointment appointment;
        sscanf(line, "%s - %s at %s in %s", appointment.name, appointment.date, appointment.time, appointment.location);
        printAppointment(appointment);
    }
    fclose(fp);
}

int main() {
    printf("Welcome to the post-apocalyptic appointment scheduler!\n");
    scheduleAppointment();
    listAppointments();
    return 0;
}