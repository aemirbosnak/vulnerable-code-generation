//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment
{
    char name[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* CreateAppointment(char* name, char* time)
{
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
}

void AddAppointment(Appointment* head, char* name, char* time)
{
    Appointment* newAppointment = CreateAppointment(name, time);
    if (head == NULL)
    {
        head = newAppointment;
    }
    else
    {
        head->next = newAppointment;
    }
}

void ListAppointments(Appointment* head)
{
    while (head)
    {
        printf("%s at %s\n", head->name, head->time);
        head = head->next;
    }
}

int main()
{
    Appointment* head = NULL;
    AddAppointment(head, "John Doe", "10:00");
    AddAppointment(head, "Jane Doe", "12:00");
    AddAppointment(head, "Peter Pan", "14:00");
    ListAppointments(head);
    return 0;
}