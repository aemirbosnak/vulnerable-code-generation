//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMPERATURES 100
#define MIN_TEMPERATURES 0
#define INVALID_TEMPERATURE -9999

typedef struct {
    int id;
    char name[50];
    int temperature;
    time_t timestamp;
} Temperature;

int main() {
    int numTemperatures = 0;
    Temperature temperatures[MAX_TEMPERATURES];
    int temperatureId = 1;
    FILE *configFile;
    char line[100];
    char *token;

    // Read configuration file
    configFile = fopen("config.txt", "r");
    if (configFile == NULL) {
        printf("Error: Unable to open configuration file.\n");
        return 1;
    }
    while (fgets(line, 100, configFile)!= NULL) {
        token = strtok(line, ",");
        strcpy(temperatures[numTemperatures].name, token);
        temperatures[numTemperatures].id = temperatureId++;
        numTemperatures++;
    }
    fclose(configFile);

    // Initialize temperatures to invalid value
    for (int i = 0; i < numTemperatures; i++) {
        temperatures[i].temperature = INVALID_TEMPERATURE;
    }

    // Main loop
    while (1) {
        for (int i = 0; i < numTemperatures; i++) {
            // Read temperature sensor
            int temperature = readTemperature(i);
            if (temperature!= INVALID_TEMPERATURE) {
                // Update temperature and timestamp
                temperatures[i].temperature = temperature;
                temperatures[i].timestamp = time(NULL);
            }
        }
        // Print temperatures
        printf("Temperature Monitor\n");
        for (int i = 0; i < numTemperatures; i++) {
            if (temperatures[i].temperature!= INVALID_TEMPERATURE) {
                printf("%s: %.2f°C (%s)\n", temperatures[i].name, (temperatures[i].temperature - 32) * 5/9, ctime(&temperatures[i].timestamp));
            }
        }
        sleep(5);
    }

    return 0;
}

int readTemperature(int temperatureId) {
    // TODO: Implement function to read temperature sensor
    // Return temperature in Celsius * 100 (e.g. 25.5°C = 255)
    // Return INVALID_TEMPERATURE if sensor is not connected or reading fails
    return INVALID_TEMPERATURE;
}