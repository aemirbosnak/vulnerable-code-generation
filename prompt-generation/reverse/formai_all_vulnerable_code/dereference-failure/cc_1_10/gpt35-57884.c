//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
  char date[20]; // Date for the appointment
  char time[20]; // Time of the appointment
  char name[50]; // Name of the patient
  char doctor[50]; // Name of the doctor
} Appointment;

int main() {
  int numAppointments; // Number of appointments to schedule
  printf("How many appointments would you like to schedule? ");
  scanf("%d", &numAppointments);
  getchar(); // flush the input buffer

  Appointment *appointments = (Appointment*) malloc(numAppointments * sizeof(Appointment)); // Allocate memory for the appointments

  for (int i = 0; i < numAppointments; i++) {
    printf("\nAppointment %d of %d\n", i + 1, numAppointments);

    // Get the date of the appointment
    printf("Enter the date of the appointment (DD/MM/YYYY): ");
    fgets(appointments[i].date, 20, stdin);
    appointments[i].date[strcspn(appointments[i].date, "\n")] = '\0'; // remove trailing newline character

    // Get the time of the appointment
    printf("Enter the time of the appointment (HH:MM AM/PM): ");
    fgets(appointments[i].time, 20, stdin);
    appointments[i].time[strcspn(appointments[i].time, "\n")] = '\0'; // remove trailing newline character

    // Get the name of the patient
    printf("Enter the name of the patient: ");
    fgets(appointments[i].name, 50, stdin);
    appointments[i].name[strcspn(appointments[i].name, "\n")] = '\0'; // remove trailing newline character

    // Get the name of the doctor
    printf("Enter the name of the doctor: ");
    fgets(appointments[i].doctor, 50, stdin);
    appointments[i].doctor[strcspn(appointments[i].doctor, "\n")] = '\0'; // remove trailing newline character
  }

  // Print out the appointments
  printf("\nAppointments:\n");
  printf("%-15s %-15s %-25s %s\n", "Date", "Time", "Patient", "Doctor");
  printf("--------------------------------------------------------\n");
  for (int i = 0; i < numAppointments; i++) {
    printf("%-15s %-15s %-25s %s\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].doctor);
  }

  free(appointments); // free the memory

  return 0;
}