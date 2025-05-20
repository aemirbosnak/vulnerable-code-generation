//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 128

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <number of seconds to monitor>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int num_seconds = atoi(argv[1]);
  int num_cycles = num_seconds / 2;
  char buff[BUF_SIZE];
  FILE *fp;
  
  for (int i = 0; i < num_cycles; i++) {
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
      printf("Error opening /proc/stat file.\n");
      exit(EXIT_FAILURE);
    }

    fgets(buff, BUF_SIZE, fp);
    fclose(fp);

    long long user_time1, nice_time1, sys_time1, idle_time1, iowait_time1, irq_time1, softirq_time1, steal_time1, guest_time1, guest_nice_time1;
    sscanf(buff, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &user_time1, &nice_time1, &sys_time1, &idle_time1, &iowait_time1, &irq_time1, &softirq_time1, &steal_time1, &guest_time1, &guest_nice_time1);

    sleep(1);

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
      printf("Error opening /proc/stat file.\n");
      exit(EXIT_FAILURE);
    }

    fgets(buff, BUF_SIZE, fp);
    fclose(fp);

    long long user_time2, nice_time2, sys_time2, idle_time2, iowait_time2, irq_time2, softirq_time2, steal_time2, guest_time2, guest_nice_time2;
    sscanf(buff, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &user_time2, &nice_time2, &sys_time2, &idle_time2, &iowait_time2, &irq_time2, &softirq_time2, &steal_time2, &guest_time2, &guest_nice_time2);

    long long total_time1 = user_time1 + nice_time1 + sys_time1 + idle_time1 + iowait_time1 + irq_time1 + softirq_time1 + steal_time1 + guest_time1 + guest_nice_time1;
    long long total_time2 = user_time2 + nice_time2 + sys_time2 + idle_time2 + iowait_time2 + irq_time2 + softirq_time2 + steal_time2 + guest_time2 + guest_nice_time2;

    float cpu_usage = ((float)(total_time2 - total_time1 - idle_time2 + idle_time1) / (float)(total_time2 - total_time1)) * 100.0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("[%02d-%02d-%04d %02d:%02d:%02d] CPU usage: %.2f%%\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, cpu_usage);
  }

  return 0;
}