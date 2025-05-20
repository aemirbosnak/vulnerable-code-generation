//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the random number generator
void init_rng(void) {
  srand(time(NULL));
}

// Generate a random number between 0 and 1
double rand_double(void) {
  return (double)rand() / (double)RAND_MAX;
}

// Generate a random integer between 0 and n-1
int rand_int(int n) {
  return rand() % n;
}

// Generate a random date between 1900 and 2100
struct tm *rand_date(void) {
  struct tm *tm = malloc(sizeof(struct tm));
  tm->tm_year = rand_int(2100 - 1900) + 1900;
  tm->tm_mon = rand_int(12);
  tm->tm_mday = rand_int(31);
  tm->tm_hour = rand_int(24);
  tm->tm_min = rand_int(60);
  tm->tm_sec = rand_int(60);
  tm->tm_isdst = -1;
  return tm;
}

// Print a date in the format "YYYY-MM-DD HH:MM:SS"
void print_date(struct tm *tm) {
  printf("%04d-%02d-%02d %02d:%02d:%02d",
    tm->tm_year, tm->tm_mon + 1, tm->tm_mday,
    tm->tm_hour, tm->tm_min, tm->tm_sec);
}

// Travel to a random date in the past or future
struct tm *time_travel(struct tm *tm) {
  // Generate a random time interval between -100 and 100 years
  int years = rand_int(201) - 100;

  // Add the time interval to the current date
  tm->tm_year += years;

  // Return the new date
  return tm;
}

int main(void) {
  // Initialize the random number generator
  init_rng();

  // Generate a random current date
  struct tm *current_date = rand_date();

  // Print the current date
  printf("Current date: ");
  print_date(current_date);
  printf("\n");

  // Travel to a random date in the past or future
  struct tm *new_date = time_travel(current_date);

  // Print the new date
  printf("New date: ");
  print_date(new_date);
  printf("\n");

  return 0;
}