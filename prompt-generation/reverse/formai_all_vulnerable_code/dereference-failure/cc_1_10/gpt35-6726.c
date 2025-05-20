//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
// Ada Lovelace style Appointment Scheduler program
// Author: Ada Lovelace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declare constants
#define MAX_APPTS 10       // maximum number of appointments the scheduler can handle
#define MAX_NAME_LENGTH 20 // limit the length of names to 20 characters
#define MAX_INPUT_LENGTH 50 // limit the length of input to 50 characters

// Declare a structure to represent an appointment
typedef struct Appointment {
  char name[MAX_NAME_LENGTH];
  int month;
  int day;
  int hour;
} Appointment;

// Declare an array of Appointment structures to hold appointments
Appointment appointments[MAX_APPTS];

// Declare a function to prompt the user for input and return their response as a string
char* get_input() {
  char* input = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));
  printf("\n> ");
  fgets(input, MAX_INPUT_LENGTH, stdin);
  strtok(input, "\n");  // remove newline character from input
  return input;
}

// Declare a function to print a single appointment
void print_appointment(Appointment appt) {
  printf("%s: %d/%d @ %d:00\n", appt.name, appt.month, appt.day, appt.hour);
}

// Declare a function to print all appointments
void print_all_appointments() {
  for (int i = 0; i < MAX_APPTS; i++) {
    if (strlen(appointments[i].name) != 0) {  // only print non-empty appointments
      print_appointment(appointments[i]);
    }
  }
}

int main() {
  printf("Welcome to Ada Lovelace's Appointment Scheduler!\n");
  int num_appts = 0; // initialize the number of appointments to zero

  // Prompt user for options
  while (true) {
    printf("\nPlease select an option:\n");
    printf("1. Schedule an appointment\n");
    printf("2. View all appointments\n");
    printf("3. Quit\n");

    char* input = get_input(); // get user input

    // Schedule an appointment
    if (strcmp(input, "1") == 0) {
      if (num_appts >= MAX_APPTS) {
        printf("\nSorry, the scheduler is full.\n");
      } else {
        Appointment appt;
        printf("\nEnter name: ");
        fgets(appt.name, MAX_NAME_LENGTH, stdin);
        strtok(appt.name, "\n");  // remove newline character from name

        printf("Enter month [1-12]: ");
        scanf("%d", &appt.month);
        printf("Enter day [1-31]: ");
        scanf("%d", &appt.day);
        printf("Enter hour [0-23]: ");
        scanf("%d", &appt.hour);

        appointments[num_appts] = appt; // add appointment to array
        num_appts++; // increment number of appointments
      }
    }

    // View all appointments
    else if (strcmp(input, "2") == 0) {
      printf("\nAll Appointments:\n");
      print_all_appointments();
    }

    // Quit
    else if (strcmp(input, "3") == 0) {
      printf("\nGoodbye!\n");
      break;
    }

    // Invalid input
    else {
      printf("\nInvalid input. Please try again.\n");
    }

    free(input); // free memory used by input string
  }

  return 0;
}