//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BAUD B115200
#define DEVICE "/dev/ttyUSB0"

int main() {
    // Open the serial port
    int fd = open(DEVICE, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening serial port: %s\n", strerror(errno));
        return 1;
    }

    // Configure the serial port settings
    struct termios options;
    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUD | CS8 | CLOCAL | CREAD;
    tcsetattr(fd, TCSANOW, &options);

    // Initialize the drone
    char init_command[] = "AT*REF=10000000,1\r";
    write(fd, init_command, strlen(init_command));

    // Takeoff
    char takeoff_command[] = "AT*FTR=0,1\r";
    write(fd, takeoff_command, strlen(takeoff_command));

    // Fly forward
    char fly_forward_command[] = "AT*FTR=0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0\r";
    write(fd, fly_forward_command, strlen(fly_forward_command));

    // Fly left
    char fly_left_command[] = "AT*FTR=0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1\r";
    write(fd, fly_left_command, strlen(fly_left_command));

    // Fly right
    char fly_right_command[] = "AT*FTR=0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0\r";
    write(fd, fly_right_command, strlen(fly_right_command));

    // Fly backward
    char fly_backward_command[] = "AT*FTR=0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0\r";
    write(fd, fly_backward_command, strlen(fly_backward_command));

    // Land
    char land_command[] = "AT*FTR=0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2\r";
    write(fd, land_command, strlen(land_command));

    // Close the serial port
    close(fd);

    return 0;
}