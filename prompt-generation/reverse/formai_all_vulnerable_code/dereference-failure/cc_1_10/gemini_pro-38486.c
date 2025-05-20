//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>

#define ACCELEROMETER_SAMPLE_RATE 100
#define HEART_RATE_SAMPLE_RATE 10
#define OXYGEN_SATURATION_SAMPLE_RATE 5
#define TEMPERATURE_SAMPLE_RATE 1

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} accelerometer_sample_t;

typedef struct {
    uint8_t value;
} heart_rate_sample_t;

typedef struct {
    uint8_t value;
} oxygen_saturation_sample_t;

typedef struct {
    float value;
} temperature_sample_t;

typedef struct {
    accelerometer_sample_t accelerometer_sample;
    heart_rate_sample_t heart_rate_sample;
    oxygen_saturation_sample_t oxygen_saturation_sample;
    temperature_sample_t temperature_sample;
} fitness_tracker_sample_t;

typedef struct {
    bool is_running;
    pthread_t thread;
    fitness_tracker_sample_t *samples;
    size_t num_samples;
} fitness_tracker_t;

void *fitness_tracker_thread(void *arg) {
    fitness_tracker_t *fitness_tracker = (fitness_tracker_t *)arg;

    while (fitness_tracker->is_running) {
        // Collect a sample from each sensor.
        accelerometer_sample_t accelerometer_sample = {0, 0, 0};
        heart_rate_sample_t heart_rate_sample = {0};
        oxygen_saturation_sample_t oxygen_saturation_sample = {0};
        temperature_sample_t temperature_sample = {0.0f};

        // Store the sample in the buffer.
        fitness_tracker->samples[fitness_tracker->num_samples].accelerometer_sample = accelerometer_sample;
        fitness_tracker->samples[fitness_tracker->num_samples].heart_rate_sample = heart_rate_sample;
        fitness_tracker->samples[fitness_tracker->num_samples].oxygen_saturation_sample = oxygen_saturation_sample;
        fitness_tracker->samples[fitness_tracker->num_samples].temperature_sample = temperature_sample;

        // Increment the number of samples.
        fitness_tracker->num_samples++;

        // Sleep for a bit before collecting the next sample.
        usleep(1000000 / ACCELEROMETER_SAMPLE_RATE);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    // Create a fitness tracker.
    fitness_tracker_t fitness_tracker = {
        .is_running = false,
        .thread = NULL,
        .samples = NULL,
        .num_samples = 0
    };

    // Start the fitness tracker thread.
    fitness_tracker.is_running = true;
    pthread_create(&fitness_tracker.thread, NULL, fitness_tracker_thread, &fitness_tracker);

    // Wait for the user to press enter.
    getchar();

    // Stop the fitness tracker thread.
    fitness_tracker.is_running = false;
    pthread_join(fitness_tracker.thread, NULL);

    // Print the fitness tracker data.
    for (size_t i = 0; i < fitness_tracker.num_samples; i++) {
        printf("Accelerometer: %d, %d, %d\n",
            fitness_tracker.samples[i].accelerometer_sample.x,
            fitness_tracker.samples[i].accelerometer_sample.y,
            fitness_tracker.samples[i].accelerometer_sample.z);
        printf("Heart rate: %d\n", fitness_tracker.samples[i].heart_rate_sample.value);
        printf("Oxygen saturation: %d\n", fitness_tracker.samples[i].oxygen_saturation_sample.value);
        printf("Temperature: %.2f\n\n", fitness_tracker.samples[i].temperature_sample.value);
    }

    // Free the fitness tracker data.
    free(fitness_tracker.samples);

    return 0;
}