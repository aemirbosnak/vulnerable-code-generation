//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a knight
typedef struct {
  char name[32];
  int strength;
  int agility;
  int intelligence;
  int charisma;
} Knight;

// Define the data structure for a list of knights
typedef struct {
  Knight *knights;
  int num_knights;
} KnightList;

// Create a new knight
Knight *new_knight(char *name, int strength, int agility, int intelligence, int charisma) {
  Knight *knight = malloc(sizeof(Knight));
  strcpy(knight->name, name);
  knight->strength = strength;
  knight->agility = agility;
  knight->intelligence = intelligence;
  knight->charisma = charisma;
  return knight;
}

// Add a knight to a list of knights
void add_knight(KnightList *list, Knight *knight) {
  list->knights = realloc(list->knights, (list->num_knights + 1) * sizeof(Knight));
  list->knights[list->num_knights++] = *knight;
}

// Print a list of knights
void print_knights(KnightList *list) {
  for (int i = 0; i < list->num_knights; i++) {
    printf("%s\n", list->knights[i].name);
  }
}

// Sort a list of knights by strength
void sort_knights_by_strength(KnightList *list) {
  for (int i = 0; i < list->num_knights - 1; i++) {
    for (int j = i + 1; j < list->num_knights; j++) {
      if (list->knights[i].strength < list->knights[j].strength) {
        Knight temp = list->knights[i];
        list->knights[i] = list->knights[j];
        list->knights[j] = temp;
      }
    }
  }
}

// Find the strongest knight in a list of knights
Knight *find_strongest_knight(KnightList *list) {
  Knight *strongest_knight = NULL;
  for (int i = 0; i < list->num_knights; i++) {
    if (strongest_knight == NULL || list->knights[i].strength > strongest_knight->strength) {
      strongest_knight = &list->knights[i];
    }
  }
  return strongest_knight;
}

// Main function
int main() {
  // Create a list of knights
  KnightList *list = malloc(sizeof(KnightList));
  list->knights = NULL;
  list->num_knights = 0;

  // Add some knights to the list
  add_knight(list, new_knight("Sir Lancelot", 9, 8, 7, 8));
  add_knight(list, new_knight("Sir Galahad", 8, 9, 6, 7));
  add_knight(list, new_knight("Sir Tristan", 7, 8, 9, 6));
  add_knight(list, new_knight("Sir Gawain", 6, 7, 8, 9));
  add_knight(list, new_knight("Sir Percival", 5, 6, 7, 8));

  // Print the list of knights
  printf("The knights of the realm:\n");
  print_knights(list);

  // Sort the list of knights by strength
  sort_knights_by_strength(list);

  // Find the strongest knight in the list
  Knight *strongest_knight = find_strongest_knight(list);

  // Print the strongest knight
  printf("The strongest knight is:\n");
  printf("%s\n", strongest_knight->name);

  // Free the memory allocated for the list of knights
  free(list->knights);
  free(list);

  return 0;
}