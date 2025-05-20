//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct AppointmentList {
    struct Appointment *appointments;
    int numAppointments;
};

struct AppointmentList *createAppointmentList() {
    struct AppointmentList *list = malloc(sizeof(struct AppointmentList));
    list->appointments = NULL;
    list->numAppointments = 0;
    return list;
}

void addAppointment(struct AppointmentList *list, struct Appointment *appointment) {
    list->appointments = realloc(list->appointments, (list->numAppointments + 1) * sizeof(struct Appointment));
    list->appointments[list->numAppointments++] = *appointment;
}

void printAppointmentList(struct AppointmentList *list) {
    for (int i = 0; i < list->numAppointments; i++) {
        printf("%s %d/%d/%d %d:%d\n", list->appointments[i].description, list->appointments[i].day, list->appointments[i].month, list->appointments[i].year, list->appointments[i].hour, list->appointments[i].minute);
    }
}

int main() {
    struct AppointmentList *list = createAppointmentList();

    struct Appointment appointment1 = {"Meeting with the Lord", 10, 10, 1492, 10, 0};
    addAppointment(list, &appointment1);

    struct Appointment appointment2 = {"Jousting tournament", 15, 10, 1492, 14, 0};
    addAppointment(list, &appointment2);

    struct Appointment appointment3 = {"Feast with the King", 20, 10, 1492, 18, 0};
    addAppointment(list, &appointment3);

    printAppointmentList(list);

    return 0;
}