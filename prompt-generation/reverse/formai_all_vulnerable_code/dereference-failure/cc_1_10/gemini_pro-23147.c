//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// structure to represent a troubadour
typedef struct troubadour {
  char* name;
  int age;
  char* instrument;
  struct troubadour* master;
} Troubadour;

// create a new troubadour
Troubadour* create_troubadour(char* name, int age, char* instrument, Troubadour* master) {
  Troubadour* troubadour = (Troubadour*) malloc(sizeof(Troubadour));
  troubadour->name = name;
  troubadour->age = age;
  troubadour->instrument = instrument;
  troubadour->master = master;
  return troubadour;
}

// print a troubadour's information
void print_troubadour(Troubadour* troubadour) {
  printf("Name: %s\n", troubadour->name);
  printf("Age: %d\n", troubadour->age);
  printf("Instrument: %s\n", troubadour->instrument);
  if (troubadour->master != NULL) {
    printf("Master: %s\n", troubadour->master->name);
  } else {
    printf("Master: None\n");
  }
  printf("\n");
}

// find the master of a troubadour
Troubadour* find_master(Troubadour* troubadour) {
  if (troubadour->master == NULL) {
    return troubadour;
  } else {
    return find_master(troubadour->master);
  }
}

// main function
int main() {
  // create a master troubadour
  Troubadour* master = create_troubadour("Master Troubadour", 50, "Lute", NULL);

  // create a journeyman troubadour
  Troubadour* journeyman = create_troubadour("Journeyman Troubadour", 30, "Fiddle", master);

  // create an apprentice troubadour
  Troubadour* apprentice = create_troubadour("Apprentice Troubadour", 20, "Drum", journeyman);

  // print the troubadours' information
  printf("Master Troubadour:\n");
  print_troubadour(master);

  printf("Journeyman Troubadour:\n");
  print_troubadour(journeyman);

  printf("Apprentice Troubadour:\n");
  print_troubadour(apprentice);

  // find the master of the apprentice troubadour
  Troubadour* master_of_apprentice = find_master(apprentice);

  // print the master of the apprentice troubadour
  printf("Master of Apprentice Troubadour:\n");
  print_troubadour(master_of_apprentice);

  return 0;
}