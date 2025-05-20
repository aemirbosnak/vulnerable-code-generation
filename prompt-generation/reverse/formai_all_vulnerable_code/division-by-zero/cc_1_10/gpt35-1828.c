//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_CPU_USAGE 100
#define BUFFER_SIZE 1024

int main() {
    int cpu_usage;
    char buffer[BUFFER_SIZE];
    FILE *file_stream;
    char *token;

    while (1) {
        // Open /proc/stat file
        file_stream = fopen("/proc/stat", "r");

        if (file_stream == NULL) {
            fprintf(stderr, "Error opening file\n");
            exit(1);
        }

        // Read first line of file
        fgets(buffer, BUFFER_SIZE, file_stream);

        // Close file
        fclose(file_stream);

        // Tokenize first line
        token = strtok(buffer, " ");

        // Skip first token as it is the CPU label
        token = strtok(NULL, " ");

        // Calculate CPU usage
        int user = atoi(token);
        token = strtok(NULL, " ");
        int nice = atoi(token);
        token = strtok(NULL, " ");
        int system = atoi(token);
        token = strtok(NULL, " ");
        int idle = atoi(token);
        token = strtok(NULL, " ");
        int iowait = atoi(token);
        token = strtok(NULL, " ");
        int irq = atoi(token);
        token = strtok(NULL, " ");
        int softirq = atoi(token);

        int total_idle = idle + iowait;
        int total_cpu = user + nice + system + irq + softirq + total_idle;

        cpu_usage = MAX_CPU_USAGE - ((total_idle * MAX_CPU_USAGE) / total_cpu);

        // Print CPU usage
        printf("\033[2J");
        printf("\033[1;H");
        printf("============== CPU Usage Monitor ==============\n");
        printf("       |");
        for(int i=0;i<MAX_CPU_USAGE;i++){
            if(i == cpu_usage){
                printf("x");
            }else{
                printf("-");
            }
        }
        printf("|\n");
        printf("       %d%%\n", cpu_usage);

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}