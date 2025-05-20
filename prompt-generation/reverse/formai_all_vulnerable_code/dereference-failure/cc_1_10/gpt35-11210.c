//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *timeTravel(void *arg) {
  time_t current_time;
  struct tm *time_info;
  char timeString[9];

  int yearsToTravel = *((int *)arg);

  // Get the current time
  current_time = time(NULL);
  time_info = localtime(&current_time);

  // Add years to the current time
  time_info->tm_year = time_info->tm_year + yearsToTravel;
  current_time = mktime(time_info);

  // Convert the time to a string
  strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

  // Print the new time
  printf("Time Traveler: %d year(s) into the future, the time is %s\n", yearsToTravel, timeString);
  
  // Release the argument memory
  free(arg);

  // Exit the thread
  pthread_exit(NULL);
}

int main() {
  pthread_t timeTraveler1, timeTraveler2, timeTraveler3;

  // Allocate argument memory for the time travelers
  int *travelTime1 = malloc(sizeof(int));
  int *travelTime2 = malloc(sizeof(int));
  int *travelTime3 = malloc(sizeof(int));

  // Set travel times
  *travelTime1 = 5;
  *travelTime2 = -10;
  *travelTime3 = 20;

  // Create the time traveler threads
  pthread_create(&timeTraveler1, NULL, timeTravel, travelTime1);
  pthread_create(&timeTraveler2, NULL, timeTravel, travelTime2);
  pthread_create(&timeTraveler3, NULL, timeTravel, travelTime3);

  // Wait for the time traveler threads to finish
  pthread_join(timeTraveler1, NULL);
  pthread_join(timeTraveler2, NULL);
  pthread_join(timeTraveler3, NULL);

  return 0;
}