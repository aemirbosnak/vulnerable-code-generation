//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the knight's fitness data
typedef struct {
  int strength;
  int agility;
  int endurance;
  int health;
} fitness_data_t;

// Create a new knight
fitness_data_t *create_knight() {
  fitness_data_t *knight = malloc(sizeof(fitness_data_t));
  knight->strength = 10;
  knight->agility = 10;
  knight->endurance = 10;
  knight->health = 100;
  return knight;
}

// Train the knight
void train_knight(fitness_data_t *knight) {
  knight->strength += 1;
  knight->agility += 1;
  knight->endurance += 1;
  knight->health += 10;
}

// Rest the knight
void rest_knight(fitness_data_t *knight) {
  knight->health += 20;
}

// Display the knight's fitness data
void display_fitness_data(fitness_data_t *knight) {
  printf("Strength: %d\n", knight->strength);
  printf("Agility: %d\n", knight->agility);
  printf("Endurance: %d\n", knight->endurance);
  printf("Health: %d\n", knight->health);
}

// Main function
int main() {
  // Create a new knight
  fitness_data_t *knight = create_knight();

  // Train the knight for 10 days
  for (int i = 0; i < 10; i++) {
    train_knight(knight);
  }

  // Rest the knight for 5 days
  for (int i = 0; i < 5; i++) {
    rest_knight(knight);
  }

  // Display the knight's fitness data
  display_fitness_data(knight);

  // Free the knight's memory
  free(knight);

  return 0;
}