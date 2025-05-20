//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
  char name[50];
  char date[50];
  char time[50];
  struct Appointment* next;
};

struct Appointment* createAppointment(char* name, char* date, char* time) {
  struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
  strcpy(newAppointment->name, name);
  strcpy(newAppointment->date, date);
  strcpy(newAppointment->time, time);
  newAppointment->next = NULL;
  return newAppointment;
}

struct Appointment* insertAppointment(struct Appointment* head, char* name, char* date, char* time) {
  struct Appointment* newAppointment = createAppointment(name, date, time);
  if (head == NULL) {
    return newAppointment;
  }
  struct Appointment* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newAppointment;
  return head;
}

void printAppointments(struct Appointment* head) {
  struct Appointment* current = head;
  while (current) {
    printf("Name: %s\n", current->name);
    printf("Date: %s\n", current->date);
    printf("Time: %s\n", current->time);
    printf("\n");
    current = current->next;
  }
}

int main() {
  struct Appointment* head = NULL;
  head = insertAppointment(head, "John Doe", "2023-08-01", "10:00");
  head = insertAppointment(head, "Jane Doe", "2023-08-02", "12:00");
  head = insertAppointment(head, "Peter Pan", "2023-08-03", "14:00");

  printAppointments(head);

  return 0;
}