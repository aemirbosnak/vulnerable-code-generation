//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyS0"

int main(int argc, char *argv[])
{
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1)
    {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0)
    {
        printf("Error tcgetattr: %s\n", strerror(errno));
        exit(1);
    }

    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;

    options.c_cflag |= CLOCAL | CREAD;

    options.c_iflag = IGNPAR;

    options.c_oflag = 0;

    options.c_lflag = 0;

    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 5;

    if (tcsetattr(fd, TCSANOW, &options)!= 0)
    {
        printf("Error tcsetattr: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[1024];

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));

        int n = read(fd, buffer, sizeof(buffer));

        if (n > 0)
        {
            printf("Received: %s\n", buffer);
        }
    }

    close(fd);

    return 0;
}