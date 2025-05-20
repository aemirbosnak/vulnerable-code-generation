//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  int num_of_passengers, num_of_bags;
  srand(time(NULL)); // Seed for random number generation

  // Ask for user input for number of passengers and bags
  printf("Enter the number of passengers: ");
  scanf("%d", &num_of_passengers);
  printf("Enter the number of bags per passenger: ");
  scanf("%d", &num_of_bags);

  // Calculate total number of bags
  int total_bags = num_of_passengers * num_of_bags;

  // Declare arrays for destinations and bags per destination
  char destinations[total_bags][4];
  int bags_per_destination[total_bags][2];

  // Fill arrays with random data
  for (int i = 0; i < total_bags; i++) {
    int dest_num = rand() % 3 + 1;
    if (dest_num == 1) {
      destinations[i][0] = 'J';
      destinations[i][1] = 'F';
      destinations[i][2] = 'K';
    } else if (dest_num == 2) {
      destinations[i][0] = 'L';
      destinations[i][1] = 'A';
      destinations[i][2] = 'X';
    } else if (dest_num == 3) {
      destinations[i][0] = 'S';
      destinations[i][1] = 'F';
      destinations[i][2] = 'O';
    }
    destinations[i][3] = '\0'; // Null-terminate string

    bags_per_destination[i][0] = dest_num; // Destination number
    bags_per_destination[i][1] = rand() % num_of_bags + 1; // Number of bags for that destination
  }

  // Sort bags_per_destination array based on destination number using bubble sort
  for (int i = 0; i < total_bags - 1; i++) {
    for (int j = 0; j < total_bags - i - 1; j++) {
      if (bags_per_destination[j][0] > bags_per_destination[j+1][0]) {
        int temp_dest = bags_per_destination[j][0];
        int temp_bags = bags_per_destination[j][1];

        bags_per_destination[j][0] = bags_per_destination[j+1][0];
        bags_per_destination[j][1] = bags_per_destination[j+1][1];

        bags_per_destination[j+1][0] = temp_dest;
        bags_per_destination[j+1][1] = temp_bags;
      }
    }
  }

  // Initialize variables for tracking bag processing times and conveyor belt usage
  int processing_times[num_of_passengers][num_of_bags];
  int conveyor_usage[num_of_passengers][num_of_bags];
  for (int i = 0; i < num_of_passengers; i++) {
    for (int j = 0; j < num_of_bags; j++) {
      processing_times[i][j] = 0;
      conveyor_usage[i][j] = 0;
    }
  }

  // Begin bag handling simulation
  printf("\nStarting baggage handling simulation...\n");

  for (int i = 0; i < total_bags; i++) {
    char dest[4];
    int num_bags;
    dest[0] = destinations[i][0];
    dest[1] = destinations[i][1];
    dest[2] = destinations[i][2];
    dest[3] = '\0';
    num_bags = bags_per_destination[i][1];

    printf("\nProcessing bags for destination %s (%d bags)\n", dest, num_bags);

    for (int j = 0; j < num_of_passengers; j++) {
      int conveyor_used = 0;

      for (int k = 0; k < num_of_bags; k++) {
        if (conveyor_used == 0 && processing_times[j][k] == 0) {
          conveyor_usage[j][k] = 1;
          conveyor_used = 1;
        }

        if (processing_times[j][k] > 0) {
          processing_times[j][k]--;
        }

        if (conveyor_usage[j][k] == 1) {
          printf("Bag %d for passenger %d has been added to the conveyor belt.\n", k+1, j+1);
        }

        if (strcmp(dest, "JFK") == 0 && conveyor_usage[j][k] == 1) {
          processing_times[j][k] = 3;
          conveyor_usage[j][k] = 0;
        } else if (strcmp(dest, "LAX") == 0 && conveyor_usage[j][k] == 1) {
          processing_times[j][k] = 5;
          conveyor_usage[j][k] = 0;
        } else if (strcmp(dest, "SFO") == 0 && conveyor_usage[j][k] == 1) {
          processing_times[j][k] = 4;
          conveyor_usage[j][k] = 0;
        }
      }
    }
  }

  // Print final statistics
  printf("\nSimulation complete. Final statistics:\n");
  for (int i = 0; i < num_of_passengers; i++) {
    printf("Passenger %d - ", i+1);
    for (int j = 0; j < num_of_bags; j++) {
      printf("Bag %d (%d seconds) ", j+1, processing_times[i][j]);
    }
    printf("\n");
  }

  return 0;
}