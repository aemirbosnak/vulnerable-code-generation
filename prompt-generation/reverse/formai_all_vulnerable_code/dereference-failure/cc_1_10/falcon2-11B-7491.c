//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main() {
    int drone_fd;
    int read_size;
    int write_size;
    int timeout;
    char *drone_path = "/dev/drone";
    char *command_str = "takeoff";
    char command[100];
    struct termios old_termios;
    struct termios new_termios;

    // Open the drone's serial port
    drone_fd = open(drone_path, O_RDWR);
    if (drone_fd < 0) {
        fprintf(stderr, "Could not open drone's serial port: %s\n", strerror(errno));
        return 1;
    }

    // Get the current terminal settings
    tcgetattr(0, &old_termios);

    // Set the terminal to raw mode
    new_termios = old_termios;
    new_termios.c_iflag = 0;
    new_termios.c_oflag = 0;
    new_termios.c_cflag = CS8 | CLOCAL | CREAD;
    new_termios.c_lflag = 0;
    tcsetattr(0, TCSANOW, &new_termios);

    // Wait for the drone to be ready
    timeout = 5;
    while (timeout-- > 0) {
        read_size = read(drone_fd, command, 100);
        if (read_size > 0) {
            printf("Drone ready: %s\n", command);
            break;
        }
        sleep(1);
    }

    // Send the takeoff command
    sprintf(command, "%s\n", command_str);
    write(drone_fd, command, strlen(command));

    // Wait for the drone to take off
    timeout = 10;
    while (timeout-- > 0) {
        read_size = read(drone_fd, command, 100);
        if (read_size > 0) {
            printf("Drone taking off: %s\n", command);
            break;
        }
        sleep(1);
    }

    // Set the terminal back to its original settings
    tcsetattr(0, TCSANOW, &old_termios);

    // Close the drone's serial port
    close(drone_fd);

    return 0;
}