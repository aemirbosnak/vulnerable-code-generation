//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of years to travel
#define MAX_YEARS 100

// Function to generate a random year between 1900 and 2022
int generateRandomYear() {
  return rand() % (2022 - 1900 + 1) + 1900;
}

// Function to simulate time travel
void timeTravel(int year) {
  printf("You have traveled to the year %d!\n", year);

  // Generate a random event for the year
  int event = rand() % 4;
  switch (event) {
    case 0:
      printf("You meet a famous historical figure!\n");
      break;
    case 1:
      printf("You witness a major historical event!\n");
      break;
    case 2:
      printf("You experience a technological marvel!\n");
      break;
    case 3:
      printf("You learn something new about the past!\n");
      break;
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the current year
  time_t now = time(NULL);
  struct tm *current = localtime(&now);
  int currentYear = current->tm_year + 1900;

  // Get the desired year from the user
  int year;
  printf("Enter the year you want to travel to (1900-%d): ", currentYear);
  scanf("%d", &year);

  // Check if the desired year is in the allowed range
  if (year < 1900 || year > currentYear) {
    printf("Invalid year. Please enter a year between 1900 and %d.\n", currentYear);
    return 1;
  }

  // Simulate time travel
  timeTravel(year);

  return 0;
}