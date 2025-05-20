//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main()
{
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY);
    if (fd == -1)
    {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    // Get the current options for the port
    if (tcgetattr(fd, &options)!= 0)
    {
        printf("Error tcgetattr: %s\n", strerror(errno));
        exit(1);
    }

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the options
    options.c_cflag |= CREAD | CLOCAL;
    options.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
    options.c_cflag |= CS8;
    options.c_iflag |= IGNPAR;
    options.c_oflag = 0;

    // Set the new options
    if (tcsetattr(fd, TCSANOW, &options)!= 0)
    {
        printf("Error tcsetattr: %s\n", strerror(errno));
        exit(1);
    }

    // Main loop
    while (1)
    {
        // Read a character from the serial port
        char c = getchar();

        // Write the character to the serial port
        write(fd, &c, 1);
    }

    // Close the serial port
    close(fd);

    return 0;
}