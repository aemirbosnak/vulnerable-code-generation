//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TEMP_SENSOR_FILE "/sys/class/thermal/thermal_zone0/temp"
#define WARNING_TEMP 75000 // in millidegrees Celsius (75.0°C)
#define CRITICAL_TEMP 85000 // in millidegrees Celsius (85.0°C)

float read_temperature() {
    FILE *file = fopen(TEMP_SENSOR_FILE, "r");
    if (file == NULL) {
        perror("Failed to open temperature sensor file");
        exit(EXIT_FAILURE);
    }

    int temp_milli_celsius;
    fscanf(file, "%d", &temp_milli_celsius);
    fclose(file);
    
    return temp_milli_celsius / 1000.0; // Convert to Celsius
}

void log_temperature(float temperature) {
    FILE *log_file = fopen("temperature_log.txt", "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    // Remove the newline character
    time_str[strlen(time_str) - 1] = '\0';

    fprintf(log_file, "[%s] Temperature: %.2f °C\n", time_str, temperature);
    fclose(log_file);
}

void alert_user(float temperature) {
    if (temperature >= CRITICAL_TEMP / 1000.0) {
        printf("CRITICAL ALERT! Temperature reached %.2f °C!\n", temperature);
    } else if (temperature >= WARNING_TEMP / 1000.0) {
        printf("Warning! Temperature is high: %.2f °C.\n", temperature);
    }
}

int main() {
    printf("Temperature Monitor Started...\n");
    while (1) {
        float current_temperature = read_temperature();
        log_temperature(current_temperature);
        alert_user(current_temperature);
        sleep(5); // Wait for 5 seconds before checking again
    }
    
    return 0; // This line will never be reached
}