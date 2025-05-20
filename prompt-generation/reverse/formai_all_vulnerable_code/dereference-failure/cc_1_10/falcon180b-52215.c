//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B115200
#define DEV_TTYS0 "/dev/ttyS0"

int fd;
struct termios options;
char buffer[100];

void init_serial() {
    fd = open(DEV_TTYS0, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEV_TTYS0, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        exit(1);
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(PARENB | PARODD);
    options.c_cflag |= CS8;
    options.c_cflag &= ~CRTSCTS;
    options.c_cc[VTIME] = 5;
    options.c_cc[VMIN] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        exit(1);
    }
}

int main() {
    init_serial();

    while (1) {
        int nbytes;

        nbytes = read(fd, buffer, sizeof(buffer));
        if (nbytes > 0) {
            buffer[nbytes] = '\0';
            printf("Received: %s\n", buffer);
        }

        usleep(100000);
    }

    return 0;
}