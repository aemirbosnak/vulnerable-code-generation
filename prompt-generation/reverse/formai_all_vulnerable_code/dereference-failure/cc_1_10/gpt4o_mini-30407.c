//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void displayMenu() {
    printf("Temperature Converter\n");
    printf("----------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
    printf("----------------------\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheitToCelsius(fahrenheit) + 273.15);
}

float kelvinToFahrenheit(float kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

float getInput() {
    char input[MAX_INPUT_LENGTH];
    float value = 0;
    
    while (1) {
        printf("Enter temperature: ");
        
        // Read user input safely
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Remove newline character if present
            input[strcspn(input, "\n")] = 0;  
            
            // Attempt to convert input to float
            char *endptr;
            value = strtof(input, &endptr);
            
            // Check if the conversion was successful
            if (endptr != input && *endptr == '\0') {
                break; // Successful conversion
            } else {
                printf("Invalid input. Please enter a numeric value.\n");
            }
        }
    }
    return value;
}

int main() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        displayMenu();
        
        printf("Select an option (0 to exit): ");
        scanf("%d", &choice);
        while(getchar() != '\n');  // Clear the input buffer
        
        switch (choice) {
            case 1: // Celsius to Fahrenheit
                printf("Celsius: ");
                temperature = getInput();
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2: // Fahrenheit to Celsius
                printf("Fahrenheit: ");
                temperature = getInput();
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 3: // Celsius to Kelvin
                printf("Celsius: ");
                temperature = getInput();
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 4: // Kelvin to Celsius
                printf("Kelvin: ");
                temperature = getInput();
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 5: // Fahrenheit to Kelvin
                printf("Fahrenheit: ");
                temperature = getInput();
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 6: // Kelvin to Fahrenheit
                printf("Kelvin: ");
                temperature = getInput();
                convertedTemperature = kelvinToFahrenheit(temperature);
                printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 0: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}