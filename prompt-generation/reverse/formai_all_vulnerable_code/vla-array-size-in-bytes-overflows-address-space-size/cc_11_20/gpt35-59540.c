//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int i, j, n;
  float location_x, location_y;
  char direction;

  printf("Welcome to GPS Navigation Simulation! \n");

  printf("Enter the number of coordinates: ");
  scanf("%d", &n);

  srand(time(0));
  float coordinates[n][2];

  for(i=0; i<n; i++) {
    // Generate random coordinates for the user to travel to
    coordinates[i][0] = (float)(rand() % 1000)/10.0;
    coordinates[i][1] = (float)(rand() % 1000)/10.0;
  }

  printf("\n Your journey begins! \n");

  for(i=0; i<n; i++) {

    location_x = coordinates[i][0];
    location_y = coordinates[i][1];

    if(location_x >= 0 && location_x <= 24 && location_y >= 0 && location_y <= 24) {
      // User in within the defined boundary

      if(location_x > 12 && location_y > 12) {
        direction = 'NorthEast';
      } else if(location_x > 12 && location_y < 12) {
        direction = 'SouthEast';
      } else if(location_x < 12 && location_y > 12) {
        direction = 'NorthWest';
      } else {
        direction = 'SouthWest';
      }

      printf("Current Location: (%.1f, %.1f)\n", location_x, location_y);
      printf("Heading %s \n\n", direction);

    } else {
      // User is outside the defined boundary
      printf("You tried to leave the boundary. Mission failed.");
      return 0;
    }
  }

  printf("Congratulations! You have reached the final destination.");

  return 0;
}