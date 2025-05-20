//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_READINGS 100
#define TEMP_THRESHOLD 75.0  // Temperature threshold for alerts
#define LOG_FILE "temperature_log.txt"

// Function to generate a random temperature
float generate_random_temp() {
    return (float)(rand() % 100); // Random temperature between 0 and 99
}

// Function to log temperature readings
void log_temperature(float temperature) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(file, "%02d-%02d-%04d %02d:%02d:%02d - Temperature: %.2f\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec, temperature);
    fclose(file);
}

// Function to send alert if temperature exceeds the threshold
void check_threshold(float temperature) {
    if (temperature > TEMP_THRESHOLD) {
        printf("ALERT: Temperature exceeded threshold! Current temperature: %.2f\n", temperature);
    }
}

// Function to display statistics of temperature readings
void display_statistics(float temperatures[], int count) {
    float sum = 0.0;
    float min = temperatures[0];
    float max = temperatures[0];

    for (int i = 0; i < count; i++) {
        sum += temperatures[i];
        if (temperatures[i] < min) min = temperatures[i];
        if (temperatures[i] > max) max = temperatures[i];
    }

    float average = sum / count;
    printf("\nTemperature Statistics:\n");
    printf("Average Temperature: %.2f\n", average);
    printf("Minimum Temperature: %.2f\n", min);
    printf("Maximum Temperature: %.2f\n", max);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    float temperatures[MAX_READINGS];
    int count = 0;
    
    printf("Temperature Monitoring System.\n");
    printf("Monitoring the temperature every second...\n");

    // Start temperature monitoring loop
    while (1) {
        float current_temp = generate_random_temp();
        temperatures[count] = current_temp;
        count++;
        
        printf("Current Temperature Reading: %.2f\n", current_temp);
        log_temperature(current_temp);
        check_threshold(current_temp);

        // Display statistics after every 10 readings
        if (count >= 10) {
            display_statistics(temperatures, count);
            count = 0; // Reset count after displaying statistics
        }

        // Sleep for 1 second before next reading
        sleep(1);
    }
    
    return 0;
}