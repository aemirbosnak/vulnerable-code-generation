//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE 1000
#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int *data;
    int start_index;
    int end_index;
} ThreadData;

// Function to generate random data
void generate_data(int *data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to perform some calculations on data (e.g., finding the maximum value)
void* calculate_max(void* arg) {
    ThreadData *thread_data = (ThreadData*)arg;
    int max_value = thread_data->data[thread_data->start_index];
    
    for (int i = thread_data->start_index; i < thread_data->end_index; i++) {
        if (thread_data->data[i] > max_value) {
            max_value = thread_data->data[i];
        }
    }
    
    printf("Thread %d: Maximum value from index %d to %d is %d\n",
           thread_data->thread_id, thread_data->start_index, thread_data->end_index, max_value);
    
    pthread_exit(NULL);
}

// Function to perform average calculation on data
void* calculate_average(void* arg) {
    ThreadData *thread_data = (ThreadData*)arg;
    int sum = 0;
    int count = thread_data->end_index - thread_data->start_index;
    
    for (int i = thread_data->start_index; i < thread_data->end_index; i++) {
        sum += thread_data->data[i];
    }
    
    double average = (double)sum / count;
    printf("Thread %d: Average value from index %d to %d is %.2f\n",
           thread_data->thread_id, thread_data->start_index, thread_data->end_index, average);
    
    pthread_exit(NULL);
}

// Function to perform standard deviation calculation
void* calculate_stddev(void* arg) {
    ThreadData *thread_data = (ThreadData*)arg;
    double sum = 0.0;
    double sum_squared = 0.0;
    int count = thread_data->end_index - thread_data->start_index;
    
    for (int i = thread_data->start_index; i < thread_data->end_index; i++) {
        sum += thread_data->data[i];
        sum_squared += (thread_data->data[i] * thread_data->data[i]);
    }
    
    double mean = sum / count;
    double stddev = sqrt((sum_squared / count) - (mean * mean));
    
    printf("Thread %d: Standard Deviation from index %d to %d is %.2f\n",
           thread_data->thread_id, thread_data->start_index, thread_data->end_index, stddev);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int *data = malloc(sizeof(int) * DATA_SIZE);
    
    // Generate random data
    srand(time(NULL));
    generate_data(data, DATA_SIZE);
    
    int segment_size = DATA_SIZE / NUM_THREADS;

    // Create threads for max calculation
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].data = data;
        thread_data[i].start_index = i * segment_size;
        thread_data[i].end_index = (i == NUM_THREADS - 1) ? DATA_SIZE : (i + 1) * segment_size;
        
        pthread_create(&threads[i], NULL, calculate_max, (void*)&thread_data[i]);
    }

    // Wait for max calculation threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create threads for average calculation
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].data = data;
        thread_data[i].start_index = i * segment_size;
        thread_data[i].end_index = (i == NUM_THREADS - 1) ? DATA_SIZE : (i + 1) * segment_size;
        
        pthread_create(&threads[i], NULL, calculate_average, (void*)&thread_data[i]);
    }

    // Wait for average calculation threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create threads for standard deviation calculation
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].data = data;
        thread_data[i].start_index = i * segment_size;
        thread_data[i].end_index = (i == NUM_THREADS - 1) ? DATA_SIZE : (i + 1) * segment_size;
        
        pthread_create(&threads[i], NULL, calculate_stddev, (void*)&thread_data[i]);
    }

    // Wait for standard deviation calculation threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(data);
    return 0;
}