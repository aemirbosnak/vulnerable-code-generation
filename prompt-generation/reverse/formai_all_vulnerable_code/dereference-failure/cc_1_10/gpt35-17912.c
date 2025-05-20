//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_SCORES 10

typedef struct {
  char name[MAX_NAME_LENGTH];
  int scores[MAX_SCORES];
  int num_scores;
} Player;

void savePlayers(Player players[], int num_players, char* filename) {
  FILE* file = fopen(filename, "wb");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }
  
  fwrite(&num_players, sizeof(int), 1, file);
  
  for (int i = 0; i < num_players; ++i) {
    fwrite(&players[i], sizeof(Player), 1, file);
  }
  
  fclose(file);
}

void loadPlayers(Player players[], int* num_players, char* filename) {
  FILE* file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }
  
  fread(num_players, sizeof(int), 1, file);
  
  for (int i = 0; i < *num_players; ++i) {
    fread(&players[i], sizeof(Player), 1, file);
  }
  
  fclose(file);
}

int main() {
  Player players[3] = {
    { .name = "John", .scores = {10, 20, 30}, .num_scores = 3 },
    { .name = "Mike", .scores = {15, 25, 35}, .num_scores = 3 },
    { .name = "Jane", .scores = {20, 30, 40}, .num_scores = 3 }
  };
  
  savePlayers(players, 3, "players.bin");
  
  Player loaded_players[3];
  int num_players;
  loadPlayers(loaded_players, &num_players, "players.bin");
  
  printf("Loaded %d players:\n", num_players);
  for (int i = 0; i < num_players; ++i) {
    printf("%s scores:\n", loaded_players[i].name);
    for (int j = 0; j < loaded_players[i].num_scores; ++j) {
      printf("%d ", loaded_players[i].scores[j]);
    }
    printf("\n");
  }
  
  return 0;
}