//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_READINGS 100
#define FILE_NAME "temperature_log.txt"
#define TEMPERATURE_MIN -10
#define TEMPERATURE_MAX 40

// Function to simulate reading temperature from a sensor
float read_temperature() {
    return (float)(rand() % (TEMPERATURE_MAX - TEMPERATURE_MIN + 1) + TEMPERATURE_MIN);
}

// Function to log temperature data into a file
void log_temperature(FILE *file, float temperature) {
    fprintf(file, "Temperature Reading: %.2f°C\n", temperature);
}

// Function to display a colorful temperature output
void display_temperature(float temperature) {
    if (temperature < 0) {
        printf("\033[1;34m"); // Blue for cold
    } else if (temperature >= 0 && temperature <= 20) {
        printf("\033[1;32m"); // Green for moderate
    } else {
        printf("\033[1;31m"); // Red for hot
    }

    printf("Current Temperature: %.2f°C\n", temperature);
    printf("\033[0m"); // Reset color
}

int main() {
    srand(time(NULL));
    float *temperatures = malloc(MAX_READINGS * sizeof(float));
    FILE *file;

    // Open log file
    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error opening file");
        free(temperatures);
        return 1;
    }

    printf("Welcome to the Temperature Monitor!\n");
    printf("Monitoring temperatures, press Ctrl+C to stop...\n");

    // Simulate continuous temperature readings
    for (int i = 0; i < MAX_READINGS; i++) {
        sleep(1); // Simulate delay for readings
        temperatures[i] = read_temperature();
        log_temperature(file, temperatures[i]);
        display_temperature(temperatures[i]);
    }

    fclose(file);
    free(temperatures);
    printf("Temperature monitoring finished.\n");
    printf("All readings logged in %s\n", FILE_NAME);
    
    return 0;
}