//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>

#define BAUD 9600
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char *argv[]) {
    int fd;
    speed_t baudrate;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        fprintf(stderr, "Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        fprintf(stderr, "Error getting attributes for %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    options.c_cflag = BAUD | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        fprintf(stderr, "Error setting attributes for %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    while (1) {
        char input[100];
        fprintf(stdout, "Enter command: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "up") == 0) {
            char up = 'A';
            write(fd, &up, 1);
        } else if (strcmp(input, "down") == 0) {
            char down = 'B';
            write(fd, &down, 1);
        } else if (strcmp(input, "left") == 0) {
            char left = 'C';
            write(fd, &left, 1);
        } else if (strcmp(input, "right") == 0) {
            char right = 'D';
            write(fd, &right, 1);
        } else if (strcmp(input, "stop") == 0) {
            char stop = 'E';
            write(fd, &stop, 1);
        } else {
            fprintf(stdout, "Invalid command\n");
        }
    }

    close(fd);
    return 0;
}