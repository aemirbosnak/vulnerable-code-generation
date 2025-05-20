//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

#define BUFSIZE 1024

int serial_init(const char *port, int baud)
{
    int fd;
    struct termios tio;

    fd = open(port, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    memset(&tio, 0, sizeof(tio));
    tio.c_cflag = CS8 | CLOCAL | CREAD;
    tio.c_iflag = IGNPAR | IGNBRK;
    tio.c_oflag = 0;
    tio.c_lflag = 0;
    tio.c_cc[VTIME] = 0;
    tio.c_cc[VMIN] = 1;
    cfsetispeed(&tio, baud);
    cfsetospeed(&tio, baud);

    if (tcsetattr(fd, TCSANOW, &tio) < 0) {
        perror("tcsetattr");
        close(fd);
        return -1;
    }

    return fd;
}

void serial_send(int fd, const char *buf, size_t len)
{
    int ret;

    ret = write(fd, buf, len);
    if (ret < 0) {
        perror("write");
        return;
    }
}

void serial_recv(int fd, char *buf, size_t len)
{
    int ret;

    ret = read(fd, buf, len);
    if (ret < 0) {
        perror("read");
        return;
    }

    buf[ret] = '\0';
}

int main(int argc, char **argv)
{
    int fd;
    char buf[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <port> <baud>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fd = serial_init(argv[1], atoi(argv[2]));
    if (fd < 0) {
        return EXIT_FAILURE;
    }

    while (1) {
        printf("Enter command: ");
        fgets(buf, BUFSIZE, stdin);

        serial_send(fd, buf, strlen(buf));

        serial_recv(fd, buf, BUFSIZE);
        printf("Received: %s\n", buf);
    }

    close(fd);

    return EXIT_SUCCESS;
}