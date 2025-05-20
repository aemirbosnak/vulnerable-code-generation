//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_TEXT_LENGTH 1024

typedef struct {
  char name[32];
  char text[MAX_TEXT_LENGTH];
  int score;
} player_t;

void print_usage() {
  printf("Usage: ./text_summarizer <num_players> <text_file>\n");
  printf("Example: ./text_summarizer 2 input.txt\n");
}

int main(int argc, char **argv) {
  if (argc != 3) {
    print_usage();
    return 1;
  }

  int num_players = atoi(argv[1]);
  if (num_players < 2 || num_players > MAX_PLAYERS) {
    printf("Invalid number of players. Must be between 2 and %d.\n", MAX_PLAYERS);
    return 1;
  }

  FILE *fp = fopen(argv[2], "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  char text[MAX_TEXT_LENGTH];
  if (fread(text, 1, MAX_TEXT_LENGTH, fp) < 0) {
    perror("Error reading file");
    fclose(fp);
    return 1;
  }
  fclose(fp);

  player_t players[MAX_PLAYERS];
  for (int i = 0; i < num_players; i++) {
    printf("Player %d, enter your name: ", i + 1);
    scanf("%s", players[i].name);
    printf("Player %s, enter your summary of the text: ", players[i].name);
    scanf("%[^\n]s", players[i].text);
    players[i].score = 0;
  }

  // TODO: Implement the scoring algorithm

  // Print the results
  printf("\nResults:\n");
  for (int i = 0; i < num_players; i++) {
    printf("Player %s: %s (score: %d)\n", players[i].name, players[i].text, players[i].score);
  }

  return 0;
}