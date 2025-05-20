//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return 1;
    }

    char *device = argv[1];

    int fd = open(device, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open device '%s': %s\n", device, strerror(errno));
        return 1;
    }

    struct termios options;
    if (tcgetattr(fd, &options) == -1) {
        fprintf(stderr, "Failed to get attributes: %s\n", strerror(errno));
        return 1;
    }

    options.c_cflag |= CREAD | CLOCAL;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    cfsetospeed(&options, B57600);
    cfsetispeed(&options, B57600);

    if (tcsetattr(fd, TCSANOW, &options) == -1) {
        fprintf(stderr, "Failed to set attributes: %s\n", strerror(errno));
        return 1;
    }

    char input[1024];
    while (1) {
        read(fd, input, sizeof(input));
        if (input[0] == 'A' && input[1] == 'T') {
            write(fd, "AT\r", 3);
            break;
        }
    }

    tcsetattr(fd, TCSANOW, &options);
    close(fd);
    return 0;
}