//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n_procs = 0;
  clock_t start_time, end_time;
  double cpu_usage;
  char **commands = NULL;

  while (1) {
    printf("Enter the number of processes to simulate: ");
    scanf("%d", &n_procs);

    if (n_procs <= 0) {
      break;
    }

    commands = malloc(n_procs * sizeof(char *));

    for (int i = 0; i < n_procs; i++) {
      commands[i] = malloc(20 * sizeof(char));
    }

    printf("Enter commands for each process (separate by semicolon):\n");

    for (int i = 0; i < n_procs; i++) {
      scanf("%s", commands[i]);
    }

    start_time = clock();

    for (int i = 0; i < n_procs; i++) {
      system(commands[i]);
    }

    end_time = clock();

    cpu_usage = (double)(end_time - start_time) / CLOCKS_PER_SEC * 100;

    printf("CPU usage: %.2f%%\n", cpu_usage);

    for (int i = 0; i < n_procs; i++) {
      free(commands[i]);
    }

    free(commands);
  }

  return 0;
}