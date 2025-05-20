//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the function to get the fortune
char *getFortune() {
  // Define an array of possible fortunes
  const char *fortunes[] = {
      "The stars are not in your favor today.",
      "You will meet someone special soon.",
      "Be careful what you wish for, it might come true.",
      "Your hard work will pay off in the end.",
      "The future is looking bright for you.",
      "You will have good luck in love today.",
      "You have a hidden talent that will soon be discovered.",
      "Be kind to yourself and others.",
      "Life is what you make it."
  };

  // Get the number of possible fortunes
  int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);

  // Generate a random number to choose a fortune
  int randomIndex = rand() % numFortunes;

  // Return the chosen fortune
  return (char *) fortunes[randomIndex];
}

// Define the function to get the current time
char *getCurrentTime() {
  // Get the current time
  time_t rawtime;
  time(&rawtime);

  // Convert the time to a string
  char *timeString = ctime(&rawtime);

  // Remove the newline character from the end of the string
  timeString[strlen(timeString) - 1] = '\0';

  // Return the current time
  return timeString;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Print a welcome message
  printf("Welcome to the Automated Fortune Teller!\n\n");

  // Keep asking for fortunes until the user quits
  while (1) {
    // Ask the user if they want a fortune
    printf("Do you want to know your fortune? (y/n) ");
    char answer;
    scanf(" %c", &answer);

    // If the user does not want a fortune, quit the program
    if (answer == 'n') {
      printf("Thanks for using the Automated Fortune Teller!\n");
      return 0;
    }

    // Get the current time
    char *currentTime = getCurrentTime();

    // Get the fortune
    char *fortune = getFortune();

    // Print the fortune and the time
    printf("Your fortune: %s\n", fortune);
    printf("Generated at: %s\n\n", currentTime);
  }

  return 0;
}