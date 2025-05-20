//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_HAUNTED_HOUSES 10

typedef struct HauntedHouse {
  char name[20];
  int yearBuilt;
  float squareFootage;
  int numGhosts;
  struct HauntedHouse* nextHouse;
} HauntedHouse;

HauntedHouse* createHauntedHouse(char* name, int yearBuilt, float squareFootage, int numGhosts) {
  HauntedHouse* house = malloc(sizeof(HauntedHouse));
  strcpy(house->name, name);
  house->yearBuilt = yearBuilt;
  house->squareFootage = squareFootage;
  house->numGhosts = numGhosts;
  house->nextHouse = NULL;
  return house;
}

HauntedHouse* addHauntedHouse(HauntedHouse* head, char* name, int yearBuilt, float squareFootage, int numGhosts) {
  HauntedHouse* house = createHauntedHouse(name, yearBuilt, squareFootage, numGhosts);
  if (head == NULL) {
    head = house;
  } else {
    house->nextHouse = head;
    head = house;
  }
  return head;
}

void displayHauntedHouses(HauntedHouse* head) {
  while (head) {
    printf("%s (%d) - Square Footage: %.2f, Number of Ghosts: %d\n", head->name, head->yearBuilt, head->squareFootage, head->numGhosts);
    head = head->nextHouse;
  }
}

int main() {
  HauntedHouse* hauntedHousesHead = NULL;

  // Create a few haunted houses
  addHauntedHouse(hauntedHousesHead, "The Addams Family House", 1820, 2000.0, 3);
  addHauntedHouse(hauntedHousesHead, "The Winchester Mystery House", 1886, 1400.0, 4);
  addHauntedHouse(hauntedHousesHead, "The Amityville Horror House", 1840, 1200.0, 2);

  // Display the haunted houses
  displayHauntedHouses(hauntedHousesHead);

  return 0;
}