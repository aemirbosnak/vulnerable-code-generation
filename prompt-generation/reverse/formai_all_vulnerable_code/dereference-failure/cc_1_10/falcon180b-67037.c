//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
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

    // Set the baud rate, character size, etc.
    tcgetattr(fd, &options);
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    tcsetattr(fd, TCSANOW, &options);

    // Loop to send and receive data
    while (1) {
        // Send a command to turn on the light
        char command[] = "ON\r";
        write(fd, command, strlen(command));

        // Read the response from the light
        char response[100];
        memset(response, 0, sizeof(response));
        int bytes_read = read(fd, response, sizeof(response));
        if (bytes_read > 0) {
            printf("Response: %s\n", response);
        } else {
            printf("Error reading from %s: %s\n", DEVICE, strerror(errno));
        }

        // Wait for 1 second before turning off the light
        sleep(1);

        // Send a command to turn off the light
        char command_off[] = "OFF\r";
        write(fd, command_off, strlen(command_off));

        // Read the response from the light
        memset(response, 0, sizeof(response));
        bytes_read = read(fd, response, sizeof(response));
        if (bytes_read > 0) {
            printf("Response: %s\n", response);
        } else {
            printf("Error reading from %s: %s\n", DEVICE, strerror(errno));
        }

        // Wait for 1 second before turning on the light again
        sleep(1);
    }

    // Close the serial port
    close(fd);
    return 0;
}