//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) / 1.8;
}

// Function to get the current temperature in Celsius
double get_current_temperature_in_celsius() {
    char temperature_string[100];
    FILE *temperature_file = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    fgets(temperature_string, sizeof(temperature_string), temperature_file);
    fclose(temperature_file);
    return (double)atof(temperature_string);
}

// Function to get the current temperature in Fahrenheit
double get_current_temperature_in_fahrenheit() {
    return celsius_to_fahrenheit(get_current_temperature_in_celsius());
}

// Function to display temperature in Celsius
void display_temperature_in_celsius() {
    double temperature_in_celsius = get_current_temperature_in_celsius();
    printf("Current temperature: %.2lf degrees Celsius\n", temperature_in_celsius);
}

// Function to display temperature in Fahrenheit
void display_temperature_in_fahrenheit() {
    double temperature_in_fahrenheit = get_current_temperature_in_fahrenheit();
    printf("Current temperature: %.2lf degrees Fahrenheit\n", temperature_in_fahrenheit);
}

// Function to monitor the temperature every second
void monitor_temperature() {
    while (1) {
        display_temperature_in_celsius();
        display_temperature_in_fahrenheit();
        sleep(1);
    }
}

int main() {
    monitor_temperature();
    return 0;
}