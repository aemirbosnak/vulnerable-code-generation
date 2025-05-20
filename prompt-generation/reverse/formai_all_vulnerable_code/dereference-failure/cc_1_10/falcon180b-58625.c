//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/time.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;
    fd_set readfds;

    if((fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY)) == -1) {
        perror("open");
        exit(1);
    }

    if(tcgetattr(fd, &options)!= 0) {
        perror("tcgetattr");
        exit(1);
    }

    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_iflag &= ~IGNBRK;
    options.c_oflag &= ~OPOST;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if(tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("tcsetattr");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    while(1) {
        int retval;

        retval = select(fd + 1, &readfds, NULL, NULL, NULL);

        if(retval == -1) {
            perror("select");
            exit(1);
        }

        if(FD_ISSET(fd, &readfds)) {
            char buffer[1024];
            int bytes_read;

            bytes_read = read(fd, buffer, sizeof(buffer));

            if(bytes_read > 0) {
                printf("Received: %s\n", buffer);
            } else {
                perror("read");
                exit(1);
            }
        }
    }

    return 0;
}