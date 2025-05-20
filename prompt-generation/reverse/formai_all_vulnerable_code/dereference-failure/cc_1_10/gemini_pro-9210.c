//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
// C Appointment Scheduler (Introspective)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment structure
typedef struct Appointment {
    time_t start;
    time_t end;
    char *description;
} Appointment;

// Appointment list
typedef struct AppointmentList {
    Appointment *appointments;
    int size;
    int capacity;
} AppointmentList;

// Initializes the appointment list
void init_appointment_list(AppointmentList *list) {
    list->size = 0;
    list->capacity = 10;
    list->appointments = malloc(sizeof(Appointment) * list->capacity);
}

// Adds an appointment to the list
void add_appointment(AppointmentList *list, Appointment *appointment) {
    // Check if the list is full
    if (list->size == list->capacity) {
        // Reallocate the list
        list->appointments = realloc(list->appointments, sizeof(Appointment) * list->capacity * 2);
        list->capacity *= 2;
    }

    // Add the appointment to the list
    list->appointments[list->size++] = *appointment;
}

// Prints the appointment list
void print_appointment_list(AppointmentList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s - %s\n", ctime(&list->appointments[i].start), ctime(&list->appointments[i].end));
    }
}

// Main function
int main() {
    // Initialize the appointment list
    AppointmentList list;
    init_appointment_list(&list);

    // Add some appointments to the list
    struct tm tm;
    time_t start, end;
    char *description;

    // First appointment
    tm.tm_year = 2023;
    tm.tm_mon = 2;  // March (0-11)
    tm.tm_mday = 15;
    tm.tm_hour = 10;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    start = mktime(&tm);
    tm.tm_hour = 11;
    end = mktime(&tm);
    description = "Meeting with the team";
    Appointment appointment1 = {start, end, description};
    add_appointment(&list, &appointment1);

    // Second appointment
    tm.tm_year = 2023;
    tm.tm_mon = 2;  // March (0-11)
    tm.tm_mday = 17;
    tm.tm_hour = 14;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    start = mktime(&tm);
    tm.tm_hour = 15;
    end = mktime(&tm);
    description = "Presentation to the CEO";
    Appointment appointment2 = {start, end, description};
    add_appointment(&list, &appointment2);

    // Print the appointment list
    printf("Your appointments:\n");
    print_appointment_list(&list);

    // Free the appointment list
    free(list.appointments);

    return 0;
}