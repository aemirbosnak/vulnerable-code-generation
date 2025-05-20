//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

struct Appointment {
  char name[50];
  char date[10];
  char time[10];
  struct Appointment* next;
};

struct Appointment* insert_appointment(struct Appointment* head) {
  struct Appointment* new_appointment = (struct Appointment*)malloc(sizeof(struct Appointment));

  printf("Enter your name: ");
  scanf("%s", new_appointment->name);

  printf("Enter the date (MM/DD/YY): ");
  scanf("%s", new_appointment->date);

  printf("Enter the time (HH:MM): ");
  scanf("%s", new_appointment->time);

  new_appointment->next = NULL;

  if (head == NULL) {
    head = new_appointment;
  } else {
    head->next = new_appointment;
  }

  return head;
}

void print_appointments(struct Appointment* head) {
  struct Appointment* current = head;

  printf("Your appointments:\n");

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

  // Insert appointments
  head = insert_appointment(head);
  insert_appointment(head);
  insert_appointment(head);

  // Print appointments
  print_appointments(head);

  return 0;
}