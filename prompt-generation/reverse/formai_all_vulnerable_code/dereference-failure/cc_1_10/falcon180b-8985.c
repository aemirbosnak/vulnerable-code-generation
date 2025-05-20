//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyACM0"

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    if ((fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY)) == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    // Get the current options for the port
    if (tcgetattr(fd, &options)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return 1;
    }

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the options for the port
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
    options.c_cflag |= CS8;
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
    options.c_oflag &= ~OPOST;

    // Set the new options for the port
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        return 1;
    }

    // Main loop
    while (1) {
        // Read input from user
        char input[100];
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Send input to drone
        write(fd, input, strlen(input));

        // Read response from drone
        char response[100];
        memset(response, 0, sizeof(response));
        int bytes_read = read(fd, response, sizeof(response));

        // Print response
        printf("Response: %s\n", response);
    }

    // Close the serial port
    close(fd);
    return 0;
}