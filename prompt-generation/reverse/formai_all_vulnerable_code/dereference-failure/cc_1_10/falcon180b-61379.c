//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE_NAME "/dev/ttyUSB0"

int main(int argc, char *argv[]) {
    int fd;
    struct termios options;
    char *device_name = DEVICE_NAME;
    int baudrate = BAUDRATE;
    int i, c;

    fd = open(device_name, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        fprintf(stderr, "Error opening %s: %s\n", device_name, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        fprintf(stderr, "Error getting attributes for %s: %s\n", device_name, strerror(errno));
        exit(1);
    }

    cfsetispeed(&options, baudrate);
    cfsetospeed(&options, baudrate);

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        fprintf(stderr, "Error setting attributes for %s: %s\n", device_name, strerror(errno));
        exit(1);
    }

    while (1) {
        printf("Enter command: ");
        fflush(stdout);
        if (read(fd, &c, 1)!= 1) {
            fprintf(stderr, "Error reading from %s: %s\n", device_name, strerror(errno));
            exit(1);
        }
        printf("You entered: %c\n", c);
        usleep(100000);
    }

    return 0;
}