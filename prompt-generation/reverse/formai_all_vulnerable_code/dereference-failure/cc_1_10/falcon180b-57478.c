//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#define BAUD B9600
#define DEV "/dev/ttyUSB0"

int main(int argc, char **argv) {
    int fd;
    struct termios options;
    char buf[100];
    int len;

    if ((fd = open(DEV, O_RDWR | O_NOCTTY)) == -1) {
        printf("Error opening %s: %s\n", DEV, strerror(errno));
        return 1;
    }

    if (tcgetattr(fd, &options) == -1) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return 1;
    }

    options.c_cflag = BAUD | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options) == -1) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        memset(buf, 0, sizeof(buf));
        len = read(fd, buf, sizeof(buf));

        if (len <= 0) {
            printf("Error reading from %s: %s\n", DEV, strerror(errno));
            break;
        }

        printf("Received: %s\n", buf);
    }

    close(fd);
    return 0;
}