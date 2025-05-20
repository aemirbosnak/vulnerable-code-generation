//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct TemporalNexus {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} TemporalNexus;

TemporalNexus temporalNexus(char *date_string) {
  TemporalNexus nexus;
  char *token;
  char **fields;

  token = strtok(date_string, "-");
  nexus.year = atoi(token);

  token = strtok(NULL, "-");
  nexus.month = atoi(token);

  token = strtok(NULL, "-");
  nexus.day = atoi(token);

  token = strtok(NULL, ":");
  nexus.hour = atoi(token);

  token = strtok(NULL, ":");
  nexus.minute = atoi(token);

  nexus.second = atoi(strtok(NULL, ":"));

  return nexus;
}

int main() {
  TemporalNexus nexus = temporalNexus("2222-12-21 14:21:00");

  printf("Temporal Nexus:\n");
  printf("Year: %d\n", nexus.year);
  printf("Month: %d\n", nexus.month);
  printf("Day: %d\n", nexus.day);
  printf("Hour: %d\n", nexus.hour);
  printf("Minute: %d\n", nexus.minute);
  printf("Second: %d\n", nexus.second);

  return 0;
}