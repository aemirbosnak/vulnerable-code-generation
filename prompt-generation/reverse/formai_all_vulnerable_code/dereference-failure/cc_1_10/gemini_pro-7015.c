//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char date[11];
    char time[6];
} Appointment;

typedef struct {
    Appointment* appointments;
    int count;
} AppointmentList;

AppointmentList* createAppointmentList() {
    AppointmentList* list = malloc(sizeof(AppointmentList));
    list->appointments = malloc(sizeof(Appointment) * 10);
    list->count = 0;
    return list;
}

void addAppointment(AppointmentList* list, Appointment appointment) {
    if (list->count >= 10) {
        list->appointments = realloc(list->appointments, sizeof(Appointment) * (list->count + 10));
    }
    list->appointments[list->count++] = appointment;
}

void printAppointments(AppointmentList* list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s %s %s\n", list->appointments[i].name, list->appointments[i].date, list->appointments[i].time);
    }
}

int main() {
    AppointmentList* list = createAppointmentList();

    Appointment appointment1 = {"John Doe", "2023-03-08", "10:00"};
    addAppointment(list, appointment1);

    Appointment appointment2 = {"Jane Smith", "2023-04-05", "11:00"};
    addAppointment(list, appointment2);

    Appointment appointment3 = {"Mark Jones", "2023-05-03", "12:00"};
    addAppointment(list, appointment3);

    printAppointments(list);

    return 0;
}