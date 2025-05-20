//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct {
  char *description;
  int start_time;
  int end_time;
} appointment;

// Create an array of appointments
appointment appointments[MAX_APPOINTMENTS];

// Initialize the number of appointments to 0
int num_appointments = 0;

// Function to add an appointment to the array
void add_appointment(char *description, int start_time, int end_time) {
  // Check if the array is full
  if (num_appointments >= MAX_APPOINTMENTS) {
    printf("Error: The array is full.\n");
    return;
  }

  // Allocate memory for the description
  appointments[num_appointments].description = malloc(strlen(description) + 1);

  // Copy the description into the array
  strcpy(appointments[num_appointments].description, description);

  // Set the start and end times
  appointments[num_appointments].start_time = start_time;
  appointments[num_appointments].end_time = end_time;

  // Increment the number of appointments
  num_appointments++;
}

// Function to print the appointments
void print_appointments() {
  // Iterate over the appointments
  for (int i = 0; i < num_appointments; i++) {
    // Print the description, start time, and end time
    printf("%s %d %d\n", appointments[i].description, appointments[i].start_time, appointments[i].end_time);
  }
}

// Function to find the first available time slot
int find_available_time_slot(int start_time, int end_time) {
  // Iterate over the appointments
  for (int i = 0; i < num_appointments; i++) {
    // Check if the time slot is available
    if (appointments[i].start_time >= end_time || appointments[i].end_time <= start_time) {
      return 1;
    }
  }

  // Return 0 if no time slot is available
  return 0;
}

// Main function
int main() {
  // Add a few appointments to the array
  add_appointment("Meeting with John", 9, 10);
  add_appointment("Meeting with Mary", 10, 11);
  add_appointment("Meeting with Bob", 11, 12);

  // Print the appointments
  print_appointments();

  // Find the first available time slot
  int start_time = 10;
  int end_time = 11;
  int available = find_available_time_slot(start_time, end_time);

  // Print the result
  if (available) {
    printf("The time slot from %d to %d is available.\n", start_time, end_time);
  } else {
    printf("No time slot is available.\n");
  }

  return 0;
}