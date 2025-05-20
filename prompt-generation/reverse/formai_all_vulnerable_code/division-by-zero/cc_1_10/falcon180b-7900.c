//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define CPU_USAGE_FILE "/proc/stat"

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int cpu_percentage = 0;
    int total_cpu_time = 0;
    int idle_cpu_time = 0;

    // Open the CPU usage file
    fp = fopen(CPU_USAGE_FILE, "r");
    if (fp == NULL) {
        printf("Error: Could not open CPU usage file.\n");
        exit(1);
    }

    // Read the first line of the file, which contains the CPU statistics
    if (fgets(line, MAX_LINE_SIZE, fp) == NULL) {
        printf("Error: Could not read CPU usage statistics.\n");
        fclose(fp);
        exit(1);
    }

    // Parse the CPU statistics line
    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (strcmp(token, "cpu") == 0) {
            token = strtok(NULL, " ");
            while (token!= NULL) {
                if (isdigit(token[0])) {
                    total_cpu_time += atoi(token);
                }
                token = strtok(NULL, " ");
            }
        }
        token = strtok(NULL, " ");
    }

    // Calculate the CPU usage percentage
    cpu_percentage = 100 - (idle_cpu_time * 100) / total_cpu_time;

    // Print the CPU usage percentage
    printf("CPU usage: %d%%\n", cpu_percentage);

    // Close the CPU usage file
    fclose(fp);

    return 0;
}