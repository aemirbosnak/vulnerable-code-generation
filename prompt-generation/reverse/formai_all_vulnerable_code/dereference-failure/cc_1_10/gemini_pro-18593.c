//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: excited
// Welcome to the most amazing appointment scheduler you'll ever lay your eyes on!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures for our appointments and scheduler
typedef struct Appointment {
  char *title;
  char *description;
  char *date;
  char *time;
} Appointment;

typedef struct Scheduler {
  Appointment **appointments;
  int num_appointments;
} Scheduler;

// Function prototypes
Scheduler *create_scheduler();
void add_appointment(Scheduler *scheduler, Appointment *appointment);
void print_scheduler(Scheduler *scheduler);
void free_scheduler(Scheduler *scheduler);

// Main function where the magic begins!
int main() {
  // Let's create our very own scheduler
  Scheduler *my_scheduler = create_scheduler();

  // Prepare some exciting appointments to fill up our scheduler
  Appointment *appointment1 = malloc(sizeof(Appointment));
  appointment1->title = "Super Important Meeting";
  appointment1->description = "Discuss the future of the universe";
  appointment1->date = "2023-03-08";
  appointment1->time = "10:00 AM";

  Appointment *appointment2 = malloc(sizeof(Appointment));
  appointment2->title = "Coffee Break Extravaganza";
  appointment2->description = "Indulge in the finest brews and pastries";
  appointment2->date = "2023-03-15";
  appointment2->time = "2:00 PM";

  // Time to add these appointments to our scheduler
  add_appointment(my_scheduler, appointment1);
  add_appointment(my_scheduler, appointment2);

  // Let's peek into our scheduler and admire our appointments
  print_scheduler(my_scheduler);

  // Once we're done, let's tidy up and free our scheduler
  free_scheduler(my_scheduler);

  return 0;
}

// Function to create a brand-new scheduler
Scheduler *create_scheduler() {
  Scheduler *scheduler = malloc(sizeof(Scheduler));
  scheduler->appointments = NULL;
  scheduler->num_appointments = 0;
  return scheduler;
}

// Function to add an appointment to our scheduler
void add_appointment(Scheduler *scheduler, Appointment *appointment) {
  // First, let's make room for the new appointment
  scheduler->appointments =
      realloc(scheduler->appointments, (scheduler->num_appointments + 1) * sizeof(Appointment *));
  // Now, let's welcome the new appointment to the team
  scheduler->appointments[scheduler->num_appointments++] = appointment;
}

// Function to print our scheduler and show off our appointments
void print_scheduler(Scheduler *scheduler) {
  printf("Behold, the grand majesty of your appointments:\n\n");
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("Title: %s\n", scheduler->appointments[i]->title);
    printf("Description: %s\n", scheduler->appointments[i]->description);
    printf("Date: %s\n", scheduler->appointments[i]->date);
    printf("Time: %s\n\n", scheduler->appointments[i]->time);
  }
}

// Function to free our scheduler and release its appointments
void free_scheduler(Scheduler *scheduler) {
  // Let's free up the memory allocated for each appointment
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]->title);
    free(scheduler->appointments[i]->description);
    free(scheduler->appointments[i]->date);
    free(scheduler->appointments[i]->time);
    free(scheduler->appointments[i]);
  }

  // Finally, let's free the scheduler itself
  free(scheduler->appointments);
  free(scheduler);
}