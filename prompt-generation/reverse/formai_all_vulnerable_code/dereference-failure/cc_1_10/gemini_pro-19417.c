//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct Appointment {
  char time[10];
  char description[100];
  struct Appointment *next;
} Appointment;

typedef struct Day {
  char day[10];
  Appointment *appointments;
  struct Day *next;
} Day;

// Function prototypes
Day *create_day(char *day);
Appointment *create_appointment(char *time, char *description);
void add_appointment(Day *day, Appointment *appointment);
void print_appointments(Day *day);
void free_appointments(Day *day);
void free_days(Day *day);

// Main function
int main() {
  // Create a new day
  Day *monday = create_day("Monday");

  // Create some appointments
  Appointment *appointment1 = create_appointment("10:00 AM", "Meeting with the boss");
  Appointment *appointment2 = create_appointment("11:00 AM", "Lunch with a client");
  Appointment *appointment3 = create_appointment("1:00 PM", "Presentation to the team");

  // Add the appointments to the day
  add_appointment(monday, appointment1);
  add_appointment(monday, appointment2);
  add_appointment(monday, appointment3);

  // Print the appointments for the day
  print_appointments(monday);

  // Free the appointments and the day
  free_appointments(monday);
  free_days(monday);

  return 0;
}

// Function to create a new day
Day *create_day(char *day) {
  Day *new_day = malloc(sizeof(Day));
  if (new_day == NULL) {
    return NULL;
  }

  strcpy(new_day->day, day);
  new_day->appointments = NULL;
  new_day->next = NULL;

  return new_day;
}

// Function to create a new appointment
Appointment *create_appointment(char *time, char *description) {
  Appointment *new_appointment = malloc(sizeof(Appointment));
  if (new_appointment == NULL) {
    return NULL;
  }

  strcpy(new_appointment->time, time);
  strcpy(new_appointment->description, description);
  new_appointment->next = NULL;

  return new_appointment;
}

// Function to add an appointment to a day
void add_appointment(Day *day, Appointment *appointment) {
  if (day->appointments == NULL) {
    day->appointments = appointment;
  } else {
    Appointment *current_appointment = day->appointments;
    while (current_appointment->next != NULL) {
      current_appointment = current_appointment->next;
    }
    current_appointment->next = appointment;
  }
}

// Function to print the appointments for a day
void print_appointments(Day *day) {
  printf("Appointments for %s:\n", day->day);
  Appointment *current_appointment = day->appointments;
  while (current_appointment != NULL) {
    printf("%s - %s\n", current_appointment->time, current_appointment->description);
    current_appointment = current_appointment->next;
  }
}

// Function to free the appointments for a day
void free_appointments(Day *day) {
  Appointment *current_appointment = day->appointments;
  while (current_appointment != NULL) {
    Appointment *next_appointment = current_appointment->next;
    free(current_appointment);
    current_appointment = next_appointment;
  }
}

// Function to free the days
void free_days(Day *day) {
  Day *next_day = day->next;
  free(day);
  day = next_day;
}