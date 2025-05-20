//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <ctype.h>

#define BUFFERSIZE 1024

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <serial port> <baud rate>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the serial port
    int fd = open(argv[1], O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd == -1)
    {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    // Set the baud rate
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, atoi(argv[2]));
    cfsetospeed(&options, atoi(argv[2]));
    tcsetattr(fd, TCSANOW, &options);

    // Send a test message
    const char *message = "Hello, world!\n";
    int bytes_written = write(fd, message, strlen(message));
    if(bytes_written == -1)
    {
        perror("write()");
        exit(EXIT_FAILURE);
    }

    // Read the response from the serial port
    char buffer[BUFFERSIZE];
    int bytes_read = read(fd, buffer, BUFFERSIZE - 1);
    if(bytes_read == -1)
    {
        perror("read()");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';

    // Print the response
    printf("%s", buffer);

    // Close the serial port
    close(fd);

    return EXIT_SUCCESS;
}