//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define PI 3.14159265
#define SAMPLE_RATE 8000  // Sampling rate of 8kHz
#define BUFFER_SIZE 256  // Buffer size for processing block of samples

// Function to generate test signal (sine wave)
void generateSignal(float* signal, int length, int frequency) {
    int i;
    for(i=0; i<length; i++) {
        signal[i] = sin(2*PI*i*frequency/SAMPLE_RATE);  // Generate sine wave
    }
}

// Thread function for filtering signal with low pass filter
void* lowPassFilter(void* data) {
    float* signal = ((float**)data)[0];
    float* filteredSignal = ((float**)data)[1];
    int length = *(int*)data;  // Length of input signal
    int cutoffFrequency = *(int*)((int*)data + 1);  // Cutoff frequency for filter
    int i;

    float a = exp(-2*PI*cutoffFrequency/SAMPLE_RATE);  // Filter coefficient

    // Filter processing loop
    for(i=0; i<length; i++) {
        if(i == 0) {
            filteredSignal[i] = signal[i];
        } else {
            filteredSignal[i] = ((1-a)/2)*(signal[i] + signal[i-1]) + a*filteredSignal[i-1];
        }
    }

    return NULL;
}

int main() {
    int frequency = 1000;  // Signal frequency of 1kHz
    int cutoffFrequency = 500;  // Cutoff frequency of filter is half signal frequency
    int length = 8000;  // Generate signal of 1 second

    float* signal = (float*)malloc(length * sizeof(float));
    generateSignal(signal, length, frequency);  // Generate test signal

    float* filteredSignal = (float*)malloc(length * sizeof(float));
    pthread_t filterThread;
    void* filterData[2] = {signal, filteredSignal};

    // Initialize thread attributes
    pthread_attr_t filterAttr;
    pthread_attr_init(&filterAttr);
    pthread_attr_setdetachstate(&filterAttr, PTHREAD_CREATE_JOINABLE);

    // Create thread for filtering signal with low pass filter
    int ret = pthread_create(&filterThread, &filterAttr, lowPassFilter, &filterData);
    if (ret) {
        printf("Error creating filter thread!");
        exit(-1);
    }

    // Wait for filter thread to complete before continuing
    pthread_join(filterThread, NULL);

    free(signal);  // Free memory for input signal

    // Print original and filtered signal values for comparison
    int i;
    for(i=0; i<length; i++) {
        printf("%f\t%f\n", signal[i], filteredSignal[i]);
    }

    free(filteredSignal);  // Free memory for filtered signal
    pthread_attr_destroy(&filterAttr);  // Destroy thread attributes

    return 0;
}