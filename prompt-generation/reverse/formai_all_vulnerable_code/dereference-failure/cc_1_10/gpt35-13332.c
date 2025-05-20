//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CPUS 16

int main(int argc, char *argv[]) {
    int interval = 1; // default interval of 1 second
    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN); // get number of online CPUs
    float prev_usage[MAX_CPUS], curr_usage[MAX_CPUS];
    FILE *stat_file;
    
    if (argc > 1) {
        interval = atoi(argv[1]); // parse interval from command line
    }
    
    printf("Monitoring CPU usage every %d seconds...\n", interval);
    
    while (1) {
        stat_file = fopen("/proc/stat", "r"); // open statistics file
        if (!stat_file) {
            perror("Error opening /proc/stat");
            exit(EXIT_FAILURE);
        }
        
        // parse CPU usage statistics from file
        char line[256];
        fgets(line, sizeof(line), stat_file);
        for (int i = 0; i < num_cpus; i++) {
            fgets(line, sizeof(line), stat_file);
            sscanf(line, "cpu%d %*d %*d %*d %*d %*d %*d %*d %*d %*d %f",
                   &i, &curr_usage[i]);
        }
        fclose(stat_file);
        
        // calculate percentage CPU usage for each CPU
        for (int i = 0; i < num_cpus; i++) {
            curr_usage[i] /= (curr_usage[i] + prev_usage[i]);
            curr_usage[i] *= 100;
        }
        
        // print CPU usage statistics
        for (int i = 0; i < num_cpus; i++) {
            printf("CPU%d usage: %.2f%%\n", i, curr_usage[i]);
        }
        printf("\n");
        
        // update previous CPU usage values
        for (int i = 0; i < num_cpus; i++) {
            prev_usage[i] = curr_usage[i];
        }
        
        sleep(interval); // wait for specified interval
    }
    
    return 0;
}