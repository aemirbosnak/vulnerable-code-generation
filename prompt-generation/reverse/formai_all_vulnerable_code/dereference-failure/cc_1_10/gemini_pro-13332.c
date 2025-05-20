//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
  char *description;
  int day;
  int month;
  int year;
  int hour;
  int minute;
} appointment_t;

appointment_t *create_appointment(char *description, int day, int month, int year, int hour, int minute) {
  appointment_t *appointment = malloc(sizeof(appointment_t));
  appointment->description = strdup(description);
  appointment->day = day;
  appointment->month = month;
  appointment->year = year;
  appointment->hour = hour;
  appointment->minute = minute;
  return appointment;
}

void destroy_appointment(appointment_t *appointment) {
  free(appointment->description);
  free(appointment);
}

int compare_appointments(const void *a, const void *b) {
  appointment_t *appointment1 = *(appointment_t **)a;
  appointment_t *appointment2 = *(appointment_t **)b;

  if (appointment1->year < appointment2->year) {
    return -1;
  } else if (appointment1->year > appointment2->year) {
    return 1;
  } else {
    if (appointment1->month < appointment2->month) {
      return -1;
    } else if (appointment1->month > appointment2->month) {
      return 1;
    } else {
      if (appointment1->day < appointment2->day) {
        return -1;
      } else if (appointment1->day > appointment2->day) {
        return 1;
      } else {
        if (appointment1->hour < appointment2->hour) {
          return -1;
        } else if (appointment1->hour > appointment2->hour) {
          return 1;
        } else {
          if (appointment1->minute < appointment2->minute) {
            return -1;
          } else if (appointment1->minute > appointment2->minute) {
            return 1;
          } else {
            return 0;
          }
        }
      }
    }
  }
}

int main() {
  appointment_t *appointments[] = {
    create_appointment("Doctor's appointment", 15, 3, 2023, 10, 30),
    create_appointment("Dentist appointment", 22, 3, 2023, 11, 00),
    create_appointment("Haircut appointment", 29, 3, 2023, 13, 00),
    create_appointment("Movie with friends", 5, 4, 2023, 19, 00),
    create_appointment("Dinner with family", 12, 4, 2023, 18, 00),
  };

  int num_appointments = sizeof(appointments) / sizeof(appointment_t *);

  qsort(appointments, num_appointments, sizeof(appointment_t *), compare_appointments);

  for (int i = 0; i < num_appointments; i++) {
    appointment_t *appointment = appointments[i];
    printf("%s: %02d/%02d/%04d %02d:%02d\n", appointment->description, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
    destroy_appointment(appointment);
  }

  return 0;
}