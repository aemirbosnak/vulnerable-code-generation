//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct appointment {
  char *start_time;
  char *end_time;
  char *location;
  char *description;
} appointment_t;

typedef struct appointment_node {
  appointment_t appointment;
  struct appointment_node *next;
} appointment_node_t;

typedef struct appointment_list {
  appointment_node_t *head;
  appointment_node_t *tail;
} appointment_list_t;

appointment_list_t *create_appointment_list() {
  appointment_list_t *list = malloc(sizeof(appointment_list_t));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void add_appointment(appointment_list_t *list, appointment_t *appointment) {
  appointment_node_t *new_node = malloc(sizeof(appointment_node_t));
  new_node->appointment = *appointment;
  new_node->next = NULL;
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

void print_appointment_list(appointment_list_t *list) {
  appointment_node_t *current = list->head;
  while (current != NULL) {
    printf("Start time: %s\n", current->appointment.start_time);
    printf("End time: %s\n", current->appointment.end_time);
    printf("Location: %s\n", current->appointment.location);
    printf("Description: %s\n\n", current->appointment.description);
    current = current->next;
  }
}

int main() {
  // Create an appointment list
  appointment_list_t *list = create_appointment_list();

  // Add some appointments to the list
  appointment_t appointment1 = {
    .start_time = "9:00 AM",
    .end_time = "10:00 AM",
    .location = "Room 101",
    .description = "Meeting with John"
  };
  add_appointment(list, &appointment1);

  appointment_t appointment2 = {
    .start_time = "11:00 AM",
    .end_time = "12:00 PM",
    .location = "Room 202",
    .description = "Meeting with Mary"
  };
  add_appointment(list, &appointment2);

  // Print the appointment list
  print_appointment_list(list);

  return 0;
}