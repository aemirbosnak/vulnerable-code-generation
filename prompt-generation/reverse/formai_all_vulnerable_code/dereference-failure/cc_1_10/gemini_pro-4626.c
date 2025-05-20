//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv)
{
    int fd;
    struct termios old_tio, new_tio;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_tty>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the tty device
    fd = open(argv[1], O_RDWR | O_NOCTTY);
    if (fd < 0) {
        fprintf(stderr, "Error opening tty %s: %s\n", argv[1], strerror(errno));
        return EXIT_FAILURE;
    }

    // Save the old terminal settings
    tcgetattr(fd, &old_tio);

    // Set the new terminal settings
    memcpy(&new_tio, &old_tio, sizeof(new_tio));
    new_tio.c_cflag |= CS8;              // 8 data bits
    new_tio.c_cflag &= ~PARENB;          // No parity
    new_tio.c_cflag &= ~CSTOPB;          // 1 stop bit
    new_tio.c_cflag &= ~CRTSCTS;         // No hardware flow control
    new_tio.c_cc[VTIME] = 0;             // Inter-character timer unused
    new_tio.c_cc[VMIN] = 1;              // Block reads until 1 char received
    if (tcsetattr(fd, TCSANOW, &new_tio) < 0) {
        fprintf(stderr, "Error setting tty attributes: %s\n", strerror(errno));
        close(fd);
        return EXIT_FAILURE;
    }

    // Get the current CPU usage
    char buff[BUFF_SIZE];
    int nread;
    nread = read(fd, buff, BUFF_SIZE);
    if (nread < 0) {
        fprintf(stderr, "Error reading tty: %s\n", strerror(errno));
        close(fd);
        tcsetattr(fd, TCSANOW, &old_tio);
        return EXIT_FAILURE;
    }

    // Parse the CPU usage from the output
    int cpu_usage;
    sscanf(buff, "CPU: %d%", &cpu_usage);

    // Print the CPU usage
    printf("CPU usage: %d%%\n", cpu_usage);

    // Restore the old terminal settings
    tcsetattr(fd, TCSANOW, &old_tio);

    close(fd);

    return EXIT_SUCCESS;
}