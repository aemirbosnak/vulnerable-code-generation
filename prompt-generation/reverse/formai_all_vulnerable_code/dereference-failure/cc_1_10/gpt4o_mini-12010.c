//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 20

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void getInput(char *buffer, size_t size);
int validateInput(const char *input);

int main() {
    int choice;
    char input[MAX_INPUT_SIZE];
    float temperature, convertedTemperature;

    // Display the menu for users
    displayMenu();

    // Loop until the user chooses to exit
    while (1) {
        printf("Choose an option (1-3): ");
        getInput(input, sizeof(input));

        // Validate user input
        choice = atoi(input);
        if (choice < 1 || choice > 3) {
            printf("Invalid choice, please try again.\n");
            continue;
        } else if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Get temperature input from user
        printf("Enter the temperature: ");
        getInput(input, sizeof(input));

        // Validate temperature input
        if (!validateInput(input)) {
            printf("Invalid temperature input. Please enter a numeric value.\n");
            continue;
        }

        temperature = atof(input);

        // Perform the appropriate conversion based on choice
        if (choice == 1) {
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, convertedTemperature);
        } else {
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, convertedTemperature);
        }

        // Loop back for another conversion
        printf("\n");
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Temperature Converter!\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to get input from user
void getInput(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove newline character from input
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

// Function to validate if the input is a number
int validateInput(const char *input) {
    char *endptr;
    strtof(input, &endptr);
    return endptr != input && *endptr == '\0';
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}