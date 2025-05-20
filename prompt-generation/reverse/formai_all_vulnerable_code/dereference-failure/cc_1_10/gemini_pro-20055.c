//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct appointment {
    char *description;
    time_t start_time;
    time_t end_time;
} appointment;

typedef struct appointment_list {
    appointment *appointments;
    int num_appointments;
} appointment_list;

void add_appointment(appointment_list *list, appointment *appt) {
    list->appointments = realloc(list->appointments, (list->num_appointments + 1) * sizeof(appointment));
    list->appointments[list->num_appointments++] = *appt;
}

void print_appointment(appointment *appt) {
    printf("Description: %s\n", appt->description);
    printf("Start time: %s\n", ctime(&appt->start_time));
    printf("End time: %s\n", ctime(&appt->end_time));
}

void print_appointment_list(appointment_list *list) {
    for (int i = 0; i < list->num_appointments; i++) {
        print_appointment(&list->appointments[i]);
        printf("\n");
    }
}

int main() {
    appointment_list list;
    list.appointments = NULL;
    list.num_appointments = 0;

    // Add some sample appointments
    appointment appt1 = {"Meeting with Mr. Johnson", time(NULL), time(NULL) + 3600};
    add_appointment(&list, &appt1);

    appointment appt2 = {"Hack the Gibson", time(NULL) + 86400, time(NULL) + 86400 + 3600};
    add_appointment(&list, &appt2);

    // Print the appointment list
    print_appointment_list(&list);

    return 0;
}