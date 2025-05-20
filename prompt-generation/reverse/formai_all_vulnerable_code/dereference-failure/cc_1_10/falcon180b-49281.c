//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main()
{
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the serial port options
    options.c_cflag = CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    // Set the serial port options
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting serial port options: %s\n", strerror(errno));
        exit(1);
    }

    // Send a command to the drone
    char command[] = "takeoff\r";
    write(fd, command, strlen(command));

    // Read the drone's response
    char response[100];
    memset(response, 0, sizeof(response));
    read(fd, response, sizeof(response));
    printf("Drone response: %s\n", response);

    // Close the serial port
    close(fd);

    return 0;
}