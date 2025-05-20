//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Turing
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

struct Appointment *create_appointment(char *description, int day, int month, int year, int hour, int minute) {
    struct Appointment *appointment = malloc(sizeof(struct Appointment));
    appointment->description = malloc(strlen(description) + 1);
    strcpy(appointment->description, description);
    appointment->day = day;
    appointment->month = month;
    appointment->year = year;
    appointment->hour = hour;
    appointment->minute = minute;
    return appointment;
}

void free_appointment(struct Appointment *appointment) {
    free(appointment->description);
    free(appointment);
}

struct AppointmentList {
    struct Appointment **appointments;
    int size;
    int capacity;
};

struct AppointmentList *create_appointment_list() {
    struct AppointmentList *list = malloc(sizeof(struct AppointmentList));
    list->appointments = malloc(sizeof(struct Appointment *) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void free_appointment_list(struct AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        free_appointment(list->appointments[i]);
    }
    free(list->appointments);
    free(list);
}

void add_appointment(struct AppointmentList *list, struct Appointment *appointment) {
    if (list->size >= list->capacity) {
        list->appointments = realloc(list->appointments, sizeof(struct Appointment *) * list->capacity * 2);
        list->capacity *= 2;
    }
    list->appointments[list->size++] = appointment;
}

void remove_appointment(struct AppointmentList *list, struct Appointment *appointment) {
    for (int i = 0; i < list->size; i++) {
        if (list->appointments[i] == appointment) {
            for (int j = i + 1; j < list->size; j++) {
                list->appointments[j - 1] = list->appointments[j];
            }
            list->size--;
            return;
        }
    }
}

void print_appointment(struct Appointment *appointment) {
    printf("%s (%02d/%02d/%04d %02d:%02d)\n", appointment->description, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
}

void print_appointment_list(struct AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        print_appointment(list->appointments[i]);
    }
}

int main() {
    struct AppointmentList *list = create_appointment_list();
    add_appointment(list, create_appointment("Doctor's appointment", 15, 3, 2023, 10, 0));
    add_appointment(list, create_appointment("Meeting with boss", 20, 3, 2023, 14, 0));
    add_appointment(list, create_appointment("Dinner with friends", 25, 3, 2023, 19, 0));
    print_appointment_list(list);
    free_appointment_list(list);
    return 0;
}