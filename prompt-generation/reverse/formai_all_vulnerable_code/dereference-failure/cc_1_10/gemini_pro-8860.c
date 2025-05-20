//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize some global variables
float temperature = 0.0;
char *units = "Celsius";
char *location = "Silicon Valley";

// Function to get the temperature from the user
float get_temperature() {
  float temp;
  printf("Enter the temperature in %s: ", units);
  scanf("%f", &temp);
  return temp;
}

// Function to display the temperature
void display_temperature(float temp) {
  printf("The temperature in %s is: %.1f %s\n", location, temp, units);
}

// Function to convert the temperature from Celsius to Fahrenheit
float convert_to_fahrenheit(float temp) {
  return (temp * 1.8) + 32;
}

// Function to convert the temperature from Fahrenheit to Celsius
float convert_to_celsius(float temp) {
  return (temp - 32) / 1.8;
}

// Function to change the units of measurement
void change_units() {
  char *new_units;
  printf("Enter the new units of measurement (Celsius/Fahrenheit): ");
  scanf("%s", &new_units);
  if (strcmp(new_units, "Celsius") == 0) {
    units = "Celsius";
    temperature = convert_to_celsius(temperature);
  } else if (strcmp(new_units, "Fahrenheit") == 0) {
    units = "Fahrenheit";
    temperature = convert_to_fahrenheit(temperature);
  } else {
    printf("Invalid units of measurement. Please enter Celsius or Fahrenheit.\n");
  }
}

// Function to change the location
void change_location() {
  char *new_location;
  printf("Enter the new location: ");
  scanf("%s", &new_location);
  location = new_location;
}

// Function to simulate a temperature change
void simulate_temperature_change() {
  // Generate a random temperature change between -2 and 2 degrees
  float temp_change = (rand() % 4) - 2;
  temperature += temp_change;
}

// Main function
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Get the initial temperature from the user
  temperature = get_temperature();

  // Display the temperature
  display_temperature(temperature);

  // Loop forever, allowing the user to change the units, location, or simulate a temperature change
  while (1) {
    char choice;
    printf("\nChoose an option:\n");
    printf("1. Change units\n");
    printf("2. Change location\n");
    printf("3. Simulate temperature change\n");
    printf("4. Exit\n");
    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        change_units();
        break;
      case '2':
        change_location();
        break;
      case '3':
        simulate_temperature_change();
        display_temperature(temperature);
        break;
      case '4':
        exit(0);
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 4.\n");
        break;
    }
  }

  return 0;
}