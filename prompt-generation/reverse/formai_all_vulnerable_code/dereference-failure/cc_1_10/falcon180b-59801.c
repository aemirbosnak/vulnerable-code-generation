//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char *argv[]) {
    int fd;
    struct termios options;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return 1;
    }

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (tcgetattr(fd, &options)!= 0) {
        perror("tcgetattr");
        return 1;
    }

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("tcsetattr");
        return 1;
    }

    write(fd, argv[1], strlen(argv[1]));
    write(fd, "\r", 1);

    close(fd);

    return 0;
}