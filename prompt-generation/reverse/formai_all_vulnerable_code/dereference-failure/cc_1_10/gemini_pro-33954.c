//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char *title;
    char *location;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment *createAppointment(char *title, char *location, char *description, int day, int month, int year, int hour, int minute) {
    Appointment *appointment = (Appointment *)malloc(sizeof(Appointment));
    appointment->title = (char *)malloc(strlen(title) + 1);
    strcpy(appointment->title, title);
    appointment->location = (char *)malloc(strlen(location) + 1);
    strcpy(appointment->location, location);
    appointment->description = (char *)malloc(strlen(description) + 1);
    strcpy(appointment->description, description);
    appointment->day = day;
    appointment->month = month;
    appointment->year = year;
    appointment->hour = hour;
    appointment->minute = minute;
    return appointment;
}

void printAppointment(Appointment *appointment) {
    printf("%s\n", appointment->title);
    printf("%s\n", appointment->location);
    printf("%s\n", appointment->description);
    printf("%d-%d-%d\n", appointment->day, appointment->month, appointment->year);
    printf("%d:%d\n", appointment->hour, appointment->minute);
}

int main() {
    Appointment *appointment1 = createAppointment("Doctor's Appointment", "My Doctor's Office", "Annual checkup", 15, 3, 2023, 10, 30);
    Appointment *appointment2 = createAppointment("Lunch with Jane", "Jane's Cafe", "Catching up", 17, 3, 2023, 12, 0);
    Appointment *appointment3 = createAppointment("Movie with John", "AMC Theater", "Watching the latest blockbuster", 19, 3, 2023, 7, 0);

    Appointment *appointments[] = {appointment1, appointment2, appointment3};
    int numAppointments = sizeof(appointments) / sizeof(Appointment *);

    for (int i = 0; i < numAppointments; i++) {
        printAppointment(appointments[i]);
        printf("\n");
    }

    return 0;
}