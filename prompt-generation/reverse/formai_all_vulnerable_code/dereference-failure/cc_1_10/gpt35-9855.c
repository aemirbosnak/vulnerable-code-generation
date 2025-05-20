//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 5
#define DEFAULT_SAMPLE_SIZE 10

int main(int argc, char *argv[]) {
    int sample_size;
    int signal_strength;
    int *signal_strengths;
    int i, j;
    int max_signal_strength = MIN_SIGNAL_STRENGTH - 1;
    int min_signal_strength = MAX_SIGNAL_STRENGTH + 1;
    int total_signal_strength = 0;
    double average_signal_strength;
    
    // Parse command line arguments
    if(argc > 1) {
        sample_size = atoi(argv[1]);
    } else {
        sample_size = DEFAULT_SAMPLE_SIZE;
    }
    
    // Allocate memory for signal_strengths array
    signal_strengths = (int *) malloc(sizeof(int) * sample_size);
    
    // Generate random signal strengths and store in array
    srand(time(NULL));
    printf("Collecting signal strength data...\n");
    for(i = 0; i < sample_size; i++) {
        signal_strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
        signal_strengths[i] = signal_strength;
        printf("Sample %d: %d\n", i+1, signal_strength);
    }
    
    // Calculate min, max, and average signal strengths
    for(i = 0; i < sample_size; i++) {
        if(signal_strengths[i] > max_signal_strength) {
            max_signal_strength = signal_strengths[i];
        }
        if(signal_strengths[i] < min_signal_strength) {
            min_signal_strength = signal_strengths[i];
        }
        total_signal_strength += signal_strengths[i];
    }
    average_signal_strength = (double) total_signal_strength / sample_size;
    
    // Display results
    printf("Signal strength analysis:\n");
    printf("Max signal strength: %d\n", max_signal_strength);
    printf("Min signal strength: %d\n", min_signal_strength);
    printf("Average signal strength: %0.2f\n", average_signal_strength);
    
    // Free memory and exit
    free(signal_strengths);
    return 0;
}