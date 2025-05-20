//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

  int cpu_usage;
  int sample_time = 5;  // Number of seconds between each sample
  int total_samples = 10;  // Number of samples to take
  
  printf("Starting CPU Usage Monitor...\n");

  for (int i = 0; i < total_samples; i++) {
    // Read CPU usage
    FILE *f = fopen("/proc/stat", "r");
    char buf[256];
    fgets(buf, sizeof(buf), f);
    fclose(f);

    char* cpu_str = strtok(buf, " ");
    cpu_str = strtok(NULL, " ");
    int user = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    int nice = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    int sys = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    int idle = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    int iowait = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    int irq = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    int softirq = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    int steal = atoi(cpu_str);

    // Calculate CPU usage
    int prev_idle = idle;
    int prev_total = user + nice + sys + idle + iowait + irq + softirq + steal;
    sleep(sample_time);
    
    f = fopen("/proc/stat", "r");
    fgets(buf, sizeof(buf), f);
    fclose(f);

    cpu_str = strtok(buf, " ");
    cpu_str = strtok(NULL, " ");
    user = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    nice = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    sys = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    idle = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    iowait = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    irq = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    softirq = atoi(cpu_str);
    cpu_str = strtok(NULL, " ");
    steal = atoi(cpu_str);

    int idle_diff = idle - prev_idle;
    int total_diff = (user + nice + sys + idle + iowait + irq + softirq + steal) - prev_total;
    cpu_usage = (total_diff - idle_diff) * 100 / total_diff;
    
    // Display CPU usage
    printf("Sample %d: CPU Usage %d%%\n", i+1, cpu_usage);
  }

  printf("CPU Usage Monitor Complete.\n");

  return 0;
}