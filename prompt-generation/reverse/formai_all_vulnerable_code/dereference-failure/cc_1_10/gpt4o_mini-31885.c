//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TEMPERATURE 40.0  // Maximum temperature that can be sensed
#define MIN_TEMPERATURE 0.0   // Minimum temperature that can be sensed
#define LOG_FILE "temperature_log.txt" // File to store the temperature readings

// Function to generate a peaceful random temperature value
float generate_random_temperature() {
    return ((float)rand()/(float)(RAND_MAX)) * (MAX_TEMPERATURE - MIN_TEMPERATURE) + MIN_TEMPERATURE;
}

// Function to log temperature in the serene log file
void log_temperature(float temperature) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening log file.\n");
        exit(EXIT_FAILURE);
    }

    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = 0;  // Remove newline character

    fprintf(file, "[%s] Temperature: %.2f°C\n", time_str, temperature);
    fclose(file);
}

// Function to display a gentle message to the user
void display_message(float temperature) {
    printf("---------------------------------------------------------------------\n");
    printf("                      🌼 Temperature Monitor 🌼                      \n");
    printf("---------------------------------------------------------------------\n");
    printf("Current Temperature: %.2f°C\n", temperature);
    
    if (temperature < 15.0) {
        printf("It's quite chilly, perhaps enjoy a warm beverage.\n");
    } else if (temperature >= 15.0 && temperature < 25.0) {
        printf("The weather is gently mild, a perfect time for a walk.\n");
    } else if (temperature >= 25.0 && temperature < 30.0) {
        printf("A lovely warm day, great for some outdoor activities!\n");
    } else {
        printf("It's quite warm, stay hydrated and take a break in the shade.\n");
    }

    printf("---------------------------------------------------------------------\n");
}

// Main function to start the peaceful monitoring of temperature
int main() {
    srand(time(NULL));  // Seed the random number generator
    float temperature;

    printf("Starting the Temperature Monitor...\n");
    while (1) {
        temperature = generate_random_temperature();  // Generate serene temperature
        log_temperature(temperature);  // Log the temperature
        display_message(temperature);   // Display the gentle message
        sleep(5);  // Wait for a serene 5 seconds before the next reading
    }

    return 0;
}