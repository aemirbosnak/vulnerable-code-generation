//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SENSORS 5
#define TEMP_THRESHOLD 30.0

typedef struct {
    int id;
    float temperature;
} SensorData;

void get_temperature(SensorData* sensor) {
    // Simulate reading temperature from a sensor
    // For demonstration purposes, we randomly generate a temperature.
    sensor->temperature = (float)(rand() % 100);
}

void log_temperature(SensorData* sensor) {
    FILE* log_file = fopen("temperature_log.txt", "a");
    if (log_file != NULL) {
        time_t now = time(NULL);
        char* time_str = ctime(&now);
        // Remove newline character from time_str
        time_str[strlen(time_str) - 1] = '\0';
        
        fprintf(log_file, "[%s] Sensor %d: Temperature = %.2f°C\n", time_str, sensor->id, sensor->temperature);
        fclose(log_file);
    } else {
        perror("Failed to open log file");
    }
}

void check_temperature(SensorData* sensor) {
    if (sensor->temperature > TEMP_THRESHOLD) {
        printf("Warning: Sensor %d reports high temperature: %.2f°C\n", sensor->id, sensor->temperature);
    } else {
        printf("Sensor %d is operating at a safe temperature: %.2f°C\n", sensor->id, sensor->temperature);
    }
}

void display_temperature(SensorData* sensors, int number_of_sensors) {
    printf("\nCurrent Temperature Readings:\n");
    for (int i = 0; i < number_of_sensors; i++) {
        printf("Sensor %d: %.2f°C\n", sensors[i].id, sensors[i].temperature);
    }
    printf("\n");
}

void peaceful_monitoring(SensorData* sensors, int number_of_sensors) {
    for (int i = 0; i < number_of_sensors; i++) {
        get_temperature(&sensors[i]);
        log_temperature(&sensors[i]);
        check_temperature(&sensors[i]);
    }
    display_temperature(sensors, number_of_sensors);
    printf("Data collected peacefully, let's take a moment to reflect on the environment.\n\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    SensorData sensors[MAX_SENSORS];
    for (int i = 0; i < MAX_SENSORS; i++) {
        sensors[i].id = i + 1; // Assigning unique IDs to each sensor
    }

    while (1) {
        peaceful_monitoring(sensors, MAX_SENSORS);
        sleep(10); // Sleep for 10 seconds between readings
    }

    return 0;
}