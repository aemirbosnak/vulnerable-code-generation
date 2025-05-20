//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>

#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyUSB0"
#define MAX_SPEED 127
#define MIN_SPEED 1
#define TURN_LEFT 'a'
#define TURN_RIGHT 'd'
#define FORWARD 'w'
#define BACKWARD's'
#define STOP 'x'

int main(int argc, char *argv[]) {
    int fd, n;
    struct termios options;
    char command;

    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", MODEMDEVICE, strerror(errno));
        return 1;
    }

    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);
    options.c_cflag |= (CS8 | CREAD | CLOCAL);
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        command = getchar();
        switch (command) {
            case FORWARD:
                printf("Moving forward\n");
                write(fd, "f", 1);
                break;
            case BACKWARD:
                printf("Moving backward\n");
                write(fd, "b", 1);
                break;
            case TURN_LEFT:
                printf("Turning left\n");
                write(fd, "l", 1);
                break;
            case TURN_RIGHT:
                printf("Turning right\n");
                write(fd, "r", 1);
                break;
            case STOP:
                printf("Stopping\n");
                write(fd, "x", 1);
                break;
            default:
                printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}