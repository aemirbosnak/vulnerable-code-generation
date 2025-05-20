//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
};

struct Appointment* insertAppointment(struct Appointment* head, char* name, char* date, char* time)
{
    struct Appointment* newApp = malloc(sizeof(struct Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    newApp->next = NULL;

    if (head == NULL)
    {
        return newApp;
    }

    head->next = newApp;
    return head;
}

void printAppointments(struct Appointment* head)
{
    struct Appointment* currentApp = head;
    while (currentApp)
    {
        printf("Name: %s\n", currentApp->name);
        printf("Date: %s\n", currentApp->date);
        printf("Time: %s\n", currentApp->time);
        printf("\n");
        currentApp = currentApp->next;
    }
}

int main()
{
    struct Appointment* head = NULL;
    head = insertAppointment(head, "John Doe", "2023-04-01", "10:00");
    head = insertAppointment(head, "Jane Doe", "2023-04-02", "12:00");
    head = insertAppointment(head, "Peter Pan", "2023-04-03", "14:00");

    printAppointments(head);

    return 0;
}