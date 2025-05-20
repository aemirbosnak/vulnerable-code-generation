//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  // Initialize the game
  srand(time(0));
  char* names[] = {"Adam", "Eve", "Everett", "Everest", "Evelyn"};
  char* spaceships[] = {"Milky Way", "Andromeda", "Sagittarius", "Orion", "Cassiopeia"};
  char* aliens[] = {"Reptilian", "Grays", "Zeta Reticuli", "Orion", "Mothman"};
  int n_players = 4;
  int n_spaceships = sizeof(spaceships) / sizeof(spaceships[0]);
  int n_aliens = sizeof(aliens) / sizeof(aliens[0]);

  // Create a team of spaceships and aliens
  int* spaceship_ids = (int*)malloc(n_players * sizeof(int));
  int* alien_ids = (int*)malloc(n_players * sizeof(int));
  for (int i = 0; i < n_players; i++) {
    spaceship_ids[i] = rand() % n_spaceships;
    alien_ids[i] = rand() % n_aliens;
  }

  // Print the team
  printf("Team of spaceships:\n");
  for (int i = 0; i < n_players; i++) {
    printf("%s %d\n", names[i], spaceship_ids[i]);
  }
  printf("\n");
  printf("Team of aliens:\n");
  for (int i = 0; i < n_players; i++) {
    printf("%s %d\n", names[i], alien_ids[i]);
  }
  printf("\n");

  // Start the game
  for (int i = 0; i < n_players; i++) {
    printf("Spaceship %s (%d) has entered the %s galaxy.\n", names[i], spaceship_ids[i], spaceships[i]);
    printf("Alien %s (%d) has entered the %s galaxy.\n", names[i], alien_ids[i], aliens[i]);
  }
  printf("\n");

  // Play the game
  for (int i = 0; i < n_players; i++) {
    printf("Spaceship %s (%d) has encountered an alien %s (%d) in the %s galaxy.\n", names[i], spaceship_ids[i], aliens[i], alien_ids[i], spaceships[i]);
    printf("Spaceship %s (%d) has fired its phasers.\n", names[i], spaceship_ids[i]);
    printf("Alien %s (%d) has been destroyed.\n", names[i], alien_ids[i]);
    printf("\n");
  }
  printf("Congratulations, the spaceships have won the game!\n");

  return 0;
}