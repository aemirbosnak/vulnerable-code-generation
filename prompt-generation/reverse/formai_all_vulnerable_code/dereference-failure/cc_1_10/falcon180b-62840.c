//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <errno.h>
#include <time.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int fd;
struct termios options;
fd_set readfds;
char buffer[1024];

void init_serial(void)
{
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    if (fcntl(fd, F_SETFL, O_RDWR) == -1) {
        printf("Error setting flags on %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    tcgetattr(fd, &options);

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cflag |= CREAD;
    options.c_cflag |= CLOCAL;

    tcsetattr(fd, TCSANOW, &options);
}

void send_command(char *cmd)
{
    int n;

    n = strlen(cmd);
    write(fd, cmd, n);
}

int main(int argc, char *argv[])
{
    init_serial();

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        select(fd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(fd, &readfds)) {
            memset(buffer, 0, sizeof(buffer));
            int n = read(fd, buffer, sizeof(buffer));

            if (n <= 0) {
                printf("Error reading from %s: %s\n", DEVICE, strerror(errno));
                exit(1);
            }

            printf("Received: %s", buffer);
        }
    }

    return 0;
}