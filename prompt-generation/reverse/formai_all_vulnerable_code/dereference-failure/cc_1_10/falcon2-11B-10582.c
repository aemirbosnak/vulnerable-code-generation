//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct appointment {
    int id;
    char *description;
    int start_time;
    int end_time;
    int priority;
    int status;
} Appointment;

typedef struct {
    Appointment *appointments;
    int count;
    int capacity;
} AppointmentList;

AppointmentList *create_appointment_list(int capacity) {
    AppointmentList *list = (AppointmentList *)malloc(sizeof(AppointmentList));
    if (list == NULL) {
        printf("Out of memory\n");
        exit(EXIT_FAILURE);
    }
    list->appointments = (Appointment *)malloc(capacity * sizeof(Appointment));
    if (list->appointments == NULL) {
        free(list);
        printf("Out of memory\n");
        exit(EXIT_FAILURE);
    }
    list->count = 0;
    list->capacity = capacity;
    return list;
}

void add_appointment(AppointmentList *list, int id, char *description, int start_time, int end_time, int priority) {
    if (list->count >= list->capacity) {
        printf("List is full\n");
        return;
    }
    Appointment *appointment = &(list->appointments[list->count]);
    appointment->id = id;
    appointment->description = (char *)malloc(strlen(description) + 1);
    if (appointment->description == NULL) {
        printf("Out of memory\n");
        exit(EXIT_FAILURE);
    }
    strcpy(appointment->description, description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;
    appointment->priority = priority;
    appointment->status = 0;
    list->count++;
}

void print_appointment(AppointmentList *list) {
    if (list->count == 0) {
        printf("List is empty\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s (%d-%d) Priority: %d Status: %d\n",
               list->appointments[i].id,
               list->appointments[i].description,
               list->appointments[i].start_time,
               list->appointments[i].end_time,
               list->appointments[i].priority,
               list->appointments[i].status);
    }
}

int main() {
    AppointmentList *list = create_appointment_list(10);
    if (list == NULL) {
        return 1;
    }
    add_appointment(list, 1, "Meeting with Bob", 9, 10, 5);
    add_appointment(list, 2, "Lunch", 12, 13, 2);
    add_appointment(list, 3, "Walk", 14, 15, 4);
    print_appointment(list);
    return 0;
}