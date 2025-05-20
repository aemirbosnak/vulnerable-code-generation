//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Our two star-crossed lovers
typedef struct {
  char *name;
  int age;
  char *home_planet;
} Person;

// A function to create a new person
Person *create_person(char *name, int age, char *home_planet) {
  Person *person = malloc(sizeof(Person));
  person->name = name;
  person->age = age;
  person->home_planet = home_planet;
  return person;
}

// A function to print a person
void print_person(Person *person) {
  printf("Name: %s\n", person->name);
  printf("Age: %d\n", person->age);
  printf("Home Planet: %s\n", person->home_planet);
}

// Our main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Create our two star-crossed lovers
  Person *romeo = create_person("Romeo", 20, "Verona");
  Person *juliet = create_person("Juliet", 18, "Montague");

  // Print our star-crossed lovers
  printf("Romeo:\n");
  print_person(romeo);
  printf("\nJuliet:\n");
  print_person(juliet);

  // Make them fall in love
  printf("\nRomeo and Juliet have fallen in love!\n");

  // But their families are sworn enemies
  printf("\nBut their families are sworn enemies.\n");

  // So they must keep their love a secret
  printf("\nSo they must keep their love a secret.\n");

  // But they can't stay apart
  printf("\nBut they can't stay apart.\n");

  // So they meet in secret
  printf("\nSo they meet in secret.\n");

  // But they are caught
  printf("\nBut they are caught.\n");

  // And they are forced to choose between their love and their families
  printf("\nAnd they are forced to choose between their love and their families.\n");

  // They choose their love
  printf("\nThey choose their love.\n");

  // And they are banished from their homes
  printf("\nAnd they are banished from their homes.\n");

  // But they find each other again
  printf("\nBut they find each other again.\n");

  // And they live happily ever after
  printf("\nAnd they live happily ever after.\n");

  // Free our star-crossed lovers
  free(romeo);
  free(juliet);

  return 0;
}