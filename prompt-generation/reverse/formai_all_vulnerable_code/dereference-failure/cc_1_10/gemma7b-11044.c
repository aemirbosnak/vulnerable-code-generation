//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
}

void printAppointments(Appointment* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    time_t currentTime = time(NULL);
    struct tm* currentTimeStruct = localtime(&currentTime);
    int currentYear = currentTimeStruct->tm_year + 1900;
    int currentMonth = currentTimeStruct->tm_mon + 1;
    int currentDay = currentTimeStruct->tm_mday;

    Appointment* head = NULL;

    // Create a few sample appointments
    createAppointment("John Doe", "2023-04-01", "10:00");
    createAppointment("Jane Doe", "2023-04-02", "12:00");
    createAppointment("Peter Pan", "2023-04-03", "14:00");

    // Print all appointments
    printAppointments(head);

    return 0;
}