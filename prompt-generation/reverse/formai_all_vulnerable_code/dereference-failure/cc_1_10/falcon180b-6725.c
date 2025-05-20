//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    // Set the baud rate
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting baud rate: %s\n", strerror(errno));
        close(fd);
        return 1;
    }

    // Main loop
    while (1) {
        // Get user input
        char input[80];
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);

        // Trim whitespace
        input[strcspn(input, "\n")] = '\0';

        // Send command to drone
        if (write(fd, input, strlen(input))!= strlen(input)) {
            printf("Error writing to serial port: %s\n", strerror(errno));
            close(fd);
            return 1;
        }

        // Read response from drone
        char response[80];
        if (read(fd, response, sizeof(response)) <= 0) {
            printf("Error reading from serial port: %s\n", strerror(errno));
            close(fd);
            return 1;
        }

        // Print response
        printf("Response: %s\n", response);
    }

    close(fd);
    return 0;
}