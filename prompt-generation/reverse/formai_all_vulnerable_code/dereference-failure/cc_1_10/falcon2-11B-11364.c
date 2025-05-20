//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void handle_serial_data(int fd) {
    char buffer[BUFFER_SIZE];
    int n;

    n = read(fd, buffer, BUFFER_SIZE);

    if (n == -1) {
        printf("Error reading from serial port\n");
        return;
    }

    if (n == 0) {
        printf("Serial port disconnected\n");
        return;
    }

    if (strncmp(buffer, "on", n) == 0) {
        printf("Turning on lights\n");
        // code to turn on lights
    } else if (strncmp(buffer, "off", n) == 0) {
        printf("Turning off lights\n");
        // code to turn off lights
    } else if (strncmp(buffer, "brightness", n) == 0) {
        int brightness;
        char *endptr;

        brightness = strtol(buffer + n, &endptr, 10);

        if (endptr == buffer + n + strlen("brightness")) {
            printf("Invalid brightness level\n");
            return;
        }

        printf("Setting brightness to %d\n", brightness);
        // code to set brightness
    } else {
        printf("Invalid command\n");
    }
}

int main() {
    int fd, n;
    struct termios options;
    char *command;

    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NONBLOCK);

    if (fd == -1) {
        printf("Error opening serial port\n");
        return 1;
    }

    tcgetattr(fd, &options);
    cfmakeraw(&options);
    tcsetattr(fd, TCSANOW, &options);

    command = malloc(BUFFER_SIZE + 1);

    while (1) {
        n = read(fd, command, BUFFER_SIZE);

        if (n == 0) {
            printf("Serial port disconnected\n");
            return 0;
        }

        if (n == -1) {
            printf("Error reading from serial port\n");
            return 1;
        }

        handle_serial_data(fd);
    }

    free(command);

    return 0;
}