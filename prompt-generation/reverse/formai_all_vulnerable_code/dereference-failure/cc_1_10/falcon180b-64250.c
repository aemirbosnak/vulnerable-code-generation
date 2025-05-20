//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char *argv[]) {
    int fd;
    struct termios options;

    if (argc!= 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    tcgetattr(fd, &options);

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cflag |= CREAD;
    options.c_cflag |= CLOCAL;

    options.c_iflag |= IGNPAR;

    options.c_oflag = 0;

    tcsetattr(fd, TCSANOW, &options);

    write(fd, argv[1], strlen(argv[1]));
    write(fd, "\r", 1);

    close(fd);

    return 0;
}