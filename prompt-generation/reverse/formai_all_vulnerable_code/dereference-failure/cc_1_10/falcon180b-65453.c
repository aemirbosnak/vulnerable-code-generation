//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char **argv) {
    int fd;
    struct termios options;
    char buffer[1024];
    int bytes_read;

    if (argc!= 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    fd = open(DEVICE, O_RDWR);
    if (fd == -1) {
        printf("Error opening device: %s\n", strerror(errno));
        return 1;
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options) == -1) {
        printf("Error setting options: %s\n", strerror(errno));
        return 1;
    }

    strcpy(buffer, argv[1]);
    strcat(buffer, "\r");

    write(fd, buffer, strlen(buffer));

    bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        printf("Error reading from device: %s\n", strerror(errno));
        return 1;
    }

    close(fd);

    printf("Response: %s\n", buffer);
    return 0;
}