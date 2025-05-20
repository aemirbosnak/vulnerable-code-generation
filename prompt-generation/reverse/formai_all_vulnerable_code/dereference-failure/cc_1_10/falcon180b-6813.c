//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyS0"
#define DELAY 100000

int fd;
struct termios oldtio, newtio;

void setup_serial_port() {
    if ((fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY)) < 0) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &oldtio) < 0) {
        printf("Error getting attributes of %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    newtio = oldtio;
    newtio.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;

    if (tcsetattr(fd, TCSANOW, &newtio) < 0) {
        printf("Error setting attributes of %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }
}

void send_command(char *command) {
    int i;
    for (i = 0; i < strlen(command); i++) {
        write(fd, &command[i], 1);
        usleep(DELAY);
    }
}

int main() {
    setup_serial_port();

    while (1) {
        send_command("AT\r");
        usleep(DELAY);
        send_command("AT\r");
        usleep(DELAY);
        send_command("AT\r");
        usleep(DELAY);
        send_command("AT\r");
        usleep(DELAY);
    }

    return 0;
}