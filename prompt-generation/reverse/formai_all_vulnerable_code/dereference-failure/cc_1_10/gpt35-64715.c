//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define necessary structures
struct space_ship {
  char name[20];
  int health;
  int fuel;
};

struct planet {
  char name[20];
  int resources;
  int threat_level;
};

// Declare necessary functions
struct planet* generate_planets(int);
void free_planets(struct planet*, int);
void print_planets(struct planet*, int);
int travel(struct space_ship*, struct planet*);

int main() {
  srand(time(NULL)); // Seed random number generator
  int num_planets = 5; // Number of planets in the universe
  struct planet* planets = generate_planets(num_planets); // Generate planets
  print_planets(planets, num_planets); // Print planets to console

  // Initialize player's spaceship
  struct space_ship player_ship = {"The Falcon", 100, 100};

  // Begin space adventure
  printf("Welcome to the galaxy, adventurer. You are the captain of The Falcon, a powerful spaceship capable of interstellar travel.\n");
  printf("Your goal is to explore different planets and collect resources while avoiding dangerous alien threats.\n");
  printf("You have 5 planets to explore. Good luck!\n");

  // Loop through planets until player runs out of fuel or health
  for(int i=0; i<num_planets && player_ship.fuel>0 && player_ship.health>0; i++) {
    int result = travel(&player_ship, &planets[i]); // Travel to planet
    if(result == 1) { // Player gains resources
      printf("You have successfully collected resources from %s! Your ship now has %d fuel and %d health.\n\n", planets[i].name, player_ship.fuel, player_ship.health);
    } else { // Player encounters alien threat
      printf("Uh-oh! You have encountered a hostile alien species on %s! Your ship now has %d fuel and %d health.\n\n", planets[i].name, player_ship.fuel, player_ship.health);
    }
  }

  // End game
  if(player_ship.fuel <= 0) {
    printf("Your ship has run out of fuel and you are now stranded in space. Game over!\n");
  } else if(player_ship.health <= 0) {
    printf("Your ship has sustained too much damage and can no longer continue. Game over!\n");
  } else {
    printf("Congratulations! You have successfully explored all 5 planets and collected valuable resources. You win!\n");
  }

  free_planets(planets, num_planets); // Free memory allocated for planets array
  return 0;
}

struct planet* generate_planets(int num_planets) {
  struct planet* planets = malloc(sizeof(struct planet) * num_planets); // Allocate memory for planets array
  char planet_names[5][20] = {"Zorgon", "Gexon", "Lunara", "Naboo", "Ryder"};
  for(int i=0; i<num_planets; i++) {
    // Set planet name
    strcpy(planets[i].name, planet_names[i]);
    // Generate random values for resources and threat level
    planets[i].resources = rand() % 100 + 1;
    planets[i].threat_level = rand() % 3 + 1;
  }
  return planets;
}

void free_planets(struct planet* planets, int num_planets) {
  for(int i=0; i<num_planets; i++) {
    free(&planets[i]); // Free memory for each planet in array
  }
  free(planets); // Free memory for planets array
}

void print_planets(struct planet* planets, int num_planets) {
  printf("Here are the planets you will be exploring:\n");
  for(int i=0; i<num_planets; i++) {
    printf("%s - Resources: %d, Threat Level: %d\n", planets[i].name, planets[i].resources, planets[i].threat_level);
  }
  printf("\n");
}

int travel(struct space_ship* player_ship, struct planet* planet) {
  printf("You are traveling to %s...\n", planet->name);
  int travel_time = rand() % 5 + 1; // Generate random travel time
  player_ship->fuel -= travel_time; // Deduct fuel from player's ship
  if(planet->threat_level == 3) { // Player encounters alien threat
    player_ship->health -= rand() % 30 + 1; // Deduct health from player's ship
    return 0;
  } else { // Player gains resources
    player_ship->health += rand() % 20 + 1; // Increase health of player's ship
    return 1;
  }
}