//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUD B115200
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char *argv[]) {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    // Get the current options for the port
    if (tcgetattr(fd, &options)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return 1;
    }

    // Set the baud rate
    cfsetispeed(&options, BAUD);
    cfsetospeed(&options, BAUD);

    // Set the data format
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    // Set the parity
    options.c_cflag &= ~PARENB;

    // Set the number of stop bits
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= CSTOPB;

    // Set the input mode
    options.c_iflag = IGNPAR;

    // Set the output mode
    options.c_oflag = 0;

    // Set the control mode
    options.c_cflag |= CLOCAL | CREAD;

    // Set the local mode
    options.c_lflag = 0;

    // Set the new options for the port
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        return 1;
    }

    // Main loop
    while (1) {
        // Read a byte from the port
        char c = getchar();

        // Send the byte to the drone
        write(fd, &c, 1);
    }

    return 0;
}