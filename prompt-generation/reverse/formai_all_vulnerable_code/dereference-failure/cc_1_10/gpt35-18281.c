//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t now, future;
  struct tm *now_tm, *future_tm;
  char future_str[80];

  printf("Welcome to the Time Travel Simulator!\n");
  printf("Please enter the year you want to travel to: ");
  int year;
  scanf("%d", &year);

  time(&now); // get current time
  now_tm = localtime(&now); // convert current time to tm struct

  future_tm = now_tm; // set future time to current time initially
  future_tm->tm_year = year - 1900; // set future year

  future = mktime(future_tm); // convert future tm struct to time_t

  // check if future time is valid
  if (future == -1) {
    printf("Sorry, time travel to year %d is not possible.\n", year);
    return 1;
  }

  // convert future time to human readable string
  strftime(future_str, sizeof(future_str), "%A, %B %d, %Y", future_tm);

  printf("You are now travelling to the year %d...\n", year);

  for (int i = 5; i >= 0; i--) {
    printf("T-minus %d seconds...\n", i);
    sleep(1);
  }

  printf("\n\nWELCOME TO THE FUTURE!\n\n");

  // print future date and time
  printf("The date is %s\n", future_str);

  // generate random futuristic news
  const char *news[] = {
    "Robots have taken over the world!",
    "The moon is now a popular tourist destination.",
    "Humans have colonized Mars.",
    "Flying cars are a reality!",
    "Virtual reality has replaced traditional schooling.",
    "Artificial intelligence has surpassed human intelligence."
  };

  srand(time(NULL));
  int index = rand() % 6;
  printf("NEWS FLASH: %s\n", news[index]);

  return 0;
}