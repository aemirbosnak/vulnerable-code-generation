//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <errno.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyS0"

int main(int argc, char *argv[])
{
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if(fd == -1)
    {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    tcgetattr(fd, &options);

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    tcsetattr(fd, TCSANOW, &options);

    while(1)
    {
        char ch;
        char command[10];
        int i = 0;

        while((ch = getchar())!= '\n')
        {
            command[i++] = ch;
        }

        command[i] = '\0';

        if(strcmp(command, "up") == 0)
        {
            printf("Drone flying up\n");
        }
        else if(strcmp(command, "down") == 0)
        {
            printf("Drone flying down\n");
        }
        else if(strcmp(command, "left") == 0)
        {
            printf("Drone flying left\n");
        }
        else if(strcmp(command, "right") == 0)
        {
            printf("Drone flying right\n");
        }
        else if(strcmp(command, "stop") == 0)
        {
            printf("Drone stopped\n");
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    close(fd);

    return 0;
}