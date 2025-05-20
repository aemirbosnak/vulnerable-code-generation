//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_CSV_LINE_LENGTH 100

// Player data structure
typedef struct Player {
  char name[MAX_NAME_LENGTH];
  int score;
} Player;

// Function to read a CSV line and store the data in a player struct
int read_csv_line(const char *csv_line, Player *player) {
  char *name, *score;
  char *comma = strchr(csv_line, ',');
  if (comma == NULL) {
    return -1;
  }

  // Extract the name and score from the CSV line
  name = malloc((comma - csv_line) + 1);
  if (name == NULL) {
    return -1;
  }
  strncpy(name, csv_line, comma - csv_line);
  name[(comma - csv_line)] = '\0';

  score = malloc(strlen(csv_line) - (comma - csv_line) + 1);
  if (score == NULL) {
    return -1;
  }
  strcpy(score, comma + 1);

  // Convert the score to an integer
  player->score = atoi(score);

  // Copy the name and score into the player struct
  strcpy(player->name, name);

  // Free the allocated memory
  free(name);
  free(score);

  return 0;
}

// Function to compare two players based on their scores
int compare_players(const void *a, const void *b) {
  Player *player1 = (Player *)a;
  Player *player2 = (Player *)b;

  return player2->score - player1->score;
}

// Main function
int main() {
  char csv_line[MAX_CSV_LINE_LENGTH];
  Player players[MAX_PLAYERS];
  int num_players = 0;

  // Read the CSV file line by line
  while (fgets(csv_line, sizeof(csv_line), stdin) != NULL) {
    // Read the data from the CSV line and store it in a player struct
    if (read_csv_line(csv_line, &players[num_players]) == -1) {
      fprintf(stderr, "Error reading CSV line: %s\n", csv_line);
      return -1;
    }

    // Increment the number of players
    num_players++;
  }

  // Sort the players based on their scores
  qsort(players, num_players, sizeof(Player), compare_players);

  // Print the names and scores of the players
  for (int i = 0; i < num_players; i++) {
    printf("%s: %d\n", players[i].name, players[i].score);
  }

  return 0;
}