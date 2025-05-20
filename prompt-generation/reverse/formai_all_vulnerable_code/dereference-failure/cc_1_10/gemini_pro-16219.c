//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Appointment {
  char *description;
  time_t start_time;
  time_t end_time;
  struct Appointment *next;
} Appointment;

Appointment *new_appointment(char *description, time_t start_time, time_t end_time) {
  Appointment *appointment = malloc(sizeof(Appointment));
  appointment->description = strdup(description);
  appointment->start_time = start_time;
  appointment->end_time = end_time;
  appointment->next = NULL;
  return appointment;
}

void free_appointment(Appointment *appointment) {
  free(appointment->description);
  free(appointment);
}

void print_appointment(Appointment *appointment) {
  printf("%s: %s - %s\n", appointment->description, ctime(&appointment->start_time), ctime(&appointment->end_time));
}

Appointment *insert_appointment(Appointment *head, Appointment *new_appointment) {
  if (head == NULL) {
    return new_appointment;
  }
  if (new_appointment->start_time < head->start_time) {
    new_appointment->next = head;
    return new_appointment;
  }
  head->next = insert_appointment(head->next, new_appointment);
  return head;
}

Appointment *find_appointment(Appointment *head, time_t start_time, time_t end_time) {
  if (head == NULL) {
    return NULL;
  }
  if (head->start_time <= start_time && head->end_time >= end_time) {
    return head;
  }
  return find_appointment(head->next, start_time, end_time);
}

Appointment *delete_appointment(Appointment *head, Appointment *appointment) {
  if (head == NULL || appointment == NULL) {
    return head;
  }
  if (head == appointment) {
    head = head->next;
    free_appointment(appointment);
    return head;
  }
  head->next = delete_appointment(head->next, appointment);
  return head;
}

void print_appointments(Appointment *head) {
  if (head == NULL) {
    printf("No appointments scheduled.\n");
    return;
  }
  print_appointment(head);
  print_appointments(head->next);
}

int main() {
  Appointment *head = NULL;

  head = insert_appointment(head, new_appointment("Doctor's appointment", time(NULL) + 3600, time(NULL) + 4200));
  head = insert_appointment(head, new_appointment("Meeting with boss", time(NULL) + 7200, time(NULL) + 8400));
  head = insert_appointment(head, new_appointment("Dinner with friends", time(NULL) + 10800, time(NULL) + 12000));

  print_appointments(head);

  Appointment *found_appointment = find_appointment(head, time(NULL) + 7200, time(NULL) + 8400);
  if (found_appointment != NULL) {
    printf("Found appointment: ");
    print_appointment(found_appointment);
  } else {
    printf("No appointment found.\n");
  }

  head = delete_appointment(head, found_appointment);

  print_appointments(head);

  return 0;
}