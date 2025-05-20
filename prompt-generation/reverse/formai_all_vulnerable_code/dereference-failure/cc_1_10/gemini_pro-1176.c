//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment data structure
typedef struct Appointment {
  char *description;  // Description of the appointment
  int day;            // Day of the month (1-31)
  int month;          // Month (1-12)
  int year;           // Year
  int hour;           // Hour (0-23)
  int minute;         // Minute (0-59)
} Appointment;

// Appointment scheduler data structure
typedef struct AppointmentScheduler {
  Appointment **appointments;  // Array of appointments
  int num_appointments;       // Number of appointments
} AppointmentScheduler;

// Create a new appointment
Appointment *create_appointment(char *description, int day, int month, int year, int hour, int minute) {
  Appointment *appointment = malloc(sizeof(Appointment));
  appointment->description = strdup(description);
  appointment->day = day;
  appointment->month = month;
  appointment->year = year;
  appointment->hour = hour;
  appointment->minute = minute;
  return appointment;
}

// Destroy an appointment
void destroy_appointment(Appointment *appointment) {
  free(appointment->description);
  free(appointment);
}

// Create a new appointment scheduler
AppointmentScheduler *create_appointment_scheduler() {
  AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
  scheduler->appointments = malloc(0);
  scheduler->num_appointments = 0;
  return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    destroy_appointment(scheduler->appointments[i]);
  }
  free(scheduler->appointments);
  free(scheduler);
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
  scheduler->appointments = realloc(scheduler->appointments, (scheduler->num_appointments + 1) * sizeof(Appointment *));
  scheduler->appointments[scheduler->num_appointments] = appointment;
  scheduler->num_appointments++;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    if (scheduler->appointments[i] == appointment) {
      // Found the appointment, so remove it
      for (int j = i + 1; j < scheduler->num_appointments; j++) {
        scheduler->appointments[j - 1] = scheduler->appointments[j];
      }
      scheduler->num_appointments--;
      return;
    }
  }
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    Appointment *appointment = scheduler->appointments[i];
    printf("%s: %02d/%02d/%04d %02d:%02d\n", appointment->description, appointment->day, appointment->month, appointment->year, appointment->hour,
           appointment->minute);
  }
}

// Main function
int main() {
  // Create an appointment scheduler
  AppointmentScheduler *scheduler = create_appointment_scheduler();

  // Add some appointments to the scheduler
  add_appointment(scheduler, create_appointment("Doctor's appointment", 15, 3, 2023, 10, 0));
  add_appointment(scheduler, create_appointment("Dentist appointment", 1, 4, 2023, 14, 30));
  add_appointment(scheduler, create_appointment("Haircut appointment", 22, 4, 2023, 16, 0));

  // Print the appointments in the scheduler
  print_appointments(scheduler);

  // Remove an appointment from the scheduler
  remove_appointment(scheduler,
                       scheduler->appointments[1]);  // Remove the second appointment (index 1)

  // Print the appointments in the scheduler again
  print_appointments(scheduler);

  // Destroy the appointment scheduler
  destroy_appointment_scheduler(scheduler);

  return 0;
}