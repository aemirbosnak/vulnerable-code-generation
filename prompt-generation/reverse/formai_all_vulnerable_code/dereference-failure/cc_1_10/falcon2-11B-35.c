//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[100];
    int duration;
    char start_time[20];
    char end_time[20];
} Appointment;

typedef struct {
    Appointment *appointments;
    int size;
    int capacity;
} AppointmentList;

AppointmentList createList(int capacity) {
    AppointmentList list;
    list.capacity = capacity;
    list.size = 0;
    list.appointments = malloc(sizeof(Appointment) * capacity);
    return list;
}

void addAppointment(AppointmentList *list, Appointment *appointment) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->appointments = realloc(list->appointments, sizeof(Appointment) * list->capacity);
    }
    list->appointments[list->size++] = *appointment;
}

void displayAppointments(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("Name: %s, Duration: %d, Start Time: %s, End Time: %s\n", list->appointments[i].name, list->appointments[i].duration, list->appointments[i].start_time, list->appointments[i].end_time);
    }
}

int main() {
    srand(time(0));
    AppointmentList list = createList(5);
    Appointment appointment;
    int count = 0;
    do {
        appointment.name[0] = 'A';
        appointment.name[1] = 'p';
        appointment.name[2] = 'p';
        appointment.name[3] = 'o';
        appointment.name[4] = '\0';
        sprintf(appointment.start_time, "%.2d:%.2d", rand() % 12, rand() % 60);
        sprintf(appointment.end_time, "%.2d:%.2d", rand() % 12, rand() % 60);
        appointment.duration = rand() % 10 + 30;
        addAppointment(&list, &appointment);
        count++;
    } while (count <= 10);
    displayAppointments(&list);
    return 0;
}