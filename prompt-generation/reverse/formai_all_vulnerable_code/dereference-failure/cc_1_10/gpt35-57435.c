//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    int tty_fd, n;
    struct termios uart;
    char str[100];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <tty device>\n", argv[0]);
        return 1;
    }

    tty_fd = open(argv[1], O_RDWR | O_NOCTTY);

    if (tty_fd < 0) {
        fprintf(stderr, "Error %d opening %s: %s\n", errno, argv[1], strerror(errno));
        return 2;
    }

    tcgetattr(tty_fd, &uart);

    uart.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    uart.c_iflag = IGNPAR;
    uart.c_oflag = 0;
    uart.c_lflag = 0;

    tcflush(tty_fd, TCIFLUSH);
    tcsetattr(tty_fd, TCSANOW, &uart);

    while(1) {
        memset(str, 0, sizeof(str));
        n = read(tty_fd, str, sizeof(str));

        if (n > 0) {
            printf("Received command: %s\n", str);
            // Execute command here
        }
    }

    close(tty_fd);

    return 0;
}