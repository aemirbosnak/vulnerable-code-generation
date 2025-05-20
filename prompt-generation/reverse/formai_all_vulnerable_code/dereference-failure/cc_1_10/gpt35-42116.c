//FormAI DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_TEMP 70 // Threshold temperature in Celsius degrees

int get_cpu_temperature() {
    int temperature = 0;
    int fd = open(TEMP_PATH, O_RDONLY);

    if (fd < 0) {
        printf("Error opening the temperature file.\n");
        return -1;
    }

    char buffer[6];
    read(fd, buffer, sizeof(buffer));
    temperature = atoi(buffer);

    close(fd);

    return temperature;
}

int main() {
    while(1) {
        int temp = get_cpu_temperature();

        if(temp < 0) {
            printf("Temperature reading failed.\n");
        }
        else {
            float temp_celsius = (float)temp / 1000;

            printf("CPU Temperature: %.2fC\n", temp_celsius);

            if(temp_celsius > MAX_TEMP) {
                printf("The temperature is too high! Shutting down the system...\n");
                // Insert code to safely shutdown the system here
            }
        }

        sleep(1); // Wait for 1 second before getting the temperature again
    }

    return 0;
}