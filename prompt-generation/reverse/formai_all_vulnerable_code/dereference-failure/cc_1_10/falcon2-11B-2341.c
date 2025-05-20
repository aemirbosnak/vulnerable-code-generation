//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

// Constants
#define BUF_SIZE 32

// Structure to hold sensor readings
struct sensor_reading {
    int value;
    char units[4];
};

// Function to read from the temperature sensor
struct sensor_reading read_sensor() {
    struct sensor_reading reading;
    int fd = open("/dev/sensors", O_RDONLY);
    if (fd == -1) {
        printf("Error opening sensor: %s\n", strerror(errno));
        return reading;
    }

    if (read(fd, &reading, sizeof(struct sensor_reading))!= sizeof(struct sensor_reading)) {
        printf("Error reading from sensor: %s\n", strerror(errno));
        return reading;
    }

    close(fd);
    return reading;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return celsius * 9/5 + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    struct sensor_reading reading = read_sensor();

    if (reading.value == 0) {
        printf("No reading available\n");
        return 1;
    }

    double fahrenheit = celsius_to_fahrenheit(reading.value);
    double celsius = fahrenheit_to_celsius(fahrenheit);

    printf("Current temperature: %s%s %s\n", reading.units, reading.value, celsius < 0? "C" : "F");

    return 0;
}