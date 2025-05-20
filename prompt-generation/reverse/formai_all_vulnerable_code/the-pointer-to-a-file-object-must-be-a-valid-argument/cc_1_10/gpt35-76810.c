//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the current C RAM usage
unsigned long get_ram_usage() 
{
    FILE* f = fopen("/proc/self/status", "r");
    char line_buff[128];
    unsigned long result = 0;
    while (fgets(line_buff, sizeof(line_buff), f))
    {
        if (strncmp(line_buff, "VmSize:", 7) == 0) {
            result = atoi(&line_buff[7]);
            break;
        }
    }
    fclose(f);
    return result;
}

// Store RAM usage as variables
unsigned long initial_ram_usage, current_ram_usage;

int main() 
{
    // Get initial RAM usage
    initial_ram_usage = get_ram_usage();

    // Run program and monitor RAM usage
    for (int i=0; i<100000; i++)
    {
        // Allocate memory for multiple variables
        int *var1 = malloc(sizeof(int));
        float *var2 = malloc(sizeof(float));
        double *var3 = malloc(sizeof(double));

        // Do some operations with variables
        *var1 = i;
        *var2 = i / 2.0;
        *var3 = i * 1.6;

        // Free memory for variables
        free(var1);
        free(var2);
        free(var3);

        // Print current RAM usage every 1000 iterations
        if (i % 1000 == 0) {
            current_ram_usage = get_ram_usage();
            printf("Current C RAM usage: %lu KB\n", current_ram_usage - initial_ram_usage);
        }
    }
    return 0;
}