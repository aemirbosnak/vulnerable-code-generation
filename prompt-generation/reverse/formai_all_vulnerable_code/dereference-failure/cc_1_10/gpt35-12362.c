//FormAI DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define minimum and maximum temperature values
#define MIN_TEMP 60
#define MAX_TEMP 100

// Function to generate a random temperature value
int generateTemperature() {
    int temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    return temp;
}

// Function to display the temperature readings
void displayTemperatures(int *temperatures, int numReadings) {
    printf("\n\tTemperature Readings (in Fahrenheit):\n");
    for (int i=0; i<numReadings; i++) {
        printf("\tReading %d: %dF\n", i+1, temperatures[i]);
    }
}

int main() {
    printf("Welcome to the Temperature Monitor!\n");

    // Define variables
    int numReadings;
    int *temperatures;

    // Get the number of readings from the user
    printf("How many temperature readings would you like to take?: ");
    scanf("%d", &numReadings);

    // Allocate memory to store the temperature readings
    temperatures = (int *)malloc(numReadings * sizeof(int));

    // Generate and store the temperature readings
    for (int i=0; i<numReadings; i++) {
        int temp = generateTemperature();
        temperatures[i] = temp;
        printf("Reading %d: %dF\n", i+1, temp);
    }

    // Display the temperature readings
    displayTemperatures(temperatures, numReadings);

    // Free up the memory allocated to temperatures
    free(temperatures);

    printf("\nThank you for using the Temperature Monitor!\n");

    return 0;
}