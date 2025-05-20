//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

struct Appointment {
  char name[50];
  int hour;
  int minute;
  struct Appointment* next;
};

struct Appointment* createAppointment(char* name, int hour, int minute) {
  struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
  strcpy(newAppointment->name, name);
  newAppointment->hour = hour;
  newAppointment->minute = minute;
  newAppointment->next = NULL;
  return newAppointment;
}

void addAppointment(struct Appointment* head, char* name, int hour, int minute) {
  struct Appointment* newAppointment = createAppointment(name, hour, minute);
  if (head == NULL) {
    head = newAppointment;
  } else {
    struct Appointment* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newAppointment;
  }
}

void printAppointments(struct Appointment* head) {
  struct Appointment* temp = head;
  while (temp) {
    printf("%s at %d:%d\n", temp->name, temp->hour, temp->minute);
    temp = temp->next;
  }
}

int main() {
  struct Appointment* head = NULL;
  addAppointment(head, "John Doe", 10, 30);
  addAppointment(head, "Jane Doe", 12, 00);
  addAppointment(head, "Peter Pan", 14, 30);
  printAppointments(head);

  return 0;
}