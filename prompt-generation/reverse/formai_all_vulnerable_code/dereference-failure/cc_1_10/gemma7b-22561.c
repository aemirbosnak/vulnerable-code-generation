//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **schedule = NULL;
  int size = 0;
  int i = 0;

  schedule = malloc(sizeof(char *) * size);
  schedule[i] = malloc(sizeof(char) * 50);

  printf("Enter the name of the appointment:");
  scanf("%s", schedule[i]);

  printf("Enter the date of the appointment:");
  scanf("%s", schedule[i] + 20);

  printf("Enter the time of the appointment:");
  scanf("%s", schedule[i] + 40);

  size++;

  schedule = realloc(schedule, sizeof(char *) * size);
  schedule[i] = malloc(sizeof(char) * 50);

  printf("Enter the name of the appointment:");
  scanf("%s", schedule[i]);

  printf("Enter the date of the appointment:");
  scanf("%s", schedule[i] + 20);

  printf("Enter the time of the appointment:");
  scanf("%s", schedule[i] + 40);

  size++;

  schedule = realloc(schedule, sizeof(char *) * size);
  schedule[i] = malloc(sizeof(char) * 50);

  printf("Enter the name of the appointment:");
  scanf("%s", schedule[i]);

  printf("Enter the date of the appointment:");
  scanf("%s", schedule[i] + 20);

  printf("Enter the time of the appointment:");
  scanf("%s", schedule[i] + 40);

  size++;

  schedule = realloc(schedule, sizeof(char *) * size);
  schedule[i] = malloc(sizeof(char) * 50);

  for (i = 0; schedule[i] != NULL; i++) {
    printf("Appointment: %s, Date: %s, Time: %s\n", schedule[i], schedule[i] + 20, schedule[i] + 40);
  }

  free(schedule);

  return 0;
}