//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <device> <command>\n", argv[0]);
        return 1;
    }

    int device = atoi(argv[1]);
    char command[100];
    strcpy(command, argv[2]);

    int fd = open(device, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct termios oldtio, newtio;
    tcgetattr(fd, &oldtio);

    newtio = oldtio;
    newtio.c_iflag = ISTRIP;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    cfsetispeed(&newtio, B115200);
    cfsetospeed(&newtio, B115200);
    tcsetattr(fd, TCSANOW, &newtio);

    char buf[128];
    int bytes_read = read(fd, buf, sizeof(buf));
    if (bytes_read == -1) {
        perror("read");
        return 1;
    }
    buf[bytes_read] = '\0';
    printf("Received: %s\n", buf);

    if (strcmp(command, "on") == 0) {
        printf("Turning on the lights\n");
        write(fd, "on\n", 4);
    } else if (strcmp(command, "off") == 0) {
        printf("Turning off the lights\n");
        write(fd, "off\n", 4);
    } else {
        printf("Invalid command\n");
    }

    close(fd);
    tcsetattr(fd, TCSANOW, &oldtio);

    return 0;
}