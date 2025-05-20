//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_APPOINTMENT_LEN 100

struct appointment {
  char *name;
  char *date;
  char *time;
  int duration;
};

struct appointment_book {
  struct appointment appointments[MAX_APPOINTMENTS];
  int num_appointments;
};

struct appointment_book book;

void init_appointment_book() {
  book.num_appointments = 0;
}

void add_appointment(char *name, char *date, char *time, int duration) {
  if (book.num_appointments >= MAX_APPOINTMENTS) {
    printf("Appointment book is full!\n");
    return;
  }

  struct appointment *new_appointment = &book.appointments[book.num_appointments++];
  new_appointment->name = malloc(strlen(name) + 1);
  strcpy(new_appointment->name, name);
  new_appointment->date = malloc(strlen(date) + 1);
  strcpy(new_appointment->date, date);
  new_appointment->time = malloc(strlen(time) + 1);
  strcpy(new_appointment->time, time);
  new_appointment->duration = duration;
}

void print_appointment_book() {
  printf("Appointment Book:\n");
  for (int i = 0; i < book.num_appointments; i++) {
    struct appointment *appointment = &book.appointments[i];
    printf("  %s, %s, %s, %d hours\n", appointment->name, appointment->date, appointment->time, appointment->duration);
  }
}

int main() {
  init_appointment_book();

  add_appointment("Lord Reginald", "12th of June", "10:00 AM", 1);
  add_appointment("Lady Agatha", "15th of June", "2:00 PM", 2);
  add_appointment("Sir Lancelot", "17th of June", "11:00 AM", 3);

  print_appointment_book();

  return 0;
}