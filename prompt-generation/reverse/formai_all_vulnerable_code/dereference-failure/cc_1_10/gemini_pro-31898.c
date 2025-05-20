//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment_t;

appointment_t *create_appointment(char *name, char *description, int day, int month, int year, int hour, int minute)
{
    appointment_t *appt = malloc(sizeof(appointment_t));

    appt->name = strdup(name);
    appt->description = strdup(description);
    appt->day = day;
    appt->month = month;
    appt->year = year;
    appt->hour = hour;
    appt->minute = minute;

    return appt;
}

void free_appointment(appointment_t *appt)
{
    free(appt->name);
    free(appt->description);
    free(appt);
}

typedef struct appointment_list {
    appointment_t **appointments;
    int num_appointments;
} appointment_list_t;

appointment_list_t *create_appointment_list()
{
    appointment_list_t *list = malloc(sizeof(appointment_list_t));

    list->appointments = NULL;
    list->num_appointments = 0;

    return list;
}

void free_appointment_list(appointment_list_t *list)
{
    for (int i = 0; i < list->num_appointments; i++) {
        free_appointment(list->appointments[i]);
    }
    free(list->appointments);
    free(list);
}

void add_appointment(appointment_list_t *list, appointment_t *appt)
{
    list->appointments = realloc(list->appointments, sizeof(appointment_t *) * (list->num_appointments + 1));
    list->appointments[list->num_appointments] = appt;
    list->num_appointments++;
}

appointment_t *find_appointment(appointment_list_t *list, char *name)
{
    for (int i = 0; i < list->num_appointments; i++) {
        if (strcmp(list->appointments[i]->name, name) == 0) {
            return list->appointments[i];
        }
    }
    return NULL;
}

void print_appointment(appointment_t *appt)
{
    printf("%s (%s) - %02d/%02d/%04d %02d:%02d\n", appt->name, appt->description, appt->day, appt->month, appt->year, appt->hour, appt->minute);
}

void print_appointment_list(appointment_list_t *list)
{
    for (int i = 0; i < list->num_appointments; i++) {
        print_appointment(list->appointments[i]);
    }
}

int main()
{
    appointment_list_t *list = create_appointment_list();

    add_appointment(list, create_appointment("John Doe", "Doctor's appointment", 15, 3, 2023, 10, 30));
    add_appointment(list, create_appointment("Jane Smith", "Dentist appointment", 20, 3, 2023, 14, 0));
    add_appointment(list, create_appointment("Bill Jones", "Haircut", 25, 3, 2023, 16, 30));

    print_appointment_list(list);

    appointment_t *appt = find_appointment(list, "Jane Smith");
    if (appt != NULL) {
        print_appointment(appt);
    } else {
        printf("Appointment not found.\n");
    }

    free_appointment_list(list);

    return 0;
}