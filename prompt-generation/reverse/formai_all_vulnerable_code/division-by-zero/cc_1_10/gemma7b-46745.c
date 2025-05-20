//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_CPU_Utilization 100

int main() {
  char filename[] = "/proc/stat";
  FILE* file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  long long int previous_user, previous_system, previous_idle = 0LL;
  char buffer[1024];
  int i = 0;

  while (1) {
    fgets(buffer, 1024, file);
    if (buffer[0] == 'u' || buffer[0] == 'U') {
      int user_time = atoi(buffer + 11);
      int system_time = atoi(buffer + 15);
      int idle_time = atoi(buffer + 19);

      long long int current_user = user_time * 1000LL;
      long long int current_system = system_time * 1000LL;
      long long int current_idle = idle_time * 1000LL;

      long long int cpu_usage =
        (current_user + current_system) * 100LL / (current_user + current_system + current_idle);

      if (cpu_usage > MAX_CPU_Utilization) {
        printf("CPU usage: %.2f%% (overlimit)\n", cpu_usage);
      } else {
        printf("CPU usage: %.2f%%\n", cpu_usage);
      }

      previous_user = current_user;
      previous_system = current_system;
      previous_idle = current_idle;
    }

    sleep(1);
  }

  fclose(file);
  return EXIT_SUCCESS;
}