//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 100

typedef struct {
  char *description;
  time_t start_time;
  time_t end_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *description, time_t start_time, time_t end_time) {
  if (num_appointments >= MAX_APPOINTMENTS) {
    fprintf(stderr, "Error: Too many appointments.  Max = %d\n", MAX_APPOINTMENTS);
    exit(1);
  }

  appointments[num_appointments].description = strdup(description);
  appointments[num_appointments].start_time = start_time;
  appointments[num_appointments].end_time = end_time;
  num_appointments++;
}

void print_appointments() {
  for (int i = 0; i < num_appointments; i++) {
    printf("%s: %s - %s\n", appointments[i].description,
           ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
  }
}

int main(int argc, char *argv[]) {
  time_t start_time, end_time;
  char description[MAX_APPOINTMENT_LENGTH];

  if (argc < 4) {
    fprintf(stderr, "Usage: %s <description> <start time> <end time>\n", argv[0]);
    exit(1);
  }

  strcpy(description, argv[1]);
  start_time = atoi(argv[2]);
  end_time = atoi(argv[3]);

  add_appointment(description, start_time, end_time);
  print_appointments();

  return 0;
}