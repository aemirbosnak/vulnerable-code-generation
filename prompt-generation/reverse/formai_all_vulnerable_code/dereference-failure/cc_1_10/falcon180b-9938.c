//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/select.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE_PATH "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;
    fd_set read_fds;
    char buffer[1024];

    fd = open(DEVICE_PATH, O_RDWR | O_NONBLOCK);
    if (fd < 0) {
        printf("Failed to open device %s: %s\n", DEVICE_PATH, strerror(errno));
        return 1;
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    tcsetattr(fd, TCSANOW, &options);

    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    while (1) {
        int select_result;
        select_result = select(fd + 1, &read_fds, NULL, NULL, NULL);

        if (select_result < 0) {
            printf("Failed to select: %s\n", strerror(errno));
            break;
        }

        if (FD_ISSET(fd, &read_fds)) {
            int bytes_read;
            bytes_read = read(fd, buffer, sizeof(buffer));

            if (bytes_read < 0) {
                printf("Failed to read from device: %s\n", strerror(errno));
                break;
            }

            buffer[bytes_read] = '\0';
            printf("%s", buffer);
        }
    }

    close(fd);
    return 0;
}