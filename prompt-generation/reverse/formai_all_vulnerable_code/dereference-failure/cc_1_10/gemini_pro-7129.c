//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Time using 24-hour format
typedef struct Time {
  int hours;
  int minutes;
} Time;

// Appointment details
typedef struct Appointment {
  Time start_time;
  Time end_time;
  char description[100];
} Appointment;

// Appointment scheduler
typedef struct AppointmentScheduler {
  Appointment* appointments;
  int num_appointments;
  int max_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler* create_appointment_scheduler(int max_appointments) {
  AppointmentScheduler* scheduler = (AppointmentScheduler*) malloc(sizeof(AppointmentScheduler));
  scheduler->appointments = (Appointment*) malloc(max_appointments * sizeof(Appointment));
  scheduler->num_appointments = 0;
  scheduler->max_appointments = max_appointments;
  return scheduler;
}

// Free the memory allocated for the appointment scheduler
void free_appointment_scheduler(AppointmentScheduler* scheduler) {
  free(scheduler->appointments);
  free(scheduler);
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler* scheduler, Appointment appointment) {
  if (scheduler->num_appointments >= scheduler->max_appointments) {
    printf("Error: Maximum number of appointments reached.\n");
    return;
  }

  scheduler->appointments[scheduler->num_appointments] = appointment;
  scheduler->num_appointments++;
}

// Print all the appointments in the scheduler
void print_appointments(AppointmentScheduler* scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("Appointment %d:\n", i + 1);
    printf("  Start time: %02d:%02d\n", scheduler->appointments[i].start_time.hours, scheduler->appointments[i].start_time.minutes);
    printf("  End time: %02d:%02d\n", scheduler->appointments[i].end_time.hours, scheduler->appointments[i].end_time.minutes);
    printf("  Description: %s\n", scheduler->appointments[i].description);
    printf("\n");
  }
}

// Main function
int main() {
  // Create an appointment scheduler
  AppointmentScheduler* scheduler = create_appointment_scheduler(5);

  // Add some appointments to the scheduler
  Appointment appointment1;
  appointment1.start_time.hours = 9;
  appointment1.start_time.minutes = 0;
  appointment1.end_time.hours = 10;
  appointment1.end_time.minutes = 0;
  strcpy(appointment1.description, "Meeting with John");
  add_appointment(scheduler, appointment1);

  Appointment appointment2;
  appointment2.start_time.hours = 11;
  appointment2.start_time.minutes = 0;
  appointment2.end_time.hours = 12;
  appointment2.end_time.minutes = 0;
  strcpy(appointment2.description, "Lunch with Mary");
  add_appointment(scheduler, appointment2);

  Appointment appointment3;
  appointment3.start_time.hours = 14;
  appointment3.start_time.minutes = 0;
  appointment3.end_time.hours = 15;
  appointment3.end_time.minutes = 0;
  strcpy(appointment3.description, "Call with David");
  add_appointment(scheduler, appointment3);

  // Print all the appointments in the scheduler
  print_appointments(scheduler);

  // Free the memory allocated for the appointment scheduler
  free_appointment_scheduler(scheduler);

  return 0;
}