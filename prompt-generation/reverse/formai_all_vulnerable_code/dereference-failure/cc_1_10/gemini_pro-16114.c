//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the appointment structure
typedef struct Appointment {
  char name[50];
  char date[20];
  char time[20];
} Appointment;

// Create a new appointment
Appointment* create_appointment(char* name, char* date, char* time) {
  Appointment* appointment = (Appointment*)malloc(sizeof(Appointment));
  strcpy(appointment->name, name);
  strcpy(appointment->date, date);
  strcpy(appointment->time, time);
  return appointment;
}

// Print the appointment details
void print_appointment(Appointment* appointment) {
  printf("Name: %s\n", appointment->name);
  printf("Date: %s\n", appointment->date);
  printf("Time: %s\n", appointment->time);
}

// Compare two appointments by date and time
int compare_appointments(const void* a, const void* b) {
  Appointment* appointment1 = (Appointment*)a;
  Appointment* appointment2 = (Appointment*)b;
  int date_comparison = strcmp(appointment1->date, appointment2->date);
  if (date_comparison == 0) {
    return strcmp(appointment1->time, appointment2->time);
  }
  return date_comparison;
}

// Sort the appointments by date and time
void sort_appointments(Appointment** appointments, int num_appointments) {
  qsort(appointments, num_appointments, sizeof(Appointment*), compare_appointments);
}

// Main function
int main() {
  // Create an array of appointments
  Appointment* appointments[] = {
    create_appointment("John Doe", "2023-03-08", "10:00 AM"),
    create_appointment("Jane Smith", "2023-03-10", "11:00 AM"),
    create_appointment("Bill Jones", "2023-03-12", "12:00 PM"),
    create_appointment("Mary Brown", "2023-03-14", "1:00 PM"),
    create_appointment("Tom Green", "2023-03-16", "2:00 PM")
  };

  // Sort the appointments
  sort_appointments(appointments, 5);

  // Print the sorted appointments
  for (int i = 0; i < 5; i++) {
    print_appointment(appointments[i]);
    printf("\n");
  }

  return 0;
}