//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
  char name[MAX_NAME_LENGTH];
  char date[MAX_NAME_LENGTH];
  char time[MAX_NAME_LENGTH];
  struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void insertAppointment(char* name, char* date, char* time) {
  Appointment* newAppt = malloc(sizeof(Appointment));
  strcpy(newAppt->name, name);
  strcpy(newAppt->date, date);
  strcpy(newAppt->time, time);
  newAppt->next = NULL;

  if (head == NULL) {
    head = newAppt;
  } else {
    Appointment* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newAppt;
  }
}

void printAppointments() {
  Appointment* temp = head;
  while (temp) {
    printf("%s - %s - %s\n", temp->name, temp->date, temp->time);
    temp = temp->next;
  }
}

int main() {
  insertAppointment("John Doe", "2023-04-01", "10:00");
  insertAppointment("Jane Doe", "2023-04-02", "12:00");
  insertAppointment("Peter Pan", "2023-04-03", "14:00");

  printAppointments();

  return 0;
}