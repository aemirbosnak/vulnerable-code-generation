//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A struct to represent a time traveler.
typedef struct {
  int year;
  int month;
  int day;
} TimeTraveler;

// A function to initialize a time traveler.
void initTimeTraveler(TimeTraveler *timeTraveler, int year, int month, int day) {
  timeTraveler->year = year;
  timeTraveler->month = month;
  timeTraveler->day = day;
}

// A function to print a time traveler.
void printTimeTraveler(TimeTraveler *timeTraveler) {
  printf("%d-%d-%d\n", timeTraveler->year, timeTraveler->month, timeTraveler->day);
}

// A function to travel to a future date.
void travelToFuture(TimeTraveler *timeTraveler, int years, int months, int days) {
  timeTraveler->year += years;
  timeTraveler->month += months;
  timeTraveler->day += days;

  // Handle the case where the month is greater than 12.
  while (timeTraveler->month > 12) {
    timeTraveler->month -= 12;
    timeTraveler->year++;
  }

  // Handle the case where the day is greater than the number of days in the month.
  int daysInMonth = 31;
  switch (timeTraveler->month) {
    case 2:
      daysInMonth = 28;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      daysInMonth = 30;
      break;
  }

  while (timeTraveler->day > daysInMonth) {
    timeTraveler->day -= daysInMonth;
    timeTraveler->month++;
  }
}

// A function to travel to a past date.
void travelToPast(TimeTraveler *timeTraveler, int years, int months, int days) {
  timeTraveler->year -= years;
  timeTraveler->month -= months;
  timeTraveler->day -= days;

  // Handle the case where the month is less than 1.
  while (timeTraveler->month < 1) {
    timeTraveler->month += 12;
    timeTraveler->year--;
  }

  // Handle the case where the day is less than 1.
  while (timeTraveler->day < 1) {
    timeTraveler->day += 31;
    timeTraveler->month--;
  }
}

// A function to generate a random date.
void generateRandomDate(TimeTraveler *timeTraveler) {
  // Get the current time.
  time_t now = time(NULL);

  // Convert the current time to a tm struct.
  struct tm *tm = localtime(&now);

  // Set the year, month, and day of the time traveler to a random date within the last 100 years.
  timeTraveler->year = tm->tm_year - (rand() % 100);
  timeTraveler->month = tm->tm_mon + 1;
  timeTraveler->day = tm->tm_mday;
}

// A function to test the time travel simulator.
void testTimeTravelSimulator() {
  // Create a time traveler.
  TimeTraveler timeTraveler;

  // Initialize the time traveler to the current date.
  generateRandomDate(&timeTraveler);

  // Print the initial date.
  printf("Initial date: ");
  printTimeTraveler(&timeTraveler);

  // Travel to the future by 10 years, 5 months, and 3 days.
  travelToFuture(&timeTraveler, 10, 5, 3);

  // Print the future date.
  printf("Future date: ");
  printTimeTraveler(&timeTraveler);

  // Travel to the past by 5 years, 2 months, and 1 day.
  travelToPast(&timeTraveler, 5, 2, 1);

  // Print the past date.
  printf("Past date: ");
  printTimeTraveler(&timeTraveler);
}

// The main function.
int main() {
  // Test the time travel simulator.
  testTimeTravelSimulator();

  return 0;
}