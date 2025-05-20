//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROOM_NAME "Living Room"
#define MAX_TEMPERATURE 30.0
#define MIN_TEMPERATURE 15.0
#define CHECK_INTERVAL 5 // seconds

void log_temperature(float temp, const char* room) {
    FILE *file = fopen("temperature_log.txt", "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // remove newline

    fprintf(file, "[%s] %s: Temperature = %.2f°C\n", time_str, room, temp);
    fclose(file);
}

float get_random_temperature() {
    // Simulate temperature fluctuations
    return (float)(rand() % 2000 - 1000) / 100.0; // Range from -10.00 to +10.00
}

void check_temperature(float temp) {
    if (temp > MAX_TEMPERATURE) {
        printf("Alert: The temperature in %s is too high (%.2f°C)!\n", ROOM_NAME, temp);
    } else if (temp < MIN_TEMPERATURE) {
        printf("Alert: The temperature in %s is too low (%.2f°C)!\n", ROOM_NAME, temp);
    } else {
        printf("Temperature in %s is okay (%.2f°C).\n", ROOM_NAME, temp);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    printf("Temperature Monitor for %s\n", ROOM_NAME);
    printf("Monitoring temperature every %d seconds...\n", CHECK_INTERVAL);

    while (1) {
        float current_temperature = get_random_temperature();

        log_temperature(current_temperature, ROOM_NAME);
        check_temperature(current_temperature);
        
        sleep(CHECK_INTERVAL); // wait for the specified interval
    }

    return 0;
}