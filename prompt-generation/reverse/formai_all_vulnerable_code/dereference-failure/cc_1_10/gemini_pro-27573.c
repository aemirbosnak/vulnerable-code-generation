//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment struct
typedef struct Appointment {
  char name[50];
  time_t start_time;
  time_t end_time;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
  Appointment *appointments;
  int num_appointments;
  int max_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *create_appointment_scheduler(int max_appointments) {
  AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
  scheduler->appointments = malloc(sizeof(Appointment) * max_appointments);
  scheduler->num_appointments = 0;
  scheduler->max_appointments = max_appointments;
  return scheduler;
}

// Free the memory allocated for an appointment scheduler
void free_appointment_scheduler(AppointmentScheduler *scheduler) {
  free(scheduler->appointments);
  free(scheduler);
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment appointment) {
  if (scheduler->num_appointments >= scheduler->max_appointments) {
    printf("Error: Appointment scheduler is full.\n");
    return;
  }
  scheduler->appointments[scheduler->num_appointments] = appointment;
  scheduler->num_appointments++;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler *scheduler, int index) {
  if (index < 0 || index >= scheduler->num_appointments) {
    printf("Error: Invalid appointment index.\n");
    return;
  }
  for (int i = index; i < scheduler->num_appointments - 1; i++) {
    scheduler->appointments[i] = scheduler->appointments[i + 1];
  }
  scheduler->num_appointments--;
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    Appointment appointment = scheduler->appointments[i];
    printf("%s: %s - %s\n", appointment.name, ctime(&appointment.start_time), ctime(&appointment.end_time));
  }
}

// Main function
int main() {
  // Create an appointment scheduler with a maximum of 10 appointments
  AppointmentScheduler *scheduler = create_appointment_scheduler(10);

  // Add some appointments to the scheduler
  Appointment appointment1 = {"John Doe", time(NULL), time(NULL) + 3600};
  Appointment appointment2 = {"Jane Doe", time(NULL) + 1800, time(NULL) + 2700};
  Appointment appointment3 = {"Bill Smith", time(NULL) + 3600, time(NULL) + 4500};
  add_appointment(scheduler, appointment1);
  add_appointment(scheduler, appointment2);
  add_appointment(scheduler, appointment3);

  // Print the appointments in the scheduler
  printf("Appointments:\n");
  print_appointments(scheduler);

  // Remove an appointment from the scheduler
  remove_appointment(scheduler, 1);

  // Print the appointments in the scheduler
  printf("Appointments after removing index 1:\n");
  print_appointments(scheduler);

  // Free the memory allocated for the scheduler
  free_appointment_scheduler(scheduler);

  return 0;
}