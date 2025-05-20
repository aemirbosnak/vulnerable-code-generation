//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

#define DEVICE "/dev/ttyUSB0"
#define BAUDRATE B9600

int fd; // file descriptor

// Define drone movements
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define UP 5
#define DOWN 6
#define ROTATE_LEFT 7
#define ROTATE_RIGHT 8
#define LAND 9

// Initialize the serial port
int init_serial_port()
{
    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd == -1)
    {
        printf("Error opening serial port: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Configure the serial port
    struct termios config;
    tcgetattr(fd, &config);
    cfsetispeed(&config, BAUDRATE);
    cfsetospeed(&config, BAUDRATE);
    config.c_cflag &= ~PARENB;
    config.c_cflag &= ~CSTOPB;
    config.c_cflag &= ~CSIZE;
    config.c_cflag |= CS8;
    config.c_cflag &= ~CRTSCTS;
    config.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    config.c_iflag &= ~(IXON | IXOFF | IXANY);
    tcsetattr(fd, TCSANOW, &config);

    // Drain the input and output buffers
    tcflush(fd, TCIOFLUSH);

    return fd;
}

// Send a movement command to the drone
void send_command(int movement)
{
    char command[2];

    switch (movement)
    {
        case FORWARD:
            strcpy(command, "F");
            break;

        case BACKWARD:
            strcpy(command, "B");
            break;

        case LEFT:
            strcpy(command, "L");
            break;

        case RIGHT:
            strcpy(command, "R");
            break;

        case UP:
            strcpy(command, "U");
            break;

        case DOWN:
            strcpy(command, "D");
            break;

        case ROTATE_LEFT:
            strcpy(command, "A");
            break;

        case ROTATE_RIGHT:
            strcpy(command, "D");
            break;

        case LAND:
            strcpy(command, "S");
            break;
    }

    // Send the command to the drone
    write(fd, command, strlen(command));
}

// Handle CTRL-C signal
void handle_signal(int signal)
{
    printf("\nExiting...\n");

    // Send a landing command before exiting
    send_command(LAND);

    // Close the serial port
    close(fd);

    exit(0);
}

int main()
{
    // Initialize the serial port
    init_serial_port();

    // Register the signal handler
    signal(SIGINT, handle_signal);

    printf("Ready to control the drone!\n\n");
    printf("Press 'W' to move forward\n");
    printf("Press 'S' to move backward\n");
    printf("Press 'A' to move left\n");
    printf("Press 'D' to move right\n");
    printf("Press 'Q' to rotate left\n");
    printf("Press 'E' to rotate right\n");
    printf("Press 'Z' to move up\n");
    printf("Press 'X' to move down\n");
    printf("Press 'C' to land\n\n");

    // Loop forever, waiting for input commands
    while (true)
    {
        char c = getchar();
        switch (c)
        {
            case 'W':
            case 'w':
                send_command(FORWARD);
                break;

            case 'S':
            case 's':
                send_command(BACKWARD);
                break;

            case 'A':
            case 'a':
                send_command(LEFT);
                break;

            case 'D':
            case 'd':
                send_command(RIGHT);
                break;

            case 'Q':
            case 'q':
                send_command(ROTATE_LEFT);
                break;

            case 'E':
            case 'e':
                send_command(ROTATE_RIGHT);
                break;

            case 'Z':
            case 'z':
                send_command(UP);
                break;

            case 'X':
            case 'x':
                send_command(DOWN);
                break;

            case 'C':
            case 'c':
                send_command(LAND);
                break;
        }
    }

    return 0;
}