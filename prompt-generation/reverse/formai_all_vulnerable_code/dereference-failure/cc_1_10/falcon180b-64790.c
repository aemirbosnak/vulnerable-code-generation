//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/select.h>

#define BAUDRATE B115200
#define DEV_PATH "/dev/ttyACM0"
#define BUF_SIZE 1024

int main() {
    int fd;
    struct termios options;
    fd_set readfds;
    char readbuf[BUF_SIZE];
    int retval;

    fd = open(DEV_PATH, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Error opening serial port");
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        perror("Error getting serial port attributes");
        exit(1);
    }

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("Error setting serial port attributes");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    while (1) {
        retval = select(fd + 1, &readfds, NULL, NULL, NULL);
        if (retval == -1) {
            perror("Error with select");
            exit(1);
        } else if (retval > 0) {
            retval = read(fd, readbuf, BUF_SIZE);
            if (retval > 0) {
                write(STDOUT_FILENO, readbuf, retval);
            } else if (retval == 0) {
                printf("Connection closed\n");
                close(fd);
                exit(0);
            } else {
                perror("Error reading from serial port");
                exit(1);
            }
        }
    }

    return 0;
}