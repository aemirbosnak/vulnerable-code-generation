//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <termios.h>
#include <errno.h>

int main() {
    int fd;
    struct termios oldtio, newtio;
    struct termios newtio2;
    char input[100];

    // Open the controlling terminal file
    fd = open("/dev/tty", O_RDWR);
    if (fd < 0) {
        printf("Unable to open /dev/tty: %s\n", strerror(errno));
        return 1;
    }

    // Save old terminal settings
    tcgetattr(fd, &oldtio);

    // Set new terminal settings
    cfmakeraw(&newtio);
    newtio.c_lflag |= ICANON | ECHO;
    newtio.c_cc[VTIME] = 5;
    newtio.c_cc[VMIN] = 1;
    tcsetattr(fd, TCSANOW, &newtio);

    // Input loop
    while (1) {
        printf("Enter command (q to quit): ");
        fflush(stdout);
        read(fd, input, sizeof(input));
        if (strcmp(input, "q") == 0)
            break;

        // Output loop
        while (1) {
            char c = getchar();
            if (c == EOF)
                break;
            write(fd, &c, sizeof(c));
        }
    }

    // Restore old terminal settings
    tcsetattr(fd, TCSANOW, &oldtio);

    // Close controlling terminal file
    close(fd);

    return 0;
}