//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <termios.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 1024

void get_temp(int fd) {
    char buffer[MAX_LINE];
    int read_size;
    while ((read_size = read(fd, buffer, MAX_LINE)) > 0) {
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    int fd, ch, port;
    struct termios oldtio, newtio;
    int status = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <thermocouple port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    if (port < 0 || port > 255) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (tcgetattr(fd, &oldtio)!= 0) {
        perror("tcgetattr");
        exit(1);
    }

    bzero(&newtio, sizeof(newtio));
    newtio.c_iflag = ISTRIP;
    newtio.c_oflag = 0;
    newtio.c_cflag = CS8 | CREAD | CLOCAL;
    newtio.c_lflag = 0;
    newtio.c_cc[VMIN] = 1;
    newtio.c_cc[VTIME] = 1;

    if (tcsetattr(fd, TCSANOW, &newtio)!= 0) {
        perror("tcsetattr");
        exit(1);
    }

    printf("Reading temperature from port %d...\n", port);
    get_temp(fd);

    tcsetattr(fd, TCSANOW, &oldtio);
    close(fd);

    return 0;
}