//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// Define the temperature conversion function
double convert_temperature(double temperature, char from_unit, char to_unit) {
    // Check if the input is valid
    if (from_unit != 'C' && from_unit != 'F') {
        fprintf(stderr, "Error: Invalid input unit %c\n", from_unit);
        exit(EXIT_FAILURE);
    }
    if (to_unit != 'C' && to_unit != 'F') {
        fprintf(stderr, "Error: Invalid output unit %c\n", to_unit);
        exit(EXIT_FAILURE);
    }

    // Convert the temperature
    double converted_temperature;
    if (from_unit == 'C' && to_unit == 'F') {
        converted_temperature = (temperature * 9 / 5) + 32;
    } else if (from_unit == 'F' && to_unit == 'C') {
        converted_temperature = (temperature - 32) * 5 / 9;
    } else {
        converted_temperature = temperature;
    }

    // Return the converted temperature
    return converted_temperature;
}

// Define the thread function
void *thread_function(void *arg) {
    // Get the arguments
    struct {
        double temperature;
        char from_unit;
        char to_unit;
        double *result;
    } *args = (struct {
        double temperature;
        char from_unit;
        char to_unit;
        double *result;
    } *)arg;

    // Convert the temperature
    *args->result = convert_temperature(args->temperature, args->from_unit, args->to_unit);

    // Return NULL
    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <temperature> <from_unit> <to_unit>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the temperature, from unit, and to unit
    double temperature = atof(argv[1]);
    char from_unit = argv[2][0];
    char to_unit = argv[3][0];

    // Create a thread
    pthread_t thread;
    struct {
        double temperature;
        char from_unit;
        char to_unit;
        double *result;
    } args = {
        .temperature = temperature,
        .from_unit = from_unit,
        .to_unit = to_unit,
        .result = malloc(sizeof(double)),
    };
    if (pthread_create(&thread, NULL, thread_function, &args)) {
        fprintf(stderr, "Error: Could not create thread\n");
        exit(EXIT_FAILURE);
    }

    // Wait for the thread to finish
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error: Could not join thread\n");
        exit(EXIT_FAILURE);
    }

    // Print the converted temperature
    printf("Converted temperature: %.2f %c\n", *args.result, to_unit);

    // Free the allocated memory
    free(args.result);

    // Exit successfully
    return EXIT_SUCCESS;
}