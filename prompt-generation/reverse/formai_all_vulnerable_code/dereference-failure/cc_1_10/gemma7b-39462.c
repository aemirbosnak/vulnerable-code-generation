//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment
{
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void displayAppointments(Appointment* head)
{
    while (head)
    {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

void insertAppointment(Appointment* head, char* name, char* date, char* time)
{
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    newApp->next = NULL;

    if (head == NULL)
    {
        head = newApp;
    }
    else
    {
        head->next = newApp;
    }
}

int main()
{
    Appointment* head = NULL;

    insertAppointment(head, "John Doe", "2023-04-01", "10:00");
    insertAppointment(head, "Jane Doe", "2023-04-02", "12:00");
    insertAppointment(head, "Peter Pan", "2023-04-03", "14:00");

    displayAppointments(head);

    return 0;
}