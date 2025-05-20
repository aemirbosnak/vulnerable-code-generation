//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000

typedef struct {
  int num_disks;
  int pegs[3];
} state_t;

state_t *create_state(int num_disks) {
  state_t *state = malloc(sizeof(state_t));
  state->num_disks = num_disks;
  state->pegs[0] = 0;
  state->pegs[1] = 0;
  state->pegs[2] = num_disks;
  return state;
}

void free_state(state_t *state) {
  free(state);
}

int is_valid_move(state_t *state, int from, int to) {
  if (from == to) {
    return 0;
  }
  if (state->pegs[to] == 0) {
    return 1;
  }
  if (state->pegs[from] < state->pegs[to]) {
    return 1;
  }
  return 0;
}

void make_move(state_t *state, int from, int to) {
  state->pegs[to]++;
  state->pegs[from]--;
}

void print_state(state_t *state) {
  for (int i = 0; i < 3; i++) {
    printf("%d ", state->pegs[i]);
  }
  printf("\n");
}

int is_solved(state_t *state) {
  return state->pegs[2] == state->num_disks;
}

int main() {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  state_t *state = create_state(num_disks);

  int num_moves = 0;
  while (!is_solved(state)) {
    for (int from = 0; from < 3; from++) {
      for (int to = 0; to < 3; to++) {
        if (is_valid_move(state, from, to)) {
          make_move(state, from, to);
          num_moves++;
          print_state(state);
        }
      }
    }
  }

  printf("Solved in %d moves\n", num_moves);

  free_state(state);

  return 0;
}