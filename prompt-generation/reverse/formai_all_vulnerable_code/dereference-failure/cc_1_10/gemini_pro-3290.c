//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the maximum length of an appointment name
#define MAX_NAME_LENGTH 50

// Define the maximum length of an appointment description
#define MAX_DESCRIPTION_LENGTH 250

// Define the maximum length of an appointment location
#define MAX_LOCATION_LENGTH 50

// Define the maximum length of an appointment date
#define MAX_DATE_LENGTH 11

// Define the maximum length of an appointment time
#define MAX_TIME_LENGTH 6

// Define the structure of an appointment
typedef struct Appointment {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  char location[MAX_LOCATION_LENGTH];
  char date[MAX_DATE_LENGTH];
  char time[MAX_TIME_LENGTH];
} Appointment;

// Define the structure of the appointment scheduler
typedef struct AppointmentScheduler {
  Appointment appointments[MAX_APPOINTMENTS];
  int numAppointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler* createAppointmentScheduler() {
  AppointmentScheduler* scheduler = malloc(sizeof(AppointmentScheduler));
  scheduler->numAppointments = 0;
  return scheduler;
}

// Add an appointment to the scheduler
void addAppointment(AppointmentScheduler* scheduler, Appointment appointment) {
  if (scheduler->numAppointments < MAX_APPOINTMENTS) {
    scheduler->appointments[scheduler->numAppointments] = appointment;
    scheduler->numAppointments++;
  } else {
    printf("Error: The appointment scheduler is full.\n");
  }
}

// Remove an appointment from the scheduler
void removeAppointment(AppointmentScheduler* scheduler, int index) {
  if (index >= 0 && index < scheduler->numAppointments) {
    for (int i = index; i < scheduler->numAppointments - 1; i++) {
      scheduler->appointments[i] = scheduler->appointments[i + 1];
    }
    scheduler->numAppointments--;
  } else {
    printf("Error: The appointment index is invalid.\n");
  }
}

// Get an appointment from the scheduler
Appointment getAppointment(AppointmentScheduler* scheduler, int index) {
  if (index >= 0 && index < scheduler->numAppointments) {
    return scheduler->appointments[index];
  } else {
    printf("Error: The appointment index is invalid.\n");
    return (Appointment){};
  }
}

// Print the appointment scheduler
void printAppointmentScheduler(AppointmentScheduler* scheduler) {
  printf("Appointments:\n");
  for (int i = 0; i < scheduler->numAppointments; i++) {
    Appointment appointment = scheduler->appointments[i];
    printf("  %s: %s\n", appointment.name, appointment.description);
    printf("    Location: %s\n", appointment.location);
    printf("    Date: %s\n", appointment.date);
    printf("    Time: %s\n", appointment.time);
  }
}

// Main function
int main() {
  // Create an appointment scheduler
  AppointmentScheduler* scheduler = createAppointmentScheduler();

  // Add some appointments to the scheduler
  Appointment appointment1 = {"Meeting with the team", "Discuss the project plan", "Zoom", "2023-03-08", "10:00 AM"};
  addAppointment(scheduler, appointment1);
  Appointment appointment2 = {"Doctor's appointment", "Annual checkup", "Dr. Smith's office", "2023-03-15", "2:00 PM"};
  addAppointment(scheduler, appointment2);
  Appointment appointment3 = {"Dinner with friends", "Celebrate Sarah's birthday", "The French Bistro", "2023-03-22", "7:00 PM"};
  addAppointment(scheduler, appointment3);

  // Print the appointment scheduler
  printAppointmentScheduler(scheduler);

  // Remove an appointment from the scheduler
  removeAppointment(scheduler, 1);

  // Print the appointment scheduler
  printf("\nUpdated appointment scheduler:\n");
  printAppointmentScheduler(scheduler);

  return 0;
}