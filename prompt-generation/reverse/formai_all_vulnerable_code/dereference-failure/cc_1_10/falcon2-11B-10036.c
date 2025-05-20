//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

#define BAUD_RATE 9600
#define DATA_BITS 8
#define STOP_BITS 1
#define FIFO_SIZE 256

int main(int argc, char **argv) {
    struct termios old_termios, new_termios;
    int fd, ret;
    char fifo_path[FIFO_SIZE], c;
    int fifo_fd;

    // Check if the program is being run as root
    if (geteuid()!= 0) {
        fprintf(stderr, "This program must be run as root.\n");
        return 1;
    }

    // Create a FIFO for communication with the drone
    snprintf(fifo_path, FIFO_SIZE, "/tmp/drone_control");
    if (mkfifo(fifo_path, 0666) == -1) {
        fprintf(stderr, "Failed to create FIFO: %s\n", strerror(errno));
        return 1;
    }
    fifo_fd = open(fifo_path, O_RDONLY);
    if (fifo_fd == -1) {
        fprintf(stderr, "Failed to open FIFO: %s\n", strerror(errno));
        return 1;
    }

    // Set the terminal to raw mode
    tcgetattr(0, &old_termios);
    new_termios = old_termios;
    new_termios.c_cflag |= (CLOCAL | CREAD);
    tcsetattr(0, TCSANOW, &new_termios);

    // Set the baud rate to the drone's communication speed
    cfsetispeed(&new_termios, BAUD_RATE);
    cfsetospeed(&new_termios, BAUD_RATE);
    ret = tcsetattr(0, TCSANOW, &new_termios);
    if (ret == -1) {
        fprintf(stderr, "Failed to set baud rate: %s\n", strerror(errno));
        return 1;
    }

    // Read commands from the drone and send them to the terminal
    while (1) {
        // Read a single byte from the FIFO
        ret = read(fifo_fd, &c, 1);
        if (ret == -1) {
            fprintf(stderr, "Failed to read from FIFO: %s\n", strerror(errno));
            return 1;
        }
        if (ret == 0) {
            break;
        }

        // Send the command to the terminal
        write(1, &c, 1);
    }

    // Restore the terminal's previous configuration
    tcsetattr(0, TCSANOW, &old_termios);

    // Close the FIFO
    close(fifo_fd);
    return 0;
}