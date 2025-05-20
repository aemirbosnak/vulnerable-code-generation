//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
  char name[50];
  char date[50];
  char time[50];
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

void displayAppointments(Appointment* head) {
  while (head) {
    printf("%s, %s, %s\n", head->name, head->date, head->time);
    head = head->next;
  }
}

int main() {
  Appointment* head = NULL;
  char name[50];
  char date[50];
  char time[50];

  printf("Enter the name of the appointment:");
  scanf("%s", name);

  printf("Enter the date of the appointment:");
  scanf("%s", date);

  printf("Enter the time of the appointment:");
  scanf("%s", time);

  head = createAppointment(name, date, time);

  displayAppointments(head);

  return 0;
}