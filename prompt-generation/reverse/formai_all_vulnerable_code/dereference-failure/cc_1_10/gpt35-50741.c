//FormAI DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Log
{
  char *date;
  char *time;
  char *level;
  char *message;
};

int main()
{
  // Initializing the log variables
  char input[256];
  int logCount = 0;
  int validCount = 0;
  struct Log logs[10];

  printf("Please input your logs (dates, times, levels, messages):\n");

  // Reading user's log inputs
  fgets(input, 256, stdin);

  // Parsing and storing logs information
  char *date = strtok(input, ",");
  while (date != NULL)
  {
    struct Log l;

    // Assigning the date value to Log's date
    l.date = malloc(strlen(date) + 1);
    strcpy(l.date, date);

    // Parsing and assigning time value
    char *time = strtok(NULL, ",");
    l.time = malloc(strlen(time) + 1);
    strcpy(l.time, time);

    // Parsing and assigning level value
    char *level = strtok(NULL, ",");
    l.level = malloc(strlen(level) + 1);
    strcpy(l.level, level);

    // Assigning the rest as message value
    char *message = strtok(NULL, "\n");
    l.message = malloc(strlen(message) + 1);
    strcpy(l.message, message);

    // Adding the current log to logs array
    logs[logCount] = l;
    logCount++;

    printf("\nDo you have another log? Answer with yes or no: ");
    fgets(input, 256, stdin);
    // If user inputs "no", break out of loop
    if (strncmp(input, "no", 2) == 0)
    {
      break;
    }
    // Retrieve next logs
    printf("Please input your next logs: \n");
    fgets(input, 256, stdin);
    date = strtok(input, ",");
  }

  // Printing logs
  printf("\n\nLogs:");
  
  for (int i = 0; i < logCount; i++)
  {
    printf("\nDate: %s", logs[i].date);
    printf("\nTime: %s", logs[i].time);
    printf("\nLevel: %s", logs[i].level);
    printf("\nMessage: %s\n\n", logs[i].message);
  }

  // Freeing memory for logs and its properties
  for (int i = 0; i < logCount; i++)
  {
    free(logs[i].date);
    free(logs[i].time);
    free(logs[i].level);
    free(logs[i].message);
  }

  return 0;
}