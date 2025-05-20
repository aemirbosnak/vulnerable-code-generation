//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    if (tcgetattr(fd, &options)!= 0) {
        printf("Error getting attributes: %s\n", strerror(errno));
        return 1;
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= CREAD | CLOCAL;

    options.c_iflag &= ~(IXON | IXOFF | IXANY);

    options.c_oflag &= ~OPOST;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        char ch;
        read(fd, &ch, 1);
        printf("%c", ch);
    }

    close(fd);
    return 0;
}