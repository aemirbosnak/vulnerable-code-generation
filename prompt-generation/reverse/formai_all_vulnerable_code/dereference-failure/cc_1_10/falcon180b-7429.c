//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY);

    if (fd < 0) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        exit(1);
    }

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while (1) {
        bytes_read = read(fd, buffer, sizeof(buffer));

        if (bytes_read <= 0) {
            printf("Error reading from %s: %s\n", DEVICE, strerror(errno));
            exit(1);
        }

        printf("Received: %s", buffer);
    }

    close(fd);
    return 0;
}