//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyS0"

void setup_serial_port(int fd) {
    struct termios options;
    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 10;

    tcsetattr(fd, TCSANOW, &options);
}

int main() {
    int fd;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0) {
        printf("Error opening serial port: %s\n", strerror(errno));
        return 1;
    }

    setup_serial_port(fd);

    while (1) {
        char input;
        read(fd, &input, 1);

        if (input == 'f') {
            printf("Drone flying forward\n");
        } else if (input == 'b') {
            printf("Drone flying backward\n");
        } else if (input == 'l') {
            printf("Drone flying left\n");
        } else if (input == 'r') {
            printf("Drone flying right\n");
        } else if (input =='s') {
            printf("Drone stop\n");
        }
    }

    close(fd);
    return 0;
}