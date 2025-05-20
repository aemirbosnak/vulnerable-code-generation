//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Planet structure
typedef struct planet {
  char *name;
  int size;
  int population;
  struct planet *next;
} planet;

// Create a new planet
planet *create_planet(char *name, int size, int population) {
  planet *new_planet = malloc(sizeof(planet));
  new_planet->name = name;
  new_planet->size = size;
  new_planet->population = population;
  new_planet->next = NULL;
  return new_planet;
}

// Add a planet to the end of the linked list
void add_planet(planet **head, planet *new_planet) {
  if (*head == NULL) {
    *head = new_planet;
  } else {
    planet *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_planet;
  }
}

// Generate a random planet
planet *generate_planet() {
  // Generate a random name
  char *name = malloc(10);
  for (int i = 0; i < 9; i++) {
    name[i] = (rand() % 26) + 97;
  }
  name[9] = '\0';

  // Generate a random size
  int size = rand() % 100000;

  // Generate a random population
  int population = rand() % 1000000;

  // Create a new planet
  planet *new_planet = create_planet(name, size, population);
  return new_planet;
}

// Print the linked list of planets
void print_planets(planet *head) {
  planet *current = head;
  while (current != NULL) {
    printf("%s (%d, %d)\n", current->name, current->size, current->population);
    current = current->next;
  }
}

// Free the linked list of planets
void free_planets(planet *head) {
  planet *current = head;
  while (current != NULL) {
    planet *next = current->next;
    free(current->name);
    free(current);
    current = next;
  }
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a linked list of planets
  planet *head = NULL;

  // Generate 10 random planets
  for (int i = 0; i < 10; i++) {
    planet *new_planet = generate_planet();
    add_planet(&head, new_planet);
  }

  // Print the linked list of planets
  print_planets(head);

  // Free the linked list of planets
  free_planets(head);

  return 0;
}