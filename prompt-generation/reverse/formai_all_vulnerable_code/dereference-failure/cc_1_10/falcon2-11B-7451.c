//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Set up the haunted house
  char* house = malloc(sizeof(char) * 100);
  strcpy(house, "This haunted house is located in the middle of nowhere.");

  // Print the haunted house description
  printf("%s\n", house);

  // Add some creepy sounds
  char* sound1 = malloc(sizeof(char) * 100);
  strcpy(sound1, "A sudden gust of wind blows through the trees.");
  printf("%s\n", sound1);
  free(sound1);

  char* sound2 = malloc(sizeof(char) * 100);
  strcpy(sound2, "The sound of creaking floorboards echoes through the halls.");
  printf("%s\n", sound2);
  free(sound2);

  char* sound3 = malloc(sizeof(char) * 100);
  strcpy(sound3, "A ghostly whisper can be heard in the distance.");
  printf("%s\n", sound3);
  free(sound3);

  // Add some spooky decorations
  char* decoration1 = malloc(sizeof(char) * 100);
  strcpy(decoration1, "A cobweb stretches across the doorway.");
  printf("%s\n", decoration1);
  free(decoration1);

  char* decoration2 = malloc(sizeof(char) * 100);
  strcpy(decoration2, "An old, dusty mirror hangs on the wall.");
  printf("%s\n", decoration2);
  free(decoration2);

  char* decoration3 = malloc(sizeof(char) * 100);
  strcpy(decoration3, "An eerie chandelier hangs from the ceiling.");
  printf("%s\n", decoration3);
  free(decoration3);

  // Add some creepy characters
  char* character1 = malloc(sizeof(char) * 100);
  strcpy(character1, "A ghostly apparition floats through the halls.");
  printf("%s\n", character1);
  free(character1);

  char* character2 = malloc(sizeof(char) * 100);
  strcpy(character2, "A demonic figure lurks in the shadows.");
  printf("%s\n", character2);
  free(character2);

  char* character3 = malloc(sizeof(char) * 100);
  strcpy(character3, "A bloodthirsty vampire prowls the halls.");
  printf("%s\n", character3);
  free(character3);

  // End of the haunted house
  free(house);

  return 0;
}