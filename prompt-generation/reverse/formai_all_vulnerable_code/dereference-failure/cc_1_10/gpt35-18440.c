//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
  float cpu_usage;
  char buf[1024];
  FILE* fp;
  int total_jiffies, work_jiffies;
  
  while(1) {
    fp = fopen("/proc/stat", "r");
    if(fp == NULL) {
      fprintf(stderr, "Error opening /proc/stat\n");
      exit(EXIT_FAILURE);
    }
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    // parse total jiffies
    char* token;
    token = strtok(buf, " ");
    int i = 0;
    while(token != NULL) {
      i++;
      if(i == 1) continue; // skip the first token (cpu label)
      if(i > 9) break; // we only need the first 9 values
      total_jiffies += atoi(token);
      token = strtok(NULL, " ");
    }

    // parse work jiffies
    work_jiffies = total_jiffies - atoi(token);

    // calculate CPU usage percentage
    cpu_usage = ((float)work_jiffies / (float)total_jiffies) * 100.0;

    // print CPU usage percentage
    printf("CPU usage: %5.2f%%\n", cpu_usage);

    // wait for 1 second before checking again
    sleep(1);
  }
  
  return 0;
}