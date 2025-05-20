//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
  char name[50];
  char date[20];
  char time[20];
  char reason[100];
  struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void schedule_appointment(char* name, char* date, char* time, char* reason) {
  Appointment* new_appointment = (Appointment*)malloc(sizeof(Appointment));

  strcpy(new_appointment->name, name);
  strcpy(new_appointment->date, date);
  strcpy(new_appointment->time, time);
  strcpy(new_appointment->reason, reason);

  new_appointment->next = head;
  head = new_appointment;
}

void print_appointments() {
  Appointment* current = head;

  while (current) {
    printf("Name: %s\n", current->name);
    printf("Date: %s\n", current->date);
    printf("Time: %s\n", current->time);
    printf("Reason: %s\n", current->reason);
    printf("\n");
    current = current->next;
  }
}

int main() {
  schedule_appointment("John Doe", "2023-08-01", "10:00", "Medical appointment");
  schedule_appointment("Jane Doe", "2023-08-02", "15:00", "Haircut");
  schedule_appointment("Peter Pan", "2023-08-03", "12:00", "Dental checkup");

  print_appointments();

  return 0;
}