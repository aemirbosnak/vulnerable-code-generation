//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    memset(&options, 0, sizeof(struct termios));

    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VTIME] = 5;
    options.c_cc[VMIN] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting attributes for %s: %s\n", DEVICE, strerror(errno));
        return 2;
    }

    while (1) {
        char buffer[1024];
        int bytes_read = read(fd, buffer, sizeof(buffer));

        if (bytes_read <= 0) {
            printf("Error reading from %s: %s\n", DEVICE, strerror(errno));
            break;
        }

        buffer[bytes_read] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(fd);
    return 0;
}