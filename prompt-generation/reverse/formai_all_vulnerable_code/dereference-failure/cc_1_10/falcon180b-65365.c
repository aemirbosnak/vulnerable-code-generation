//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE);
    options.c_cflag |= CS8;
    options.c_cflag &= ~(PARENB);
    options.c_cflag &= ~(CSTOPB);
    options.c_cflag &= ~(CRTSCTS);
    options.c_iflag |= (IGNBRK | IGNPAR);
    options.c_oflag = 0;
    options.c_lflag = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    printf("Serial port initialized.\n");

    while (1) {
        char input[100];
        int n;

        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);

        n = write(fd, input, strlen(input));
        if (n!= strlen(input)) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }

        memset(input, 0, sizeof(input));
        n = read(fd, input, sizeof(input));
        if (n <= 0) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }

        printf("Received data: %s", input);
    }

    return 0;
}