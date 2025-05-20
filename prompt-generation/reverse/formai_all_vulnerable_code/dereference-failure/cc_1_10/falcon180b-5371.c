//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define TIMEOUT 1
#define DEV_TTYS0 "/dev/ttyS0"

int main()
{
    int fd;
    struct termios options;

    fd = open(DEV_TTYS0, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0)
    {
        printf("Error opening %s - %s\n", DEV_TTYS0, strerror(errno));
        return 1;
    }

    if (tcgetattr(fd, &options) < 0)
    {
        printf("Error getting attributes of %s - %s\n", DEV_TTYS0, strerror(errno));
        return 1;
    }

    // Set baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set timeouts
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = TIMEOUT;

    // Set input mode
    options.c_iflag = IGNPAR;

    // Set output mode
    options.c_oflag = 0;

    // Set control mode
    options.c_cflag = CS8 | CREAD | CLOCAL;

    // Set local mode
    options.c_lflag = 0;

    if (tcsetattr(fd, TCSANOW, &options) < 0)
    {
        printf("Error setting attributes of %s - %s\n", DEV_TTYS0, strerror(errno));
        return 1;
    }

    char cmd[2];
    cmd[0] = 'A';
    cmd[1] = '\0';

    write(fd, cmd, strlen(cmd));

    sleep(2);

    char cmd2[2];
    cmd2[0] = 'B';
    cmd2[1] = '\0';

    write(fd, cmd2, strlen(cmd2));

    close(fd);

    return 0;
}