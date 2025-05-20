//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

// Define the serial port and baud rate
#define PORT "/dev/ttyUSB0"
#define BAUD 9600

// Function prototypes
void initSerial(void);
void sendCommand(char *command);
int receiveResponse(char *response);

// Main function
int main(void) {
    initSerial();

    // Turn on light
    sendCommand("ON");

    // Wait for response
    char response[50];
    receiveResponse(response);
    printf("Light turned on\n");

    // Turn off light
    sendCommand("OFF");

    // Wait for response
    receiveResponse(response);
    printf("Light turned off\n");

    return 0;
}

// Initialize the serial port
void initSerial(void) {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(PORT, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening serial port\n");
        exit(1);
    }

    // Get the current options for the serial port
    tcgetattr(fd, &options);

    // Set the baud rate
    cfsetispeed(&options, BAUD);
    cfsetospeed(&options, BAUD);

    // Set the options for the serial port
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    // Set the new options for the serial port
    tcsetattr(fd, TCSANOW, &options);
}

// Send a command to the serial port
void sendCommand(char *command) {
    int fd;
    int bytesSent;

    fd = open(PORT, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening serial port\n");
        exit(1);
    }

    bytesSent = write(fd, command, strlen(command));
    if (bytesSent == -1) {
        printf("Error writing to serial port\n");
        exit(1);
    }

    close(fd);
}

// Receive a response from the serial port
int receiveResponse(char *response) {
    int fd;
    int bytesReceived;

    fd = open(PORT, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening serial port\n");
        exit(1);
    }

    bytesReceived = read(fd, response, 50);
    if (bytesReceived == -1) {
        printf("Error reading from serial port\n");
        exit(1);
    }

    response[bytesReceived] = '\0';
    close(fd);

    return bytesReceived;
}