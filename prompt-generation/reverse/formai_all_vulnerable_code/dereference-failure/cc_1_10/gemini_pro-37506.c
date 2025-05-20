//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
  int id;
  char *name;
  char *description;
  int start_time;
  int end_time;
} appointment;

typedef struct appointment_node {
  appointment *appointment;
  struct appointment_node *next;
} appointment_node;

typedef struct appointment_list {
  appointment_node *head;
  appointment_node *tail;
} appointment_list;

void add_appointment(appointment_list *list, appointment *appointment) {
  appointment_node *new_node = malloc(sizeof(appointment_node));
  new_node->appointment = appointment;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

void print_appointment(appointment *appointment) {
  printf("ID: %d\n", appointment->id);
  printf("Name: %s\n", appointment->name);
  printf("Description: %s\n", appointment->description);
  printf("Start time: %d\n", appointment->start_time);
  printf("End time: %d\n", appointment->end_time);
  printf("\n");
}

void print_appointment_list(appointment_list *list) {
  appointment_node *current_node = list->head;

  while (current_node != NULL) {
    print_appointment(current_node->appointment);
    current_node = current_node->next;
  }
}

int main() {
  appointment_list *list = malloc(sizeof(appointment_list));
  list->head = NULL;
  list->tail = NULL;

  appointment *appointment1 = malloc(sizeof(appointment));
  appointment1->id = 1;
  appointment1->name = "Doctor's appointment";
  appointment1->description = "Annual checkup";
  appointment1->start_time = 1000;
  appointment1->end_time = 1100;

  appointment *appointment2 = malloc(sizeof(appointment));
  appointment2->id = 2;
  appointment2->name = "Meeting with boss";
  appointment2->description = "Discuss project progress";
  appointment2->start_time = 1400;
  appointment2->end_time = 1500;

  add_appointment(list, appointment1);
  add_appointment(list, appointment2);

  print_appointment_list(list);

  return 0;
}