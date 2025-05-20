//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Appointment struct
typedef struct Appointment {
  int id;                // Unique appointment ID
  char *description;     // Appointment description
  int day;               // Day of the appointment (1-31)
  int month;             // Month of the appointment (1-12)
  int year;              // Year of the appointment (YYYY)
  int start_time;        // Start time of the appointment (HHMM)
  int end_time;          // End time of the appointment (HHMM)
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
  Appointment *appointments; // Array of appointments
  int num_appointments;     // Number of appointments
  int max_appointments;    // Maximum number of appointments
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *create_appointment_scheduler() {
  AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
  scheduler->appointments = NULL;
  scheduler->num_appointments = 0;
  scheduler->max_appointments = 10;
  return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment appointment) {
  // Check if the scheduler is full
  if (scheduler->num_appointments >= scheduler->max_appointments) {
    printf("Error: Appointment scheduler is full!\n");
    return;
  }

  // Allocate memory for the new appointment
  scheduler->appointments = realloc(scheduler->appointments, (scheduler->num_appointments + 1) * sizeof(Appointment));

  // Copy the appointment data into the array
  scheduler->appointments[scheduler->num_appointments] = appointment;

  // Increment the number of appointments
  scheduler->num_appointments++;
}

// Find an appointment by its ID
Appointment *find_appointment_by_id(AppointmentScheduler *scheduler, int id) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    if (scheduler->appointments[i].id == id) {
      return &scheduler->appointments[i];
    }
  }

  return NULL;
}

// Print all appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    Appointment appointment = scheduler->appointments[i];
    printf("Appointment ID: %d\n", appointment.id);
    printf("Description: %s\n", appointment.description);
    printf("Date: %d/%d/%d\n", appointment.day, appointment.month, appointment.year);
    printf("Start time: %d\n", appointment.start_time);
    printf("End time: %d\n\n", appointment.end_time);
  }
}

// Free the memory used by the appointment scheduler
void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i].description);
  }

  free(scheduler->appointments);
  free(scheduler);
}

// Main function
int main() {
  // Create a new appointment scheduler
  AppointmentScheduler *scheduler = create_appointment_scheduler();

  // Add some appointments to the scheduler
  Appointment appointment1 = {
    .id = 1,
    .description = "Meeting with the boss",
    .day = 10,
    .month = 3,
    .year = 2023,
    .start_time = 900,
    .end_time = 1000
  };

  add_appointment(scheduler, appointment1);

  Appointment appointment2 = {
    .id = 2,
    .description = "Doctor's appointment",
    .day = 15,
    .month = 3,
    .year = 2023,
    .start_time = 1100,
    .end_time = 1200
  };

  add_appointment(scheduler, appointment2);

  // Print all appointments in the scheduler
  print_appointments(scheduler);

  // Find an appointment by its ID
  Appointment *appointment3 = find_appointment_by_id(scheduler, 2);

  // Print the found appointment
  printf("Found appointment: %d\n", appointment3->id);

  // Free the memory used by the appointment scheduler
  destroy_appointment_scheduler(scheduler);

  return 0;
}