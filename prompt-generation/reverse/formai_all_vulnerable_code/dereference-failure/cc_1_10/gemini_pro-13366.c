//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the appointment structure
typedef struct appointment {
  int id;
  char *name;
  char *description;
  time_t start_time;
  time_t end_time;
} appointment_t;

// Create a new appointment
appointment_t *create_appointment(int id, char *name, char *description, time_t start_time, time_t end_time) {
  appointment_t *appointment = malloc(sizeof(appointment_t));
  appointment->id = id;
  appointment->name = name;
  appointment->description = description;
  appointment->start_time = start_time;
  appointment->end_time = end_time;
  return appointment;
}

// Delete an appointment
void delete_appointment(appointment_t *appointment) {
  free(appointment->name);
  free(appointment->description);
  free(appointment);
}

// Print an appointment
void print_appointment(appointment_t *appointment) {
  printf("ID: %d\n", appointment->id);
  printf("Name: %s\n", appointment->name);
  printf("Description: %s\n", appointment->description);
  printf("Start time: %s\n", ctime(&appointment->start_time));
  printf("End time: %s\n", ctime(&appointment->end_time));
}

// Main function
int main() {
  // Create an array of appointments
  appointment_t *appointments[10];

  // Initialize the appointments
  for (int i = 0; i < 10; i++) {
    appointments[i] = create_appointment(i, "Appointment", "This is an appointment.", time(NULL), time(NULL) + 3600);
  }

  // Print the appointments
  for (int i = 0; i < 10; i++) {
    print_appointment(appointments[i]);
  }

  // Delete the appointments
  for (int i = 0; i < 10; i++) {
    delete_appointment(appointments[i]);
  }

  return 0;
}