//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_flights; // Number of flights
  printf("Enter number of flights: ");
  scanf("%d", &num_flights);
  
  int cargo_capacity[num_flights]; // Array to hold cargo capacity of each flight
  srand(time(NULL)); // Set random seed based on current time
  
  for (int i = 0; i < num_flights; i++) {
    // Generate a random cargo capacity between 100 and 1000
    cargo_capacity[i] = rand() % 901 + 100;
    printf("Flight %d cargo capacity: %d\n", i+1, cargo_capacity[i]);
  }
  
  int total_cargo = 0; // Total cargo that needs to be processed
  for (int i = 0; i < num_flights; i++) {
    total_cargo += cargo_capacity[i];
  }
  printf("Total cargo to be processed: %d\n", total_cargo);
  
  int conveyor_speed; // Speed of the conveyor belt in meters per minute
  printf("Enter conveyor speed (in meters per minute): ");
  scanf("%d", &conveyor_speed);
  
  float time_to_process = (float)total_cargo / conveyor_speed; // Time required to process all cargo
  printf("Time required to process all cargo: %.2f minutes\n", time_to_process);
  
  int num_workers; // Number of workers available to process the cargo
  printf("Enter number of workers: ");
  scanf("%d", &num_workers);
  
  int cargo_per_worker = total_cargo / num_workers; // Amount of cargo each worker needs to process
  printf("Each worker needs to process %d cargo units\n", cargo_per_worker);
  
  int num_cargo_processed = 0; // Number of cargo units processed so far
  int num_workers_needed = 0; // Number of workers needed to process all cargo
  
  // Calculate number of workers needed, accounting for excess cargo
  while (num_cargo_processed < total_cargo) {
    num_workers_needed++;
    num_cargo_processed += cargo_per_worker;
  }
  
  printf("%d workers are needed to process all cargo\n", num_workers_needed);
  
  return 0;
}