//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUD_RATE B115200
#define DEVICE_NAME "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    if ((fd = open(DEVICE_NAME, O_RDWR | O_NOCTTY | O_NDELAY)) == -1) {
        printf("Error opening %s: %s\n", DEVICE_NAME, strerror(errno));
        return 1;
    }

    // Get the current options for the serial port
    if (tcgetattr(fd, &options)!= 0) {
        printf("Error getting attributes for %s: %s\n", DEVICE_NAME, strerror(errno));
        return 1;
    }

    // Set the baud rate
    cfsetispeed(&options, BAUD_RATE);
    cfsetospeed(&options, BAUD_RATE);

    // Set the options for the serial port
    options.c_cflag |= CREAD | CLOCAL;
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_iflag |= IGNPAR;
    options.c_oflag &= ~OPOST;

    // Set the input mode to raw
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    // Set the new options for the serial port
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting attributes for %s: %s\n", DEVICE_NAME, strerror(errno));
        return 1;
    }

    // Main loop
    while (1) {
        // Read a byte from the serial port
        char c;
        if (read(fd, &c, 1)!= 1) {
            printf("Error reading from %s: %s\n", DEVICE_NAME, strerror(errno));
            return 1;
        }

        // Print the received byte
        printf("Received byte: %c\n", c);

        // Send a command to the drone
        char command[] = "takeoff";
        write(fd, command, strlen(command));

        // Wait for 1 second
        sleep(1);
    }

    // Close the serial port
    if (close(fd)!= 0) {
        printf("Error closing %s: %s\n", DEVICE_NAME, strerror(errno));
        return 1;
    }

    return 0;
}