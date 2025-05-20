//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an appointment
typedef struct appointment {
  char *name;
  char *date;
  char *time;
} appointment;

// Function to create a new appointment
appointment *create_appointment(char *name, char *date, char *time) {
  appointment *new_appointment = malloc(sizeof(appointment));
  new_appointment->name = malloc(strlen(name) + 1);
  strcpy(new_appointment->name, name);
  new_appointment->date = malloc(strlen(date) + 1);
  strcpy(new_appointment->date, date);
  new_appointment->time = malloc(strlen(time) + 1);
  strcpy(new_appointment->time, time);
  return new_appointment;
}

// Function to print an appointment
void print_appointment(appointment *appt) {
  printf("Name: %s\n", appt->name);
  printf("Date: %s\n", appt->date);
  printf("Time: %s\n", appt->time);
}

// Function to compare two appointments
int compare_appointments(appointment *appt1, appointment *appt2) {
  int result = strcmp(appt1->date, appt2->date);
  if (result == 0) {
    result = strcmp(appt1->time, appt2->time);
  }
  return result;
}

// Function to sort an array of appointments
void sort_appointments(appointment **appts, int num_appts) {
  for (int i = 0; i < num_appts - 1; i++) {
    for (int j = i + 1; j < num_appts; j++) {
      if (compare_appointments(appts[i], appts[j]) > 0) {
        appointment *temp = appts[i];
        appts[i] = appts[j];
        appts[j] = temp;
      }
    }
  }
}

// Function to print an array of appointments
void print_appointments(appointment **appts, int num_appts) {
  for (int i = 0; i < num_appts; i++) {
    print_appointment(appts[i]);
    printf("\n");
  }
}

// Main function
int main() {
  // Create an array of appointments
  appointment *appts[] = {
    create_appointment("John Smith", "2023-03-08", "10:00 AM"),
    create_appointment("Jane Doe", "2023-03-09", "11:00 AM"),
    create_appointment("Bill Jones", "2023-03-10", "12:00 PM"),
    create_appointment("Mary Johnson", "2023-03-11", "1:00 PM"),
    create_appointment("Bob Brown", "2023-03-12", "2:00 PM")
  };

  // Sort the array of appointments
  sort_appointments(appts, 5);

  // Print the array of appointments
  print_appointments(appts, 5);

  // Free the memory allocated for the appointments
  for (int i = 0; i < 5; i++) {
    free(appts[i]->name);
    free(appts[i]->date);
    free(appts[i]->time);
    free(appts[i]);
  }

  return 0;
}