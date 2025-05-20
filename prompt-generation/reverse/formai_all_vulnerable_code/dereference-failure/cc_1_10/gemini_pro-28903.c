//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

// Shared memory segment
typedef struct {
  // Game state
  int player1_pos;
  int player2_pos;
  int ball_pos;
  int ball_vel;
  int winner;
} game_state;

// Semaphores for synchronization
sem_t sem_player1;
sem_t sem_player2;

// Thread functions
void* player1_thread(void* arg) {
  while (1) {
    // Wait for turn
    sem_wait(&sem_player1);

    // Get shared memory
    game_state* state = (game_state*)arg;

    // Get user input
    printf("Player 1: Enter your move: ");
    char input[10];
    fgets(input, sizeof(input), stdin);

    // Update player position
    if (strcmp(input, "up") == 0) {
      state->player1_pos++;
    } else if (strcmp(input, "down") == 0) {
      state->player1_pos--;
    }

    // Check for collision
    if (state->player1_pos == state->ball_pos) {
      state->ball_vel = -state->ball_vel;
    }

    // Signal other player
    sem_post(&sem_player2);
  }
}

void* player2_thread(void* arg) {
  while (1) {
    // Wait for turn
    sem_wait(&sem_player2);

    // Get shared memory
    game_state* state = (game_state*)arg;

    // Get user input
    printf("Player 2: Enter your move: ");
    char input[10];
    fgets(input, sizeof(input), stdin);

    // Update player position
    if (strcmp(input, "up") == 0) {
      state->player2_pos++;
    } else if (strcmp(input, "down") == 0) {
      state->player2_pos--;
    }

    // Check for collision
    if (state->player2_pos == state->ball_pos) {
      state->ball_vel = -state->ball_vel;
    }

    // Signal other player
    sem_post(&sem_player1);
  }
}

void* ball_thread(void* arg) {
  while (1) {
    // Get shared memory
    game_state* state = (game_state*)arg;

    // Update ball position
    state->ball_pos += state->ball_vel;

    // Check for boundaries
    if (state->ball_pos == 0 || state->ball_pos == 100) {
      state->ball_vel = -state->ball_vel;
    }

    // Check for winner
    if (state->ball_pos == state->player1_pos || state->ball_pos == state->player2_pos) {
      state->winner = 1;
    }
  }
}

int main() {
  // Create shared memory segment
  game_state* state = (game_state*)malloc(sizeof(game_state));

  // Initialize game state
  state->player1_pos = 50;
  state->player2_pos = 50;
  state->ball_pos = 50;
  state->ball_vel = 1;
  state->winner = 0;

  // Initialize semaphores
  sem_init(&sem_player1, 0, 1);
  sem_init(&sem_player2, 0, 0);

  // Create threads
  pthread_t player1_tid;
  pthread_t player2_tid;
  pthread_t ball_tid;
  pthread_create(&player1_tid, NULL, player1_thread, state);
  pthread_create(&player2_tid, NULL, player2_thread, state);
  pthread_create(&ball_tid, NULL, ball_thread, state);

  // Wait for threads to finish
  pthread_join(player1_tid, NULL);
  pthread_join(player2_tid, NULL);
  pthread_join(ball_tid, NULL);

  // Destroy semaphores
  sem_destroy(&sem_player1);
  sem_destroy(&sem_player2);

  // Free shared memory segment
  free(state);

  return 0;
}