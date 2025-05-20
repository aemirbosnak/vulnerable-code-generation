//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char *argv[]) {
    int fd;
    struct termios options;
    char buf[64];
    int nbytes;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
    options.c_cflag |= CS8;

    options.c_iflag = IGNPAR;
    options.c_oflag = 0;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        printf("Enter command: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\r\n")] = '\0';

        nbytes = write(fd, buf, strlen(buf));
        if (nbytes!= strlen(buf)) {
            printf("Error writing to %s: %s\n", DEVICE, strerror(errno));
            exit(1);
        }

        usleep(100000);

        nbytes = read(fd, buf, sizeof(buf));
        if (nbytes <= 0) {
            printf("Error reading from %s: %s\n", DEVICE, strerror(errno));
            exit(1);
        }

        buf[nbytes] = '\0';
        printf("Response: %s\n", buf);
    }

    return 0;
}