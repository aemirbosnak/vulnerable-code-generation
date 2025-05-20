//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print appointment details
void printAppointment(int appointmentID, int startTime, int endTime, int duration) {
    printf("Appointment ID: %d\n", appointmentID);
    printf("Start Time: %d\n", startTime);
    printf("End Time: %d\n", endTime);
    printf("Duration: %d\n", duration);
}

// Function to schedule an appointment
void scheduleAppointment(int appointmentID, int startTime, int endTime, int duration, char* name) {
    printf("Scheduling appointment %d with start time %d, end time %d, and duration %d for %s\n", appointmentID, startTime, endTime, duration, name);
}

// Function to check appointment availability
int isAvailable(int startTime, int endTime, int duration) {
    time_t currentTime = time(0);
    struct tm* currentDateTime = localtime(&currentTime);
    int startHour = currentDateTime->tm_hour;
    int startMinute = currentDateTime->tm_min;
    int endHour = startHour + duration;
    int endMinute = endHour * 60 + startMinute + duration * 60;
    if (startTime < endTime) {
        if (startMinute < endMinute) {
            return 1; // Appointment is available
        } else {
            return 0; // Appointment is not available
        }
    } else {
        if (startHour < endHour) {
            return 1; // Appointment is available
        } else {
            return 0; // Appointment is not available
        }
    }
}

// Function to get user input for scheduling an appointment
void getUserInput() {
    printf("Enter appointment ID: ");
    int appointmentID;
    scanf("%d", &appointmentID);

    printf("Enter start time: ");
    int startTime;
    scanf("%d", &startTime);

    printf("Enter end time: ");
    int endTime;
    scanf("%d", &endTime);

    printf("Enter duration: ");
    int duration;
    scanf("%d", &duration);

    printf("Enter name: ");
    char name[100];
    scanf("%s", name);

    if (isAvailable(startTime, endTime, duration)) {
        scheduleAppointment(appointmentID, startTime, endTime, duration, name);
    } else {
        printf("Appointment is not available.\n");
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    int appointmentID = rand() % 10 + 1; // Generate random appointment ID
    int startTime = rand() % 1440 + 1; // Generate random start time
    int endTime = rand() % 1440 + startTime; // Generate random end time
    int duration = rand() % 360 + 1; // Generate random duration

    char name[100];
    sprintf(name, "Appointment %d", appointmentID);

    printf("Appointment Details:\n");
    printAppointment(appointmentID, startTime, endTime, duration);
    printf("\n\n");

    getUserInput();

    return 0;
}