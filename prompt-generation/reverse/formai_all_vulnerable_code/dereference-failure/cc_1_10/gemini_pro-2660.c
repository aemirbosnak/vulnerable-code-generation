//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define TEMPERATURE_SAMPLE_INTERVAL 1000 // in milliseconds
#define TEMPERATURE_DISPLAY_INTERVAL 5000 // in milliseconds

#define TEMPERATURE_SENSOR_PATH "/sys/bus/w1/devices/28-000007863939/temperature"

int main() {
    // Open the temperature sensor file
    FILE *temperature_file = fopen(TEMPERATURE_SENSOR_PATH, "r");
    if (temperature_file == NULL) {
        perror("Error opening temperature sensor file");
        return EXIT_FAILURE;
    }

    // Initialize the temperature variables
    float temperature_celsius = 0.0f;
    float temperature_fahrenheit = 0.0f;

    // Get the current time
    time_t start_time = time(NULL);

    // Main loop
    while (1) {
        // Get the current time
        time_t current_time = time(NULL);

        // Check if it is time to sample the temperature
        if (current_time - start_time >= TEMPERATURE_SAMPLE_INTERVAL / 1000) {
            // Read the temperature from the sensor file
            char temperature_buffer[256];
            if (fgets(temperature_buffer, sizeof(temperature_buffer), temperature_file) == NULL) {
                perror("Error reading temperature from sensor file");
                return EXIT_FAILURE;
            }

            // Parse the temperature from the buffer
            char *temperature_string = strstr(temperature_buffer, "t=");
            if (temperature_string == NULL) {
                fprintf(stderr, "Error parsing temperature from sensor file\n");
                return EXIT_FAILURE;
            }

            temperature_celsius = atof(temperature_string + 2) / 1000;
            temperature_fahrenheit = temperature_celsius * 9 / 5 + 32;

            // Reset the start time
            start_time = current_time;
        }

        // Check if it is time to display the temperature
        if (current_time - start_time >= TEMPERATURE_DISPLAY_INTERVAL / 1000) {
            // Display the temperature
            printf("Temperature: %.2f°C (%.2f°F)\n", temperature_celsius, temperature_fahrenheit);

            // Reset the start time
            start_time = current_time;
        }
    }

    // Close the temperature sensor file
    fclose(temperature_file);

    return EXIT_SUCCESS;
}