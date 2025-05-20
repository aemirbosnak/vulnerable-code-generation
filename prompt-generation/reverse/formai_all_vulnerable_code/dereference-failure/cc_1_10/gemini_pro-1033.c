//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char *start_time;
    char *end_time;
    char *description;
} Appointment;

typedef struct AppointmentList {
    int count;
    Appointment *appointments;
} AppointmentList;

void create_appointment(AppointmentList *list, char *start_time, char *end_time, char *description) {
    Appointment *new_appointment = malloc(sizeof(Appointment));
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    new_appointment->description = description;
    list->appointments = realloc(list->appointments, (list->count + 1) * sizeof(Appointment));
    list->appointments[list->count++] = *new_appointment;
}

void print_appointments(AppointmentList *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s - %s: %s\n", list->appointments[i].start_time, list->appointments[i].end_time, list->appointments[i].description);
    }
}

void free_appointments(AppointmentList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->appointments[i].start_time);
        free(list->appointments[i].end_time);
        free(list->appointments[i].description);
    }
    free(list->appointments);
}

int main() {
    AppointmentList list;
    list.count = 0;
    list.appointments = NULL;

    create_appointment(&list, "10:00 AM", "11:00 AM", "Meeting with John");
    create_appointment(&list, "11:00 AM", "12:00 PM", "Lunch with Mary");
    create_appointment(&list, "1:00 PM", "2:00 PM", "Call with Bob");

    print_appointments(&list);

    free_appointments(&list);

    return 0;
}