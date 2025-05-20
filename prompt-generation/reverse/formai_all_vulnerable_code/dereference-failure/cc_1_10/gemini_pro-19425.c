//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 32
#define MAX_MESSAGE_LENGTH 128

typedef struct {
  char name[MAX_NAME_LENGTH];
  int score;
} player_t;

typedef struct {
  player_t players[MAX_PLAYERS];
  int num_players;
  sem_t mutex;
} game_t;

void *player_thread(void *arg) {
  game_t *game = (game_t *)arg;

  // Get a unique player ID
  int player_id;
  sem_wait(&game->mutex);
  player_id = game->num_players++;
  sem_post(&game->mutex);

  // Generate a random name
  char name[MAX_NAME_LENGTH];
  sprintf(name, "Player %d", player_id);

  // Initialize the player's score
  game->players[player_id].score = 0;

  // Send a welcome message to the player
  sem_wait(&game->mutex);
  printf("Welcome to the game, %s!\n", name);
  sem_post(&game->mutex);

  // Game loop
  while (1) {
    // Get a message from the player
    char message[MAX_MESSAGE_LENGTH];
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Parse the message
    char *command = strtok(message, " ");
    if (strcmp(command, "quit") == 0) {
      // Quit the game
      sem_wait(&game->mutex);
      game->num_players--;
      sem_post(&game->mutex);
      break;
    } else if (strcmp(command, "score") == 0) {
      // Get the player's score
      sem_wait(&game->mutex);
      printf("Your score is %d\n", game->players[player_id].score);
      sem_post(&game->mutex);
    } else if (strcmp(command, "attack") == 0) {
      // Attack another player
      char *target_name = strtok(NULL, " ");
      int target_id = -1;
      for (int i = 0; i < game->num_players; i++) {
        if (strcmp(game->players[i].name, target_name) == 0) {
          target_id = i;
          break;
        }
      }
      if (target_id == -1) {
        // Target player not found
        sem_wait(&game->mutex);
        printf("Player %s not found\n", target_name);
        sem_post(&game->mutex);
      } else {
        // Attack the target player
        sem_wait(&game->mutex);
        game->players[target_id].score--;
        printf("You attacked %s and their score is now %d\n", target_name, game->players[target_id].score);
        sem_post(&game->mutex);
      }
    }
  }

  return NULL;
}

int main() {
  // Initialize the game
  game_t game;
  game.num_players = 0;
  sem_init(&game.mutex, 0, 1);

  // Create the player threads
  pthread_t player_threads[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    pthread_create(&player_threads[i], NULL, player_thread, &game);
  }

  // Join the player threads
  for (int i = 0; i < MAX_PLAYERS; i++) {
    pthread_join(player_threads[i], NULL);
  }

  // Destroy the game
  sem_destroy(&game.mutex);

  return 0;
}