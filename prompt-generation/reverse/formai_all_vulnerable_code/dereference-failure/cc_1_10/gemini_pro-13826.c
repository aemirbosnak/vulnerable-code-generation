//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define HAPPY_MAX 100
#define HAPPY_MIN 0

int main() {
  srand(time(NULL));

  printf("Hello! I'm here to help you keep track of your CPU usage.\n");

  while (1) {
    // Get the CPU usage.
    FILE *fp = fopen("/proc/stat", "r");
    char buf[1024];
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    // Parse the CPU usage.
    char *tok = strtok(buf, " ");
    tok = strtok(NULL, " ");
    long long user = atoll(tok);
    tok = strtok(NULL, " ");
    long long nice = atoll(tok);
    tok = strtok(NULL, " ");
    long long system = atoll(tok);
    tok = strtok(NULL, " ");
    long long idle = atoll(tok);

    // Calculate the CPU usage.
    long long total = user + nice + system + idle;
    double cpu_usage = (double)(user + nice + system) / total;

    // Print the CPU usage.
    printf("CPU usage: %.2f%%\n", cpu_usage * 100);

    // Generate a random happiness level.
    int happiness = rand() % (HAPPY_MAX - HAPPY_MIN + 1) + HAPPY_MIN;

    // Print a cheerful message based on the happiness level.
    if (happiness >= 90) {
      printf("I'm so happy to help you! :D\n");
    } else if (happiness >= 70) {
      printf("I'm glad to be of assistance! :)\n");
    } else if (happiness >= 50) {
      printf("I'm here to serve you! :|)\n");
    } else if (happiness >= 30) {
      printf("I'm doing my best to help you. :-\n");
    } else if (happiness >= 10) {
      printf("I'm trying my best. :(\n");
    } else {
      printf("I'm sorry, I'm not feeling very well. :-\n");
    }

    // Sleep for 1 second.
    sleep(1);
  }

  return 0;
}