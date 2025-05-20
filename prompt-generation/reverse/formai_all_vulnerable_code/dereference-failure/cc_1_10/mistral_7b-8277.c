//MISTRAL-7B DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

// Struct for RainbowTempSensor
typedef struct {
    int temperature;
    char color[10];
} RainbowTempSensor;

// Function to read temperature from RainbowTempSensor
int read_temperature(void *sensor_addr) {
    RainbowTempSensor *sensor = (RainbowTempSensor *) sensor_addr;
    int temperature = sensor->temperature;
    return temperature;
}

// Function to set color of RainbowTempSensor LED based on temperature
void set_color(int temperature) {
    if (temperature < 10) {
        printf("\033[1;31m"); // Red
    } else if (temperature < 20) {
        printf("\033[1;32m"); // Orange
    } else if (temperature < 30) {
        printf("\033[1;33m"); // Yellow
    } else if (temperature < 40) {
        printf("\033[1;34m"); // Green
    } else if (temperature < 50) {
        printf("\033[1;35m"); // Blue
    } else {
        printf("\033[1;36m"); // Purple
    }
}

// Function to initialize RainbowTempSensor
void init_sensor(void *sensor_addr) {
    RainbowTempSensor *sensor = (RainbowTempSensor *) sensor_addr;
    sensor->temperature = 0;
}

int main() {
    void *sensor_addr;
    int fd;

    fd = open("/dev/rainbowtempsensor", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("Error opening RainbowTempSensor device file");
        exit(EXIT_FAILURE);
    }

    sensor_addr = mmap(NULL, sizeof(RainbowTempSensor), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (sensor_addr == MAP_FAILED) {
        perror("Error mapping RainbowTempSensor memory");
        exit(EXIT_FAILURE);
    }

    init_sensor(sensor_addr);

    while (1) {
        int temperature = read_temperature(sensor_addr);
        printf("Current temperature: %.2f degrees Celsius\n", temperature / 10.0);
        set_color(temperature);
        usleep(100000); // Delay for 0.1 seconds
    }

    munmap(sensor_addr, sizeof(RainbowTempSensor));
    close(fd);

    return EXIT_SUCCESS;
}