//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_RINGS 3

void hanoi_recur(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    printf("Move ring 1 from rod %c to rod %c\n", from_rod, to_rod);
    return;
  }
  hanoi_recur(n - 1, from_rod, aux_rod, to_rod);
  printf("Move ring %d from rod %c to rod %c\n", n, from_rod, to_rod);
  hanoi_recur(n - 1, aux_rod, to_rod, from_rod);
}

void hanoi_iter(int n, char from_rod, char to_rod, char aux_rod) {
  int moves[NUM_RINGS], num_moves = 0;
  int rods[NUM_RINGS];
  int i, j;

  for (i = 0; i < NUM_RINGS; ++i) {
    rods[i] = from_rod;
  }

  while (num_moves < n * (n - 1)) {
    for (i = 0; i < NUM_RINGS; ++i) {
      if (rods[i] == from_rod) {
        for (j = i + 1; j < NUM_RINGS; ++j) {
          if (rods[j] == to_rod) {
            moves[num_moves++] = i + 1;
            rods[i] = to_rod;
            break;
          } else if (rods[j] == aux_rod) {
            moves[num_moves++] = i + 1;
            rods[i] = aux_rod;
            break;
          }
        }
      } else if (rods[i] == aux_rod) {
        for (j = i + 1; j < NUM_RINGS; ++j) {
          if (rods[j] == from_rod) {
            moves[num_moves++] = i + 1;
            rods[i] = from_rod;
            break;
          } else if (rods[j] == to_rod) {
            moves[num_moves++] = i + 1;
            rods[i] = to_rod;
            break;
          }
        }
      }
    }
  }

  for (i = 0; i < num_moves; ++i) {
    printf("Move ring %d from rod %c to rod %c\n",
           moves[i], from_rod, to_rod);
    sleep(1);
  }
}

int main(int argc, char **argv) {
  int n;

  if (argc != 4) {
    fprintf(stderr, "Usage: %s n from_rod to_rod aux_rod\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  n = atoi(argv[1]);
  if (n <= 0) {
    fprintf(stderr, "Invalid number of rings: %d\n", n);
    exit(EXIT_FAILURE);
  }

  if (strlen(argv[2]) != 1 || strlen(argv[3]) != 1 || strlen(argv[4]) != 1) {
    fprintf(stderr, "Invalid rod names: %s %s %s\n", argv[2], argv[3], argv[4]);
    exit(EXIT_FAILURE);
  }

  if (argv[2][0] == argv[3][0] || argv[2][0] == argv[4][0] || argv[3][0] == argv[4][0]) {
    fprintf(stderr, "Invalid rod names: %s %s %s\n", argv[2], argv[3], argv[4]);
    exit(EXIT_FAILURE);
  }

  printf("Recursive solution:\n");
  hanoi_recur(n, argv[2][0], argv[3][0], argv[4][0]);

  printf("\nIterative solution:\n");
  hanoi_iter(n, argv[2][0], argv[3][0], argv[4][0]);

  return EXIT_SUCCESS;
}