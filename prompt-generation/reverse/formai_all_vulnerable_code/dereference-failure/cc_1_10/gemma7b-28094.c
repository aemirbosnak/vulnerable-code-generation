//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Define the futuristic C Fitness Tracker structure
typedef struct CFitnessTracker {
  int heartRate;
  float distanceTraveled;
  char mood;
  double caloriesBurned;
  struct CFitnessTracker *nextPtr;
} CFitnessTracker;

// Function to add a new fitness tracker entry
void addNewEntry(CFitnessTracker **trackerPtr) {
  // Allocate memory for a new tracker entry
  CFitnessTracker *newTracker = malloc(sizeof(CFitnessTracker));

  // Get the user's input
  printf("Enter your heart rate:");
  scanf("%d", &newTracker->heartRate);

  printf("Enter the distance traveled:");
  scanf("%f", &newTracker->distanceTraveled);

  printf("Enter your mood:");
  scanf(" %c", &newTracker->mood);

  printf("Enter the number of calories burned:");
  scanf("%lf", &newTracker->caloriesBurned);

  // Add the new entry to the tracker list
  *trackerPtr = newTracker;
}

// Function to display the fitness tracker entries
void displayEntries(CFitnessTracker *trackerPtr) {
  // Traverse the tracker list and print each entry
  while (trackerPtr) {
    printf("Heart Rate: %d\n", trackerPtr->heartRate);
    printf("Distance Traveled: %.2f miles\n", trackerPtr->distanceTraveled);
    printf("Mood: %c\n", trackerPtr->mood);
    printf("Calories Burned: %.2lf\n", trackerPtr->caloriesBurned);
    printf("\n");
    trackerPtr = trackerPtr->nextPtr;
  }
}

int main() {
  // Create a linked list of fitness tracker entries
  CFitnessTracker *trackerHead = NULL;

  // Add new entries to the list
  addNewEntry(&trackerHead);
  addNewEntry(&trackerHead);
  addNewEntry(&trackerHead);

  // Display the entries in the list
  displayEntries(trackerHead);

  return 0;
}