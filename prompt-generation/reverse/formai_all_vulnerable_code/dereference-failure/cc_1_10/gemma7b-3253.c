//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment
{
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment** head)
{
    *head = malloc(sizeof(Appointment));
    (*head)->next = NULL;
    return;
}

void addAppointment(Appointment* head, char* name, char* date, char* time)
{
    Appointment* newAppt = malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;

    if (head == NULL)
    {
        head = newAppt;
    }
    else
    {
        head->next = newAppt;
    }
    return;
}

void printAppointments(Appointment* head)
{
    while (head)
    {
        printf("%s (%s) at %s\n", head->name, head->date, head->time);
        head = head->next;
    }
    return;
}

int main()
{
    Appointment* head = NULL;
    createAppointment(&head);
    addAppointment(head, "John Doe", "2023-09-01", "10:00");
    addAppointment(head, "Jane Doe", "2023-09-02", "12:00");
    addAppointment(head, "Bill Smith", "2023-09-03", "14:00");

    printAppointments(head);

    return 0;
}