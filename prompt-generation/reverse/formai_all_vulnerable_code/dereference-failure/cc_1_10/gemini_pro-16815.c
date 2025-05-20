//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the temperature sensor's parameters
#define TEMP_SENSOR_MIN_TEMP -50.0
#define TEMP_SENSOR_MAX_TEMP 150.0
#define TEMP_SENSOR_RESOLUTION 0.1

// Define the temperature monitor's parameters
#define TEMP_MONITOR_SAMPLE_RATE 1.0 // Hz
#define TEMP_MONITOR_WINDOW_SIZE 10

// Define the data structures
typedef struct {
    double temperature;
    time_t timestamp;
} TemperatureReading;

typedef struct {
    TemperatureReading* readings;
    size_t size;
} TemperatureMonitor;

// Create a new temperature monitor
TemperatureMonitor* create_temperature_monitor() {
    TemperatureMonitor* monitor = malloc(sizeof(TemperatureMonitor));
    monitor->readings = malloc(TEMP_MONITOR_WINDOW_SIZE * sizeof(TemperatureReading));
    monitor->size = 0;
    return monitor;
}

// Add a new temperature reading to the monitor
void add_temperature_reading(TemperatureMonitor* monitor, double temperature) {
    // Check if the temperature is within the valid range
    if (temperature < TEMP_SENSOR_MIN_TEMP || temperature > TEMP_SENSOR_MAX_TEMP) {
        fprintf(stderr, "Error: Temperature out of range\n");
        return;
    }

    // Add the new reading to the buffer
    monitor->readings[monitor->size].temperature = temperature;
    monitor->readings[monitor->size].timestamp = time(NULL);
    monitor->size++;

    // If the buffer is full, remove the oldest reading
    if (monitor->size > TEMP_MONITOR_WINDOW_SIZE) {
        for (size_t i = 0; i < monitor->size - 1; i++) {
            monitor->readings[i] = monitor->readings[i + 1];
        }
        monitor->size--;
    }
}

// Get the average temperature from the monitor
double get_average_temperature(TemperatureMonitor* monitor) {
    double average_temperature = 0.0;
    for (size_t i = 0; i < monitor->size; i++) {
        average_temperature += monitor->readings[i].temperature;
    }
    average_temperature /= monitor->size;
    return average_temperature;
}

// Get the standard deviation of the temperature from the monitor
double get_standard_deviation(TemperatureMonitor* monitor) {
    double average_temperature = get_average_temperature(monitor);
    double variance = 0.0;
    for (size_t i = 0; i < monitor->size; i++) {
        variance += pow(monitor->readings[i].temperature - average_temperature, 2);
    }
    variance /= monitor->size;
    double standard_deviation = sqrt(variance);
    return standard_deviation;
}

// Print the temperature monitor's data
void print_temperature_monitor(TemperatureMonitor* monitor) {
    printf("Temperature Monitor Data:\n");
    printf("  Average Temperature: %.2f\n", get_average_temperature(monitor));
    printf("  Standard Deviation: %.2f\n", get_standard_deviation(monitor));
    printf("  Readings:\n");
    for (size_t i = 0; i < monitor->size; i++) {
        printf("    %.2f at %s\n", monitor->readings[i].temperature, ctime(&monitor->readings[i].timestamp));
    }
}

// Free the memory allocated by the temperature monitor
void free_temperature_monitor(TemperatureMonitor* monitor) {
    free(monitor->readings);
    free(monitor);
}

// Main function
int main() {
    // Create a new temperature monitor
    TemperatureMonitor* monitor = create_temperature_monitor();

    // Add some sample temperature readings to the monitor
    for (double temperature = TEMP_SENSOR_MIN_TEMP; temperature <= TEMP_SENSOR_MAX_TEMP; temperature += TEMP_SENSOR_RESOLUTION) {
        add_temperature_reading(monitor, temperature);
    }

    // Print the temperature monitor's data
    print_temperature_monitor(monitor);

    // Free the memory allocated by the temperature monitor
    free_temperature_monitor(monitor);

    return 0;
}