//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

int main() {
    int i;
    double cpu_percent;
    struct rusage usage;
    char *token;
    char *delimiter = " ";

    // Get CPU usage
    getrusage(RUSAGE_SELF, &usage);

    // Calculate CPU percentage
    cpu_percent = (double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000.0;
    cpu_percent /= (double) usage.ru_stime.tv_sec + (double) usage.ru_stime.tv_usec / 1000000.0;
    cpu_percent *= 100;

    // Print CPU usage
    printf("CPU usage: %.2f%%\n", cpu_percent);

    // Get process ID
    pid_t pid = getpid();

    // Get process name
    char process_name[1024];
    sprintf(process_name, "/proc/%d/cmdline", pid);

    // Read process name
    FILE *fp = fopen(process_name, "r");
    if (fp == NULL) {
        printf("Error: Unable to read process name.\n");
        return 1;
    }

    // Get process name
    fgets(process_name, 1024, fp);

    // Close file
    fclose(fp);

    // Remove newline character
    process_name[strcspn(process_name, "\n")] = '\0';

    // Print process name
    printf("Process name: %s\n", process_name);

    // Get process memory usage
    char *mem_usage_str = NULL;
    size_t mem_usage_size = 0;
    FILE *mem_fp = fopen("/proc/self/status", "r");
    if (mem_fp!= NULL) {
        while ((getline(&mem_usage_str, &mem_usage_size, mem_fp))!= -1) {
            if (strstr(mem_usage_str, "VmSize:")!= NULL) {
                token = strtok(mem_usage_str, delimiter);
                printf("Memory usage: %s\n", token);
                break;
            }
        }
        free(mem_usage_str);
        fclose(mem_fp);
    } else {
        printf("Error: Unable to read memory usage.\n");
        return 1;
    }

    return 0;
}