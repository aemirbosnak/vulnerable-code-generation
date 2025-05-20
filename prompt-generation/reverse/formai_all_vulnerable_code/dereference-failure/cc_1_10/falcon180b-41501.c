//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEV_NAME "/dev/ttyUSB0"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    char buffer[BUFFER_SIZE];
    struct termios options;

    // Open the serial port
    fd = open(DEV_NAME, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        fprintf(stderr, "Error opening %s: %s\n", DEV_NAME, strerror(errno));
        exit(1);
    }

    // Get the current options for the serial port
    tcgetattr(fd, &options);

    // Set the baud rate, character size, parity, and stop bits
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);
    options.c_cflag |= CS8 | CREAD;
    options.c_cflag &= ~PARENB;
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
    options.c_oflag &= ~OPOST;

    // Set the input mode to raw
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    // Set the new options for the serial port
    tcsetattr(fd, TCSANOW, &options);

    // Read data from the serial port
    while (1) {
        int bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            fprintf(stderr, "Error reading from %s: %s\n", DEV_NAME, strerror(errno));
            exit(1);
        }

        if (bytes_read == 0) {
            fprintf(stderr, "Serial port closed\n");
            exit(1);
        }

        // Print the received data
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    // Close the serial port
    close(fd);
    return 0;
}