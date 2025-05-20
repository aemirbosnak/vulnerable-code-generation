//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"
#define TIMEOUT 1000

int fd;
struct termios options;

void setup_serial() {
    fd = open(DEVICE, O_RDWR | O_NOCTTY);
    if(fd < 0) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VTIME] = TIMEOUT / 100;
    options.c_cc[VMIN] = 0;

    if(tcsetattr(fd, TCSANOW, &options) < 0) {
        printf("Error setting serial options: %s\n", strerror(errno));
        exit(1);
    }
}

int main() {
    setup_serial();

    char buffer[1024];
    int bytes_read;

    while(1) {
        bytes_read = read(fd, buffer, sizeof(buffer));
        if(bytes_read <= 0) {
            printf("Error reading from serial port: %s\n", strerror(errno));
            break;
        }

        buffer[bytes_read] = 0;
        printf("%s", buffer);
    }

    close(fd);
    return 0;
}