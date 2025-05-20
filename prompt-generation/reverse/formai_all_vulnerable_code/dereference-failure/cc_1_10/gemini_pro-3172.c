//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store an appointment
typedef struct Appointment {
  int day;
  int month;
  int year;
  char *description;
} Appointment;

// Array to store appointments
Appointment appointments[100];

// Number of appointments
int num_appointments = 0;

// Function to add an appointment
void add_appointment(int day, int month, int year, char *description) {
  // Check if the array is full
  if (num_appointments == 100) {
    printf("Appointment array is full.\n");
    return;
  }

  // Create a new appointment
  Appointment appointment;
  appointment.day = day;
  appointment.month = month;
  appointment.year = year;
  appointment.description = strdup(description);

  // Add the appointment to the array
  appointments[num_appointments] = appointment;

  // Increment the number of appointments
  num_appointments++;
}

// Function to print all appointments
void print_appointments() {
  // Loop through the appointments
  for (int i = 0; i < num_appointments; i++) {
    printf("%d/%d/%d: %s\n", appointments[i].day, appointments[i].month,
           appointments[i].year, appointments[i].description);
  }
}

// Main function
int main() {
  // Add some appointments
  add_appointment(1, 1, 2023, "New Year's Day");
  add_appointment(14, 2, 2023, "Valentine's Day");
  add_appointment(17, 3, 2023, "St. Patrick's Day");
  add_appointment(1, 4, 2023, "April Fool's Day");

  // Print the appointments
  print_appointments();

  return 0;
}