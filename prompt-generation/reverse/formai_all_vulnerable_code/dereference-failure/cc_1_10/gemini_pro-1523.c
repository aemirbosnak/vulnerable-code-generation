//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: brave
// Bold C-Language Fitness Tracker
// Embark on a Fitness Odyssey!

#include <stdio.h>
#include <time.h>

// Macros for Epicness
#define PRESS_ENTER printf("Press Enter to Continue...");
#define CLEAR_SCREEN printf("\033[H\033[J");

// Voyage Initialization
int main() {
  // Intruder Alert! Avast!
  int intrudersDetected = 0;

  // Captain's Log
  time_t rawTime;
  struct tm * timeInfo;

  // Fitness Parameters
  int steps, distance, calories;

  // Embark on the Quest
  while (1) {
    // Prepare for Perils
    time(&rawTime);
    timeInfo = localtime(&rawTime);

    // Log the Mighty Deeds
    printf("[%02d:%02d:%02d]\n", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
    printf("----------------------------------\n");

    // Distance Traveled
    printf("Distance (m): ");
    scanf("%d", &distance);

    // Calories Burned
    printf("Calories Burned: ");
    scanf("%d", &calories);

    // Steps Conquered
    printf("Steps Taken: ");
    scanf("%d", &steps);

    // Check for Intruders
    if (distance < 0 || calories < 0 || steps < 0) {
      intrudersDetected++;
      printf("Intruders Detected: %d\n", intrudersDetected);
      if (intrudersDetected >= 3) {
        printf("Security Breach! Abort Mission!\n");
        PRESS_ENTER;
        break;
      }
    }

    // Clear the Decks
    CLEAR_SCREEN;
  }

  // Raise the Jolly Roger
  printf("\nQuest Complete, Brave Soul!\n");

  // Farewell, Matey!
  return 0;
}