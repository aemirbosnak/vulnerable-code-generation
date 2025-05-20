//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SAMPLES 10 // set to the maximum number of samples to gather
#define SLEEP_TIME 1    // number of seconds to wait between samples

int main(int argc, char** argv) {
    int num_samples = 0;
    int interval = SLEEP_TIME;
    int show_avg = 0;
    int arg_idx = 1;
    
    // Parse command line arguments
    while(arg_idx < argc) {
        if(strcmp(argv[arg_idx], "--samples") == 0 || strcmp(argv[arg_idx], "-s") == 0) {
            arg_idx++;
            if(arg_idx < argc) {
                num_samples = atoi(argv[arg_idx]);
            }
        }
        else if(strcmp(argv[arg_idx], "--interval") == 0 || strcmp(argv[arg_idx], "-i") == 0) {
            arg_idx++;
            if(arg_idx < argc) {
                interval = atoi(argv[arg_idx]);
            }
        }
        else if(strcmp(argv[arg_idx], "--average") == 0 || strcmp(argv[arg_idx], "-a") == 0) {
            show_avg = 1;
        }
        arg_idx++;
    }
    
    if(num_samples <= 0 || interval <= 0) {
        printf("Usage: %s --samples <samples> --interval <interval> [--average]\n", argv[0]);
        return 1;
    }
    
    // Gather samples every 'interval' seconds
    int samples[MAX_SAMPLES];
    int i = 0;
    while(i < num_samples) {
        // Get RAM usage in kB
        FILE* file = fopen("/proc/meminfo", "r");
        char* line = NULL;
        size_t len = 0;
        ssize_t read;
        int mem_total = 0;
        int mem_free = 0;
        while((read = getline(&line, &len, file)) != -1){
            if (strstr(line, "MemTotal:")){
                sscanf(line, "%*s %d", &mem_total);
            }
            if (strstr(line, "MemAvailable:")){
                sscanf(line, "%*s %d", &mem_free);
            }
        }
        fclose(file);
        if(line){
            free(line);
        }
        int ram_used = mem_total - mem_free;
        samples[i] = ram_used;
        printf("Sample #%d: %d kB\n", i+1, ram_used);
        i++;
        sleep(interval);
    }
    
    // Calculate average usage
    int sum = 0;
    int max_usage = 0;
    for(i = 0; i < num_samples; i++) {
        sum += samples[i];
        if(samples[i] > max_usage) {
            max_usage = samples[i];
        }
    }
    float avg_usage = (float) sum / num_samples;
    
    // Print results
    printf("\n");
    printf("Max usage: %d kB\n", max_usage);
    printf("Avg usage: %.2f kB\n", avg_usage);
    if(show_avg) {
        printf("\nSamples:\n");
        for(i = 0; i < num_samples; i++) {
            printf("%d, ", samples[i]);
        }
        printf("\n");
    }
    
    return 0;
}