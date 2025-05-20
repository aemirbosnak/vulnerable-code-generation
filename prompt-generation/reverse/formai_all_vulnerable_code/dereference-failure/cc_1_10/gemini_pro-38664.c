//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments that can be scheduled.
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment.
typedef struct Appointment {
  char *name;
  char *description;
  time_t start_time;
  time_t end_time;
} Appointment;

// Create an array of appointments.
Appointment appointments[MAX_APPOINTMENTS];

// Initialize the number of appointments to 0.
int num_appointments = 0;

// Function to add an appointment to the schedule.
void add_appointment(char *name, char *description, time_t start_time, time_t end_time) {
  // Check if the array of appointments is full.
  if (num_appointments == MAX_APPOINTMENTS) {
    printf("Error: The array of appointments is full.\n");
    return;
  }

  // Allocate memory for the new appointment.
  Appointment *appointment = malloc(sizeof(Appointment));

  // Set the fields of the new appointment.
  appointment->name = strdup(name);
  appointment->description = strdup(description);
  appointment->start_time = start_time;
  appointment->end_time = end_time;

  // Add the new appointment to the array of appointments.
  appointments[num_appointments++] = *appointment;
}

// Function to print the schedule of appointments.
void print_schedule() {
  // Loop through the array of appointments.
  for (int i = 0; i < num_appointments; i++) {
    // Print the fields of the appointment.
    printf("Appointment %d:\n", i + 1);
    printf("  Name: %s\n", appointments[i].name);
    printf("  Description: %s\n", appointments[i].description);
    printf("  Start time: %s\n", ctime(&appointments[i].start_time));
    printf("  End time: %s\n", ctime(&appointments[i].end_time));
  }
}

// Function to free the memory allocated for the appointments.
void free_appointments() {
  // Loop through the array of appointments.
  for (int i = 0; i < num_appointments; i++) {
    // Free the memory allocated for the name and description of the appointment.
    free(appointments[i].name);
    free(appointments[i].description);
  }
}

// Main function.
int main() {
  // Add some appointments to the schedule.
  add_appointment("John Doe", "Meeting with the boss", time(NULL) + 3600, time(NULL) + 7200);
  add_appointment("Jane Doe", "Doctor's appointment", time(NULL) + 10800, time(NULL) + 12600);
  add_appointment("Bill Smith", "Lunch with a friend", time(NULL) + 14400, time(NULL) + 16200);

  // Print the schedule of appointments.
  print_schedule();

  // Free the memory allocated for the appointments.
  free_appointments();

  return 0;
}