//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Appointments 10

typedef struct Appointment {
  char name[20];
  char date[20];
  char time[20];
  struct Appointment* next;
} Appointment;

int main() {
  Appointment* head = NULL;
  int i = 0;

  // Allocate memory for appointments
  head = (Appointment*) malloc(MAX_Appointments * sizeof(Appointment));

  // Create a loop to get the number of appointments
  printf("Enter the number of appointments you want to make: ");
  int numAppointments;
  scanf("%d", &numAppointments);

  // Loop to get the details of each appointment
  for (i = 0; i < numAppointments; i++) {
    printf("Enter the name of the appointment: ");
    scanf("%s", head[i].name);

    printf("Enter the date of the appointment: ");
    scanf("%s", head[i].date);

    printf("Enter the time of the appointment: ");
    scanf("%s", head[i].time);

    // Create a new node and insert it into the list
    head[i].next = (Appointment*) malloc(sizeof(Appointment));
    head = head[i].next;
  }

  // Print the appointments
  printf("Your appointments are:\n");
  for (i = 0; i < numAppointments; i++) {
    printf("Name: %s\n", head[i].name);
    printf("Date: %s\n", head[i].date);
    printf("Time: %s\n", head[i].time);
    printf("\n");
  }

  // Free the memory allocated for the appointments
  free(head);

  return 0;
}