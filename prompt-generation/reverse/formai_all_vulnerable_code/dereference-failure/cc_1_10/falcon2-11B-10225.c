//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char* title;
    char* description;
    int date;
    int time;
    char* clientName;
    char* assistantName;
};

struct appointment* createAppointment(char* title, char* description, int date, int time, char* clientName, char* assistantName) {
    struct appointment* appointment = malloc(sizeof(struct appointment));
    appointment->title = title;
    appointment->description = description;
    appointment->date = date;
    appointment->time = time;
    appointment->clientName = clientName;
    appointment->assistantName = assistantName;
    return appointment;
}

void deleteAppointment(struct appointment* appointment) {
    free(appointment->title);
    free(appointment->description);
    free(appointment->clientName);
    free(appointment->assistantName);
    free(appointment);
}

void displayAppointment(struct appointment* appointment) {
    printf("Title: %s\n", appointment->title);
    printf("Description: %s\n", appointment->description);
    printf("Date: %d\n", appointment->date);
    printf("Time: %d\n", appointment->time);
    printf("Client Name: %s\n", appointment->clientName);
    printf("Assistant Name: %s\n", appointment->assistantName);
    printf("\n");
}

int main() {
    struct appointment* appointment1 = createAppointment("Meeting", "Discuss project updates", 2022, 10, "John Doe", "Jane Smith");
    displayAppointment(appointment1);

    struct appointment* appointment2 = createAppointment("Presentation", "Company performance review", 2022, 11, "Jane Smith", "John Doe");
    displayAppointment(appointment2);

    deleteAppointment(appointment1);
    deleteAppointment(appointment2);

    return 0;
}