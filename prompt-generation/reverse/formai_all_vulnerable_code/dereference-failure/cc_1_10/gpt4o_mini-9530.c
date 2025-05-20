//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_DATA_POINTS 1000
#define NUM_THREADS 2

typedef struct {
    double *data;
    int start;
    int end;
} ThreadData;

double mean = 0.0;
double stddev = 0.0;
pthread_mutex_t lock;

void *calculate_mean(void *arg) {
    ThreadData *threadData = (ThreadData *)arg;
    double sum = 0.0;

    for (int i = threadData->start; i < threadData->end; i++) {
        sum += threadData->data[i];
    }

    pthread_mutex_lock(&lock);
    mean += sum;
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

void *calculate_stddev(void *arg) {
    ThreadData *threadData = (ThreadData *)arg;
    double sum = 0.0;
    
    for (int i = threadData->start; i < threadData->end; i++) {
        sum += pow(threadData->data[i] - (mean / NUM_DATA_POINTS), 2);
    }

    pthread_mutex_lock(&lock);
    stddev += sum;
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

double finalize_results(int count) {
    return sqrt(stddev / count);
}

int main() {
    double *data = malloc(NUM_DATA_POINTS * sizeof(double));
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    int segment = NUM_DATA_POINTS / NUM_THREADS;

    // Initialize data
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        data[i] = rand() % 100; // Random numbers between 0 and 99
    }

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Calculate Mean
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].data = data;
        threadData[i].start = i * segment;
        threadData[i].end = (i + 1) * segment;
        if (i == NUM_THREADS - 1) {
            threadData[i].end = NUM_DATA_POINTS; // Handle last segment
        }
        pthread_create(&threads[i], NULL, calculate_mean, (void *)&threadData[i]);
    }

    // Wait for mean calculation
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    mean /= NUM_DATA_POINTS; // Final mean calculation

    // Calculate Standard Deviation
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].data = data;
        threadData[i].start = i * segment;
        threadData[i].end = (i + 1) * segment;
        if (i == NUM_THREADS - 1) {
            threadData[i].end = NUM_DATA_POINTS; // Handle last segment
        }
        pthread_create(&threads[i], NULL, calculate_stddev, (void *)&threadData[i]);
    }

    // Wait for standard deviation calculation
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Final standard deviation calculation
    stddev = finalize_results(NUM_DATA_POINTS);

    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", stddev);

    free(data);
    pthread_mutex_destroy(&lock);
    
    return 0;
}