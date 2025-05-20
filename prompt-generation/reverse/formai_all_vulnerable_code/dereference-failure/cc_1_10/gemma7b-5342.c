//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
  system("clear");
  char **mem_usage = NULL;
  long **physical_memory = NULL;
  long **swap_usage = NULL;
  long total_physical_memory = 0L;
  long total_swap_usage = 0L;

  mem_usage = (char **)malloc(sizeof(char *) * 4);
  physical_memory = (long **)malloc(sizeof(long *) * 4);
  swap_usage = (long **)malloc(sizeof(long *) * 4);

  for (int i = 0; i < 4; i++) {
    physical_memory[i] = (long *)malloc(sizeof(long) * 3);
    swap_usage[i] = (long *)malloc(sizeof(long) * 3);
  }

  while (1) {
    system("clear");
    for (int i = 0; i < 4; i++) {
      printf("Memory Usage for Partition %d:\n", i + 1);
      printf("-------------------------\n");
      printf("Physical Memory: %.2f%% (%.2f MB)\n",
             (double)physical_memory[i][0] / total_physical_memory * 100.0,
             (double)physical_memory[i][0] / 1024);
      printf("Swap Usage: %.2f%% (%.2f MB)\n",
             (double)swap_usage[i][0] / total_swap_usage * 100.0,
             (double)swap_usage[i][0] / 1024);
      printf("\n");
    }

    sleep(2);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      free(physical_memory[i][j]);
      free(swap_usage[i][j]);
    }
    free(physical_memory[i]);
    free(swap_usage[i]);
  }

  free(mem_usage);
  free(physical_memory);
  free(swap_usage);

  return 0;
}