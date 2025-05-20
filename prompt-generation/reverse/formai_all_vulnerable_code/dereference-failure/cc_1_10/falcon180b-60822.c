//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

#define BAUDRATE B9600
#define SERIAL_PORT "/dev/ttyS0"
#define MAX_BUFFER_SIZE 1024

int fd;
char buffer[MAX_BUFFER_SIZE];
int bytes_read;

void init_serial_port() {
    struct termios options;
    memset(&options, 0, sizeof(options));

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VTIME] = 5;
    options.c_cc[VMIN] = 0;

    fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening serial port: %s\n", strerror(errno));
        exit(1);
    }

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting serial port options: %s\n", strerror(errno));
        exit(1);
    }
}

void send_command(const char* command) {
    write(fd, command, strlen(command));
}

void read_response(char* response) {
    bytes_read = read(fd, buffer, MAX_BUFFER_SIZE);

    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        strcpy(response, buffer);
    } else {
        strcpy(response, "No response");
    }
}

int main() {
    init_serial_port();

    char response[MAX_BUFFER_SIZE];

    while (1) {
        send_command("MOVE 10");
        read_response(response);
        printf("Response: %s\n", response);

        usleep(500000);

        send_command("TURN 30");
        read_response(response);
        printf("Response: %s\n", response);

        usleep(500000);

        send_command("MOVE -10");
        read_response(response);
        printf("Response: %s\n", response);

        usleep(500000);

        send_command("TURN -30");
        read_response(response);
        printf("Response: %s\n", response);

        usleep(500000);
    }

    close(fd);
    return 0;
}