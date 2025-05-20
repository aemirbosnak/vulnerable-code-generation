//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to simulate reading temperature from a sensor
float read_temperature() {
    // Simulating a temperature range from -10.0 to 40.0 degrees Celsius
    return (float)(rand() % 500) / 10.0 - 10.0; // Generate a float between -10.0 and 40.0
}

// Function to insert temperature reading into a history log
void log_temperature(float temperature) {
    FILE *log_file = fopen("temperature_log.txt", "a");
    if (log_file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    // Remove the newline character from the timestamp string
    timestamp[strlen(timestamp) - 1] = '\0';
    fprintf(log_file, "%s: %.2f°C\n", timestamp, temperature);
    fclose(log_file);
}

// Function to check temperature threshold
void check_threshold(float temperature, float lower_threshold, float upper_threshold) {
    if (temperature < lower_threshold) {
        printf("Warning: Temperature %.2f°C is below the lower threshold of %.2f°C.\n", temperature, lower_threshold);
    } else if (temperature > upper_threshold) {
        printf("Warning: Temperature %.2f°C is above the upper threshold of %.2f°C.\n", temperature, upper_threshold);
    } else {
        printf("Temperature is within normal range: %.2f°C\n", temperature);
    }
}

// Function to display current temperature and historical data
void display_temperature_history() {
    printf("\n--- Temperature History ---\n");
    char buffer[256];
    FILE *log_file = fopen("temperature_log.txt", "r");
    if (log_file == NULL) {
        perror("Unable to open log file");
        return;
    }
    while (fgets(buffer, sizeof(buffer), log_file) != NULL) {
        printf("%s", buffer);
    }
    fclose(log_file);
}

int main() {
    float lower_threshold = 0.0; // Lower temperature threshold
    float upper_threshold = 30.0; // Upper temperature threshold
    srand(time(NULL)); // Seed the random number generator for temperature readings

    printf("Temperature Monitoring System\n");
    printf("Lower Threshold: %.2f°C\n", lower_threshold);
    printf("Upper Threshold: %.2f°C\n", upper_threshold);
    
    while (1) {
        float current_temperature = read_temperature(); // Simulated temperature reading
        printf("Current Temperature: %.2f°C\n", current_temperature);
        log_temperature(current_temperature); // Log the temperature
        check_threshold(current_temperature, lower_threshold, upper_threshold); // Check for warnings

        // Display the temperature history every 5 readings
        static int readings_count = 0;
        readings_count++;
        if (readings_count % 5 == 0) {
            display_temperature_history();
        }
        
        sleep(2); // Wait for 2 seconds before the next reading
    }

    return 0; // Exit successfully
}