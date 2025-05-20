//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Sensor data structure
typedef struct {
    float temperature;
    float humidity;
    float pressure;
} SensorData;

// Sensor reading function
int readSensor(SensorData *data) {
    // Simulate sensor reading
    data->temperature = 25.0 + rand() % 5;
    data->humidity = 50.0 + rand() % 10;
    data->pressure = 1013.0 + rand() % 10;
    return 0;
}

// Data processing function
void processData(SensorData *data) {
    // Check for extreme values
    if (data->temperature > 40.0 || data->temperature < 10.0) {
        printf("Temperature warning: %.1f degrees Celsius\n", data->temperature);
    }
    if (data->humidity > 80.0 || data->humidity < 20.0) {
        printf("Humidity warning: %.1f%%\n", data->humidity);
    }
    if (data->pressure > 1030.0 || data->pressure < 990.0) {
        printf("Pressure warning: %.1f hPa\n", data->pressure);
    }
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Allocate memory for sensor data
    SensorData *data = malloc(sizeof(SensorData));

    // Continuously read and process sensor data
    while (1) {
        // Read sensor data
        if (readSensor(data) != 0) {
            perror("Error reading sensor");
            return EXIT_FAILURE;
        }

        // Process data
        processData(data);

        // Sleep for 1 second
        sleep(1);
    }

    // Free allocated memory
    free(data);

    return EXIT_SUCCESS;
}