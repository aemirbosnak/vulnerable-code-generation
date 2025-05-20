//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 100

int main() {
  int mem_total, mem_free;
  float mem_used;

  FILE* fp;
  char path[MAX_LEN];

  while (1) {
    sprintf(path, "/proc/meminfo");
    fp = fopen(path, "r");

    if (fp == NULL) {
      printf("Error opening file!");
      exit(1);
    }

    char line[MAX_LEN];
    int line_num = 0;

    // Read memory information from file
    while (fgets(line, MAX_LEN, fp)) {
      line_num++;
      char* token = strtok(line, " ");
      int value = atoi(strtok(NULL, " "));

      if (line_num == 1) {
        mem_total = value;
      } else if (line_num == 2) {
        mem_free = value;
      }
    }

    fclose(fp);

    // Calculate memory used
    mem_used = (float)(mem_total - mem_free) / (float)mem_total * 100.0;

    // Print memory information
    printf("Total memory: %d kB\n", mem_total);
    printf("Free memory: %d kB\n", mem_free);
    printf("Used memory: %.2f%%\n", mem_used);

    // Wait for 1 second
    sleep(1);
  }
  
  return 0;
}