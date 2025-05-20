//FormAI DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    char* type;
    char* unit;
} Measurement;

// Function to convert pounds to kilograms
void lbs_to_kgs(Measurement* weight) {
    weight->value *= 0.45359237;
    weight->type = "Mass";
    weight->unit = "kg";
}

// Function to convert celsius to fahrenheit
void c_to_f(Measurement* temp) {
    temp->value = (temp->value * 1.8) + 32;
    temp->type = "Temperature";
    temp->unit = "F";
}

// Function to asynchronously convert the measurements
void async_convert(Measurement* measurements[], int num_measurements) {
    // Declare an array of function pointers
    void (*convert_functions[])(Measurement*) = {lbs_to_kgs, c_to_f};

    // Loop through each measurement
    for (int i = 0; i < num_measurements; i++) {
        // Generate a random number to select the conversion function
        int index = rand() % 2;

        // Call the selected conversion function asynchronously
        convert_functions[index](measurements[i]);

        // Print the converted measurement
        printf("%.2f %s converted to %s: %.2f %s\n", measurements[i]->value, measurements[i]->unit, measurements[i]->type, measurements[i]->value, measurements[i]->unit);
    }
}

int main() {
    // Create an array of measurements
    Measurement* measurements[5];

    // Allocate memory for each measurement
    for (int i = 0; i < 5; i++) {
        measurements[i] = malloc(sizeof(Measurement));
    }

    // Set the values for each measurement
    measurements[0]->value = 150.0;
    measurements[0]->type = "Mass";
    measurements[0]->unit = "lbs";

    measurements[1]->value = 20.0;
    measurements[1]->type = "Temperature";
    measurements[1]->unit = "C";

    measurements[2]->value = 75.0;
    measurements[2]->type = "Mass";
    measurements[2]->unit = "lbs";

    measurements[3]->value = 32.0;
    measurements[3]->type = "Temperature";
    measurements[3]->unit = "C";

    measurements[4]->value = 200.0;
    measurements[4]->type = "Mass";
    measurements[4]->unit = "lbs";

    // Call the async_convert function with the array of measurements
    async_convert(measurements, 5);

    // Free the memory for each measurement
    for (int i = 0; i < 5; i++) {
        free(measurements[i]);
    }

    return 0;
}