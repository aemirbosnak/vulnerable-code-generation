//FormAI DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"
#define TEMP_LOW_THRESHOLD 50
#define TEMP_HIGH_THRESHOLD 85

int main(void) {
    // Open the temperature file
    FILE* temp_file_descriptor = fopen(TEMP_FILE, "r");
    if(temp_file_descriptor == NULL) {
        printf("Failed to open temperature file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // Read the temperature value
    char temp_string[10];
    if(fgets(temp_string, 10, temp_file_descriptor) == NULL) {
        printf("Failed to read temperature: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // Close the temperature file
    if(fclose(temp_file_descriptor) != 0) {
        printf("Failed to close temperature file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // Convert temperature to integer
    int temperature = atoi(temp_string) / 1000;
    
    // Check if temperature is within acceptable range
    bool is_temp_ok = true;
    if(temperature < TEMP_LOW_THRESHOLD) {
        printf("Warning: Temperature is too low (Below %d degrees C)\n", TEMP_LOW_THRESHOLD);
        is_temp_ok = false;
    }
    else if(temperature > TEMP_HIGH_THRESHOLD) {
        printf("Warning: Temperature is too high (Above %d degrees C)\n", TEMP_HIGH_THRESHOLD);
        is_temp_ok = false;
    }
    
    // Print the current temperature
    printf("Current Temperature: %d degrees C\n", temperature);
    
    // Warn if temperature is not within acceptable range
    if(!is_temp_ok) {
        printf("Please take appropriate action to cool down or warm up the system.\n");
    }
    
    return EXIT_SUCCESS;
}