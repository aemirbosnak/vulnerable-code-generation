//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main(void)
{
  // Declare the variables we need:
  int temperature; // The temperature in degrees Fahrenheit
  int i; // A loop counter
  int j; // Another loop counter
  char *days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  char *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  time_t now; // The current time
  struct tm *local; // The local time

  // Get the current time:
  time(&now);
  local = localtime(&now);

  // Print the header:
  printf("*********************************************************************************\n");
  printf("*                                                                                 *\n");
  printf("*      Ye Temperature Monitor, ver. 1.0                                           *\n");
  printf("*                                                                                 *\n");
  printf("*********************************************************************************\n");

  // Print the current date:
  printf("** Date: %s, %d %s %d **\n", days[local->tm_wday], local->tm_mday, months[local->tm_mon], local->tm_year + 1900);

  // Print the current time:
  printf("** Time: %d:%02d:%02d **\n", local->tm_hour, local->tm_min, local->tm_sec);

  // Print the temperature:
  temperature = 72; // Get this from a sensor or something
  printf("** Temperature: %d degrees Fahrenheit **\n", temperature);

  // Print the temperature graph:
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < temperature; j++)
    {
      printf("|");
    }
    printf("\n");
  }

  // Print the footer:
  printf("*********************************************************************************\n");

  // Return to the system:
  return 0;
}