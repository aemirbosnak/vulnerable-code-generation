//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BAUDRATE B115200

int main(int argc, char **argv) {
    int fd;
    struct termios options;

    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        fprintf(stderr, "Error opening /dev/ttyUSB0: %s\n", strerror(errno));
        exit(1);
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNBRK;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options) == -1) {
        fprintf(stderr, "Error setting attributes for /dev/ttyUSB0: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[1024];
    while (1) {
        int bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            fprintf(stderr, "Error reading from /dev/ttyUSB0: %s\n", strerror(errno));
            exit(1);
        }

        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                printf("Received message: %s\n", buffer);
            }
        }
    }

    return 0;
}