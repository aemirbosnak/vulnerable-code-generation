//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CHECKIN_COUNTERS 5
#define NUM_SECURITY_LINES 3
#define NUM_BAGGAGE_CLAIMS 4

// Baggage types
enum BaggageType {SMALL, MEDIUM, LARGE};

// Baggage status
enum BaggageStatus {CHECKED_IN, IN_SECURITY, IN_TRANSIT, AT_BAGGAGE_CLAIM};

// Passenger types
enum PassengerType {BUSINESS, ECONOMY};

// Airport simulation
struct Airport {
  int num_bags;
  int num_checkin_counters;
  int num_security_lines;
  int num_baggage_claims;
  struct Baggage *bags;
  struct CheckinCounter *checkin_counters;
  struct SecurityLine *security_lines;
  struct BaggageClaim *baggage_claims;
};

// Baggage
struct Baggage {
  int id;
  enum BaggageType type;
  enum BaggageStatus status;
  int passenger_id;
};

// Check-in counter
struct CheckinCounter {
  int id;
  int num_bags;
  int num_passengers;
};

// Security line
struct SecurityLine {
  int id;
  int num_bags;
  int num_passengers;
};

// Baggage claim
struct BaggageClaim {
  int id;
  int num_bags;
  int num_passengers;
};

// Initialize the airport
void initialize_airport(struct Airport *airport) {
  airport->num_bags = NUM_BAGS;
  airport->num_checkin_counters = NUM_CHECKIN_COUNTERS;
  airport->num_security_lines = NUM_SECURITY_LINES;
  airport->num_baggage_claims = NUM_BAGGAGE_CLAIMS;

  // Allocate memory for bags
  airport->bags = malloc(sizeof(struct Baggage) * airport->num_bags);

  // Initialize bags
  for (int i = 0; i < airport->num_bags; i++) {
    airport->bags[i].id = i;
    airport->bags[i].type = rand() % 3;
    airport->bags[i].status = CHECKED_IN;
    airport->bags[i].passenger_id = rand() % 100;
  }

  // Allocate memory for check-in counters
  airport->checkin_counters = malloc(sizeof(struct CheckinCounter) * airport->num_checkin_counters);

  // Initialize check-in counters
  for (int i = 0; i < airport->num_checkin_counters; i++) {
    airport->checkin_counters[i].id = i;
    airport->checkin_counters[i].num_bags = 0;
    airport->checkin_counters[i].num_passengers = 0;
  }

  // Allocate memory for security lines
  airport->security_lines = malloc(sizeof(struct SecurityLine) * airport->num_security_lines);

  // Initialize security lines
  for (int i = 0; i < airport->num_security_lines; i++) {
    airport->security_lines[i].id = i;
    airport->security_lines[i].num_bags = 0;
    airport->security_lines[i].num_passengers = 0;
  }

  // Allocate memory for baggage claims
  airport->baggage_claims = malloc(sizeof(struct BaggageClaim) * airport->num_baggage_claims);

  // Initialize baggage claims
  for (int i = 0; i < airport->num_baggage_claims; i++) {
    airport->baggage_claims[i].id = i;
    airport->baggage_claims[i].num_bags = 0;
    airport->baggage_claims[i].num_passengers = 0;
  }
}

// Simulate the airport
void simulate_airport(struct Airport *airport) {
  // Check in passengers
  for (int i = 0; i < airport->num_bags; i++) {
    struct Baggage *baggage = &airport->bags[i];

    // Find a check-in counter
    int checkin_counter_id = rand() % airport->num_checkin_counters;
    struct CheckinCounter *checkin_counter = &airport->checkin_counters[checkin_counter_id];

    // Check in the baggage
    checkin_counter->num_bags++;
    checkin_counter->num_passengers++;
    baggage->status = IN_SECURITY;
  }

  // Go through security
  for (int i = 0; i < airport->num_bags; i++) {
    struct Baggage *baggage = &airport->bags[i];

    // Find a security line
    int security_line_id = rand() % airport->num_security_lines;
    struct SecurityLine *security_line = &airport->security_lines[security_line_id];

    // Go through security
    security_line->num_bags++;
    security_line->num_passengers++;
    baggage->status = IN_TRANSIT;
  }

  // Claim baggage
  for (int i = 0; i < airport->num_bags; i++) {
    struct Baggage *baggage = &airport->bags[i];

    // Find a baggage claim
    int baggage_claim_id = rand() % airport->num_baggage_claims;
    struct BaggageClaim *baggage_claim = &airport->baggage_claims[baggage_claim_id];

    // Claim the baggage
    baggage_claim->num_bags++;
    baggage_claim->num_passengers++;
    baggage->status = AT_BAGGAGE_CLAIM;
  }
}

// Print the airport statistics
void print_airport_statistics(struct Airport *airport) {
  printf("Airport Statistics\n");
  printf("------------------\n");
  printf("Number of bags: %d\n", airport->num_bags);
  printf("Number of check-in counters: %d\n", airport->num_checkin_counters);
  printf("Number of security lines: %d\n", airport->num_security_lines);
  printf("Number of baggage claims: %d\n", airport->num_baggage_claims);

  printf("\nCheck-in Counter Statistics\n");
  printf("--------------------------\n");
  for (int i = 0; i < airport->num_checkin_counters; i++) {
    struct CheckinCounter *checkin_counter = &airport->checkin_counters[i];
    printf("Check-in counter %d: %d bags, %d passengers\n", checkin_counter->id, checkin_counter->num_bags, checkin_counter->num_passengers);
  }

  printf("\nSecurity Line Statistics\n");
  printf("------------------------\n");
  for (int i = 0; i < airport->num_security_lines; i++) {
    struct SecurityLine *security_line = &airport->security_lines[i];
    printf("Security line %d: %d bags, %d passengers\n", security_line->id, security_line->num_bags, security_line->num_passengers);
  }

  printf("\nBaggage Claim Statistics\n");
  printf("------------------------\n");
  for (int i = 0; i < airport->num_baggage_claims; i++) {
    struct BaggageClaim *baggage_claim = &airport->baggage_claims[i];
    printf("Baggage claim %d: %d bags, %d passengers\n", baggage_claim->id, baggage_claim->num_bags, baggage_claim->num_passengers);
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the airport
  struct Airport airport;
  initialize_airport(&airport);

  // Simulate the airport
  simulate_airport(&airport);

  // Print the airport statistics
  print_airport_statistics(&airport);

  return 0;
}