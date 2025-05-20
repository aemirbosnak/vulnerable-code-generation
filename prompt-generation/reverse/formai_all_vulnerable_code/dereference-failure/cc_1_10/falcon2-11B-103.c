//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Appointment {
    char *title;
    int startTime;
    int endTime;
};

struct Appointment appointments[100];
int numAppointments = 0;

void addAppointment(char *title, int startTime, int endTime) {
    struct Appointment newAppointment;
    newAppointment.title = (char*)malloc(strlen(title) + 1);
    strcpy(newAppointment.title, title);
    newAppointment.startTime = startTime;
    newAppointment.endTime = endTime;
    appointments[numAppointments] = newAppointment;
    numAppointments++;
}

void removeAppointment(int index) {
    for (int i = index; i < numAppointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    numAppointments--;
}

void printAppointments() {
    for (int i = 0; i < numAppointments; i++) {
        printf("Title: %s\n", appointments[i].title);
        printf("Start Time: %d\n", appointments[i].startTime);
        printf("End Time: %d\n\n", appointments[i].endTime);
    }
}

int main() {
    srand(time(NULL));

    addAppointment("Meeting with John", 10, 12);
    addAppointment("Lunch with Sarah", 13, 14);
    addAppointment("Doctor's Appointment", 15, 16);

    printAppointments();

    removeAppointment(1);

    printAppointments();

    return 0;
}