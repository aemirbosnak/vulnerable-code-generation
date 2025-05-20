//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Appointment struct
typedef struct Appointment {
    char *title;
    char *location;
    int startTime;
    int endTime;
    char *description;
} Appointment;

// Define the Appointment Scheduler
void scheduler(Appointment *appointments, int numAppointments) {
    int currentIndex = 0;
    int i = 0;
    int j = 0;

    printf("Appointment Scheduler\n");
    printf("--------------------------------------------\n");

    while (currentIndex < numAppointments) {
        printf("Title: %s\n", appointments[currentIndex].title);
        printf("Location: %s\n", appointments[currentIndex].location);
        printf("Start Time: %d\n", appointments[currentIndex].startTime);
        printf("End Time: %d\n", appointments[currentIndex].endTime);
        printf("Description: %s\n", appointments[currentIndex].description);
        printf("--------------------------------------------\n");
        currentIndex++;
    }
}

int main() {
    int numAppointments = 3;

    // Allocate memory for the appointments
    Appointment *appointments = (Appointment*) malloc(numAppointments * sizeof(Appointment));

    // Set up the appointments
    appointments[0].title = "Meeting with John";
    appointments[0].location = "Conference Room A";
    appointments[0].startTime = 10;
    appointments[0].endTime = 11;
    appointments[0].description = "Discuss project status.";

    appointments[1].title = "Lunch";
    appointments[1].location = "Cafeteria";
    appointments[1].startTime = 12;
    appointments[1].endTime = 13;
    appointments[1].description = "Grab a bite to eat.";

    appointments[2].title = "Meeting with Jane";
    appointments[2].location = "Office";
    appointments[2].startTime = 14;
    appointments[2].endTime = 15;
    appointments[2].description = "Discuss project timeline.";

    // Print the appointments
    scheduler(appointments, numAppointments);

    // Free the memory
    free(appointments);

    return 0;
}