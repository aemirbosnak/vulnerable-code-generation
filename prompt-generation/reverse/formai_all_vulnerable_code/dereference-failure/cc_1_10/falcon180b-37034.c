//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyUSB0"
#define BUFFER_SIZE 100

int main() {
    int fd, n;
    char buffer[BUFFER_SIZE];
    struct termios options;

    // Open the serial port
    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening serial port: %s\n", strerror(errno));
        return 1;
    }

    // Set up the serial port options
    memset(&options, 0, sizeof(options));
    options.c_cflag = CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VTIME] = 5; // 0.5 second read timeout
    options.c_cc[VMIN] = 0;

    tcsetattr(fd, TCSANOW, &options);

    // Loop forever, reading and writing to the serial port
    while (1) {
        // Read data from the serial port
        n = read(fd, buffer, BUFFER_SIZE);
        if (n == -1) {
            printf("Error reading from serial port: %s\n", strerror(errno));
            break;
        }

        // Write the data back to the serial port
        write(fd, buffer, n);
    }

    // Close the serial port
    close(fd);

    return 0;
}