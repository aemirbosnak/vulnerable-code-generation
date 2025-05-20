//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 100.0
#define MIN_TEMP 0.0

int main() {
    float current_temp = 25.0;
    char user_input[20];
    time_t now;
    struct tm *current_time;

    while(1) {
        // Get user input
        printf("Enter a command (temp or quit): ");
        fgets(user_input, 20, stdin);

        // Check command and perform action
        if (strcmp(user_input, "temp\n") == 0) {
            // Generate random temperature change
            float temp_change = ((float) rand() / RAND_MAX) * 10 - 5;

            // Update current temperature
            current_temp += temp_change;

            // Check if temperature is out of bounds
            if (current_temp > MAX_TEMP || current_temp < MIN_TEMP) {
                printf("Temperature out of bounds!\n");
                exit(1);
            }

            // Get current time
            time(&now);
            current_time = localtime(&now);

            // Print updated temperature and time
            printf("Current temperature: %.2f degrees Celsius\n", current_temp);
            printf("Current time: %02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

        } else if (strcmp(user_input, "quit\n") == 0) {
            // Exit program
            printf("Exiting...\n");
            exit(0);

        } else {
            // Invalid command
            printf("Invalid command!\n");
        }
    }

    return 0;
}