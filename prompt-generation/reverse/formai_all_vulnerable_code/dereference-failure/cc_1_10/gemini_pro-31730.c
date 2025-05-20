//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct appointment {
  char *name;
  char *time;
  char *date;
};

struct appointment_list {
  struct appointment *appointments[MAX_APPOINTMENTS];
  int num_appointments;
};

void init_appointment_list(struct appointment_list *list) {
  list->num_appointments = 0;
}

void add_appointment(struct appointment_list *list, struct appointment *appointment) {
  if (list->num_appointments < MAX_APPOINTMENTS) {
    list->appointments[list->num_appointments++] = appointment;
  }
}

void print_appointment_list(struct appointment_list *list) {
  for (int i = 0; i < list->num_appointments; i++) {
    struct appointment *appointment = list->appointments[i];
    printf("%s\n", appointment->name);
    printf("%s\n", appointment->time);
    printf("%s\n", appointment->date);
  }
}

int main() {
  struct appointment_list list;
  init_appointment_list(&list);

  struct appointment *appointment = malloc(sizeof(struct appointment));
  appointment->name = "Donald Knuth";
  appointment->time = "10:00 AM";
  appointment->date = "January 1, 2023";
  add_appointment(&list, appointment);

  appointment = malloc(sizeof(struct appointment));
  appointment->name = "Edsger W. Dijkstra";
  appointment->time = "11:00 AM";
  appointment->date = "January 1, 2023";
  add_appointment(&list, appointment);

  appointment = malloc(sizeof(struct appointment));
  appointment->name = "Grace Hopper";
  appointment->time = "12:00 PM";
  appointment->date = "January 1, 2023";
  add_appointment(&list, appointment);

  print_appointment_list(&list);

  return 0;
}