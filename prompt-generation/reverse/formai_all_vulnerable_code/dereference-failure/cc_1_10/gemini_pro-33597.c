//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years that can be traveled
#define MAX_YEARS 100

// Define the minimum number of years that can be traveled
#define MIN_YEARS -100

// Define the probability of successfully traveling through time
#define PROBABILITY_OF_SUCCESS 0.5

// Define the minimum age that a person can be to travel through time
#define MIN_AGE 18

// Define the maximum age that a person can be to travel through time
#define MAX_AGE 120

// Get the current year from the system
int get_current_year() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  return tm->tm_year + 1900;
}

// Get the user's age from the system
int get_user_age() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  return tm->tm_year + 1900 - tm->tm_yday;
}

// Get the user's desired destination year
int get_destination_year() {
  int year;
  printf("Enter the year you would like to travel to: ");
  scanf("%d", &year);
  return year;
}

// Check if the user is eligible to travel through time
int is_eligible(int age) {
  return age >= MIN_AGE && age <= MAX_AGE;
}

// Check if the user's desired destination year is valid
int is_valid_destination(int year) {
  return year >= get_current_year() + MIN_YEARS && year <= get_current_year() + MAX_YEARS;
}

// Generate a random number between 0 and 1
double generate_random_number() {
  return (double)rand() / (double)RAND_MAX;
}

// Simulate the time travel process
int time_travel(int age, int year) {
  // Check if the user is eligible to travel through time
  if (!is_eligible(age)) {
    printf("You are not eligible to travel through time.\n");
    return -1;
  }

  // Check if the user's desired destination year is valid
  if (!is_valid_destination(year)) {
    printf("Your desired destination year is not valid.\n");
    return -1;
  }

  // Generate a random number to determine if the time travel was successful
  double random_number = generate_random_number();

  // If the random number is less than the probability of success, then the time travel was successful
  if (random_number < PROBABILITY_OF_SUCCESS) {
    printf("You have successfully traveled to the year %d.\n", year);
    return 0;
  } else {
    printf("You have failed to travel through time.\n");
    return -1;
  }
}

int main() {
  // Get the current year
  int current_year = get_current_year();

  // Get the user's age
  int age = get_user_age();

  // Get the user's desired destination year
  int year = get_destination_year();

  // Simulate the time travel process
  int result = time_travel(age, year);

  // Print the result of the simulation
  if (result == 0) {
    printf("Congratulations! You have successfully traveled to the year %d.\n", year);
  } else {
    printf("Sorry, you have failed to travel through time.\n");
  }

  return 0;
}