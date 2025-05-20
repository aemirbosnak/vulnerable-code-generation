//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 10
#define MAX_BAGS_PER_FLIGHT 20

void simulate_baggage_handling() {
   int baggage[MAX_BAGGAGE];
   int flights[MAX_FLIGHTS][MAX_BAGS_PER_FLIGHT];
   int num_bags = rand() % MAX_BAGGAGE;
   int num_flights = rand() % MAX_FLIGHTS;
   int num_bags_per_flight = rand() % MAX_BAGS_PER_FLIGHT + 1;
   int i, j;

   printf("Initializing baggage...\n");

   for (i = 0; i < num_bags; i++) {
      baggage[i] = rand() % 100 + 1;
   }

   printf("Successfully initialized %d bags.\n", num_bags);
   printf("Initializing flights...\n");

   for (i = 0; i < num_flights; i++) {
      printf("Flight %d: ", i+1);
      for (j = 0; j < num_bags_per_flight; j++) {
         int bag_index = rand() % num_bags;
         flights[i][j] = baggage[bag_index];
      }
      printf("Successfully initialized %d bags.\n", num_bags_per_flight);
   }

   printf("Successfully initialized %d flights.\n", num_flights);
   printf("Processing flights...\n");

   for (i = 0; i < num_flights; i++) {
      printf("Processing flight %d...\n", i+1);
      for (j = 0; j < num_bags_per_flight; j++) {
         int bag_weight = flights[i][j];
         printf("Checking bag %d (weight: %d)...\n", j+1, bag_weight);
         if (bag_weight > 50) {
            printf("Bag rejected! Weight limit exceeded.\n");
         }
         else {
            printf("Bag accepted. Proceeding to next stage.\n");
            // add code to move bag to next stage here
         }
      }
   }

   printf("Simulation complete.\n");
}

int main() {
   srand(time(NULL));
   simulate_baggage_handling();
   return 0;
}