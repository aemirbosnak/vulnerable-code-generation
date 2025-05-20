//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyACM0"

int fd;
struct termios oldtio, newtio;

void setup_serial() {
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        fprintf(stderr, "Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    memset(&oldtio, 0, sizeof(oldtio));
    memset(&newtio, 0, sizeof(newtio));

    if (tcgetattr(fd, &oldtio)!= 0) {
        fprintf(stderr, "Error getting attributes: %s\n", strerror(errno));
        exit(1);
    }

    newtio.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;

    if (tcsetattr(fd, TCSANOW, &newtio)!= 0) {
        fprintf(stderr, "Error setting attributes: %s\n", strerror(errno));
        exit(1);
    }
}

void send_command(char *cmd) {
    write(fd, cmd, strlen(cmd));
    write(fd, "\r", 1);
}

void *read_thread(void *arg) {
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            fprintf(stderr, "Error reading from serial port\n");
            exit(1);
        }
        printf("%s", buffer);
    }
}

int main() {
    setup_serial();

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, read_thread, NULL);

    while (1) {
        char input[1024];
        fgets(input, sizeof(input), stdin);
        send_command(input);
    }

    close(fd);
    return 0;
}