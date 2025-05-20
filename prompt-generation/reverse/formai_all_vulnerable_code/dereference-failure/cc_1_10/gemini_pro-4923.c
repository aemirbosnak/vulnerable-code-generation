//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the appointment structure
typedef struct appointment {
  char time[20];
  char description[255];
} appointment;

// Define the linked list node structure
typedef struct node {
  appointment data;
  struct node *next;
} node;

// Define the linked list head pointer
node *head = NULL;

// Define the current date and time
time_t current_time;
struct tm *current_tm;

// Function to add an appointment
void add_appointment(char *time, char *description) {
  // Create a new appointment
  appointment new_appointment;
  strcpy(new_appointment.time, time);
  strcpy(new_appointment.description, description);

  // Create a new linked list node
  node *new_node = malloc(sizeof(node));
  new_node->data = new_appointment;
  new_node->next = NULL;

  // Add the new node to the linked list
  if (head == NULL) {
    head = new_node;
  } else {
    node *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

// Function to print the appointments
void print_appointments() {
  // Get the current date and time
  current_time = time(NULL);
  current_tm = localtime(&current_time);

  // Print the current date and time
  printf("Current Date and Time: %s\n", asctime(current_tm));

  // Print the appointments
  node *current_node = head;
  while (current_node != NULL) {
    printf("%s - %s\n", current_node->data.time, current_node->data.description);
    current_node = current_node->next;
  }
}

// Function to delete an appointment
void delete_appointment(char *time) {
  // Find the appointment to delete
  node *current_node = head;
  while (current_node != NULL && strcmp(current_node->data.time, time) != 0) {
    current_node = current_node->next;
  }

  // If the appointment was found, delete it
  if (current_node != NULL) {
    if (current_node == head) {
      head = current_node->next;
    } else {
      node *previous_node = head;
      while (previous_node->next != current_node) {
        previous_node = previous_node->next;
      }
      previous_node->next = current_node->next;
    }
    free(current_node);
  }
}

// Function to get user input
void get_user_input() {
  char input[256];
  char time[20];
  char description[255];

  while (1) {
    // Print the menu
    printf("\nMenu:\n");
    printf("1. Add an appointment\n");
    printf("2. Print the appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Quit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%s", input);

    // Handle the user's choice
    switch (input[0]) {
      case '1':
        // Get the appointment time
        printf("Enter the appointment time (hh:mm): ");
        scanf("%s", time);

        // Get the appointment description
        printf("Enter the appointment description: ");
        scanf(" %[^\n]%*c", description);

        // Add the appointment
        add_appointment(time, description);
        break;
      case '2':
        // Print the appointments
        print_appointments();
        break;
      case '3':
        // Get the appointment time
        printf("Enter the appointment time to delete (hh:mm): ");
        scanf("%s", time);

        // Delete the appointment
        delete_appointment(time);
        break;
      case '4':
        // Quit the program
        exit(0);
      default:
        // Invalid input
        printf("Invalid input. Please try again.\n");
    }
  }
}

// Main function
int main() {
  // Get user input
  get_user_input();

  return 0;
}