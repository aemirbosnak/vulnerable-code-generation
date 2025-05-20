//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <time.h>

int main() {
  // Welcome the time traveler!
  printf("Greetings, intrepid time traveler! Welcome to the Time Travel Simulator 3000!\n\n");

  // Let's set the current time.
  time_t now = time(NULL);
  struct tm *current = localtime(&now);

  // Now, where would you like to go?
  printf("Enter the date and time you'd like to visit (in YYYY-MM-DD HH:MM:SS format): ");
  char destination[20];
  scanf("%s", destination);

  // Time to hop into the time machine!
  struct tm *dest = malloc(sizeof(struct tm));
  strptime(destination, "%Y-%m-%d %H:%M:%S", dest);
  time_t timestamp = mktime(dest);

  if (timestamp == (time_t)-1) {
    // Oops, something went wrong with that time.
    printf("Invalid time format. Please try again.\n");
  } else {
    // Here we go!
    printf("Whoosh! You've arrived in %s!\n", destination);

    // Let's see what the weather's like.
    time_t weather_now = time(NULL);
    struct tm *weather_current = localtime(&weather_now);
    weather_current->tm_year = dest->tm_year;
    weather_current->tm_mon = dest->tm_mon;
    weather_current->tm_mday = dest->tm_mday;
    weather_current->tm_hour = dest->tm_hour;
    weather_current->tm_min = dest->tm_min;
    weather_current->tm_sec = dest->tm_sec;
    double temp = 20 + rand() % 10; // Just a random guess :)
    printf("The weather is a pleasant %f degrees Celsius.\n", temp);

    // How about some local news?
    printf("Here's a headline from the local newspaper:\n");
    char headlines[][100] = {"Time Traveler Visits Our Fair Town!", "Local Inventor Unveils Time Machine", "Scientists Baffled by Time Travel Phenomenon"};
    printf("%s\n", headlines[rand() % 3]);

    // Time to head back?
    printf("Your time here is up. It's time to return to the present.\n");

    // Back to the future!
    timestamp = mktime(current);
    now = timestamp;
    printf("Whoosh! You're back in the present.\n");
  }

  // See you later, time traveler!
  printf("Thank you for using the Time Travel Simulator 3000! Safe travels!");

  return 0;
}