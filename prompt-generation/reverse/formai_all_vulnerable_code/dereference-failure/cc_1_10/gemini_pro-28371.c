//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent an appointment
typedef struct Appointment {
  char *startTime;
  char *endTime;
  char *description;
} Appointment;

// Function to create a new appointment
Appointment *createAppointment(char *startTime, char *endTime, char *description) {
  Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
  newAppointment->startTime = startTime;
  newAppointment->endTime = endTime;
  newAppointment->description = description;
  return newAppointment;
}

// Function to print an appointment
void printAppointment(Appointment *appointment) {
  printf("Start Time: %s\n", appointment->startTime);
  printf("End Time: %s\n", appointment->endTime);
  printf("Description: %s\n", appointment->description);
  printf("\n");
}

// Function to compare two appointments by start time
int compareAppointments(const void *a, const void *b) {
  Appointment *appointment1 = (Appointment *)a;
  Appointment *appointment2 = (Appointment *)b;
  return strcmp(appointment1->startTime, appointment2->startTime);
}

// Function to get the current time as a string
char *getCurrentTime() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *currentTime = malloc(20);
  strftime(currentTime, 20, "%Y-%m-%d %H:%M:%S", tm);
  return currentTime;
}

// Main function
int main() {
  // Create an array of appointments
  Appointment *appointments[] = {
      createAppointment("2023-03-08 10:00:00", "2023-03-08 11:00:00", "Meeting with John"),
      createAppointment("2023-03-09 12:00:00", "2023-03-09 13:00:00", "Lunch with Mary"),
      createAppointment("2023-03-10 14:00:00", "2023-03-10 15:00:00", "Call with Bob"),
  };

  // Sort the appointments by start time
  qsort(appointments, sizeof(appointments) / sizeof(appointments[0]), sizeof(Appointment *), compareAppointments);

  // Get the current time
  char *currentTime = getCurrentTime();

  // Print the appointments
  printf("Your upcoming appointments:\n");
  for (int i = 0; i < sizeof(appointments) / sizeof(appointments[0]); i++) {
    if (strcmp(appointments[i]->startTime, currentTime) >= 0) {
      printAppointment(appointments[i]);
    }
  }

  // Free the allocated memory
  for (int i = 0; i < sizeof(appointments) / sizeof(appointments[0]); i++) {
    free(appointments[i]->startTime);
    free(appointments[i]->endTime);
    free(appointments[i]->description);
    free(appointments[i]);
  }
  free(currentTime);

  return 0;
}