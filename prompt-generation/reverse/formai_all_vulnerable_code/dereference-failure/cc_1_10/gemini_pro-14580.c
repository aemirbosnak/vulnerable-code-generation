//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Appointment {
  char description[50];
  int day;
  int month;
  int year;
  int hour;
  int minute;
  bool is_scheduled;
};

struct AppointmentList {
  struct Appointment *appointments;
  int size;
  int capacity;
};

struct AppointmentList *create_appointment_list(int capacity) {
  struct AppointmentList *list = malloc(sizeof(struct AppointmentList));
  list->appointments = malloc(sizeof(struct Appointment) * capacity);
  list->size = 0;
  list->capacity = capacity;
  return list;
}

void add_appointment(struct AppointmentList *list, struct Appointment *appointment) {
  if (list->size == list->capacity) {
    list->capacity *= 2;
    list->appointments = realloc(list->appointments, sizeof(struct Appointment) * list->capacity);
  }
  list->appointments[list->size++] = *appointment;
}

void print_appointment(struct Appointment *appointment) {
  printf("%s, %d/%d/%d, %02d:%02d\n", appointment->description, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
}

void print_appointment_list(struct AppointmentList *list) {
  for (int i = 0; i < list->size; i++) {
    print_appointment(&list->appointments[i]);
  }
}

int main() {
  struct AppointmentList *list = create_appointment_list(10);
  struct Appointment appointment;

  strcpy(appointment.description, "Doctor's appointment");
  appointment.day = 15;
  appointment.month = 3;
  appointment.year = 2023;
  appointment.hour = 10;
  appointment.minute = 30;
  appointment.is_scheduled = true;
  add_appointment(list, &appointment);

  strcpy(appointment.description, "Meeting with boss");
  appointment.day = 20;
  appointment.month = 3;
  appointment.year = 2023;
  appointment.hour = 14;
  appointment.minute = 0;
  appointment.is_scheduled = true;
  add_appointment(list, &appointment);

  strcpy(appointment.description, "Dinner with friends");
  appointment.day = 25;
  appointment.month = 3;
  appointment.year = 2023;
  appointment.hour = 19;
  appointment.minute = 0;
  appointment.is_scheduled = false;
  add_appointment(list, &appointment);

  print_appointment_list(list);

  return 0;
}