//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyS0"

void setupSerial() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening %s\n", DEVICE);
        exit(1);
    }

    tcgetattr(fd, &options);

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    tcsetattr(fd, TCSANOW, &options);
}

void sendCommand(char *command) {
    int fd;
    char response[100];

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening %s\n", DEVICE);
        exit(1);
    }

    write(fd, command, strlen(command));

    read(fd, response, sizeof(response));

    printf("Response: %s\n", response);

    close(fd);
}

int main() {
    setupSerial();

    sendCommand("AT\r");

    sendCommand("AT+CIPSTART=\"TCP\",\"192.168.1.1\",5555\r");

    sendCommand("AT+CIPSEND=30\r");

    char message[30] = "Hello, World!";

    write(1, message, strlen(message));

    read(0, message, sizeof(message));

    sendCommand(message);

    close(1);

    return 0;
}