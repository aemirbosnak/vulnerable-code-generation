//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char *name;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char *notes;
} Appointment;

Appointment *appointments[100];
int numAppointments = 0;

void addAppointment(char *name, int day, int month, int year, int hour, int minute, char *notes) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->day = day;
    appointment->month = month;
    appointment->year = year;
    appointment->hour = hour;
    appointment->minute = minute;
    appointment->notes = strdup(notes);
    appointments[numAppointments++] = appointment;
}

void printAppointments() {
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\n", appointments[i]->name);
        printf("%d/%d/%d\n", appointments[i]->day, appointments[i]->month, appointments[i]->year);
        printf("%d:%d\n", appointments[i]->hour, appointments[i]->minute);
        printf("%s\n\n", appointments[i]->notes);
    }
}

void deleteAppointment(char *name) {
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i]->name, name) == 0) {
            free(appointments[i]->name);
            free(appointments[i]->notes);
            free(appointments[i]);
            appointments[i] = appointments[numAppointments - 1];
            numAppointments--;
            return;
        }
    }
}

int main() {
    addAppointment("John Doe", 1, 1, 2023, 10, 0, "Meeting with the boss");
    addAppointment("Mary Smith", 1, 2, 2023, 11, 0, "Lunch with a friend");
    addAppointment("John Doe", 1, 3, 2023, 12, 0, "Dentist appointment");
    addAppointment("Mary Smith", 1, 4, 2023, 13, 0, "Shopping for groceries");
    addAppointment("John Doe", 1, 5, 2023, 14, 0, "Movie night");
    addAppointment("Mary Smith", 1, 6, 2023, 15, 0, "Dinner with family");
    addAppointment("John Doe", 1, 7, 2023, 16, 0, "Gym workout");
    addAppointment("Mary Smith", 1, 8, 2023, 17, 0, "Yoga class");
    addAppointment("John Doe", 1, 9, 2023, 18, 0, "Coding session");
    addAppointment("Mary Smith", 1, 10, 2023, 19, 0, "Reading time");

    printAppointments();

    deleteAppointment("John Doe");

    printAppointments();

    return 0;
}