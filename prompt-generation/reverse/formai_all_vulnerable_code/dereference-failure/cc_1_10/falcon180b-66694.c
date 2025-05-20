//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/serial.h>

#define BAUDRATE B9600
#define SERIAL_DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;
    char buffer[1024];
    int bytes_read;

    fd = open(SERIAL_DEVICE, O_RDWR);
    if (fd == -1) {
        printf("Error opening serial device: %s\n", strerror(errno));
        return 1;
    }

    if (tcgetattr(fd, &options)!= 0) {
        printf("Error getting serial device attributes: %s\n", strerror(errno));
        return 1;
    }

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting serial device attributes: %s\n", strerror(errno));
        return 1;
    }

    printf("Serial device initialized\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        bytes_read = read(fd, buffer, sizeof(buffer));

        if (bytes_read <= 0) {
            printf("Error reading from serial device: %s\n", strerror(errno));
            break;
        }

        printf("Received: %s", buffer);
    }

    close(fd);
    return 0;
}