//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>

#define BUFFER_SIZE 256

// Structure to hold drone configuration
typedef struct {
    int altitude;
    int speed;
    int direction; // 0: North, 1: East, 2: South, 3: West
} DroneConfig;

// Function to initialize the serial port for communication
int init_serial(const char *portname) {
    int fd = open(portname, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Unable to open the port");
        exit(EXIT_FAILURE);
    }

    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB; // No parity
    options.c_cflag &= ~CSTOPB; // 1 stop bit
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8; // 8 data bits
    tcsetattr(fd, TCSANOW, &options);
    
    return fd;
}

// Function to send drone commands over serial
void send_command(int fd, const char *command) {
    write(fd, command, strlen(command));
    printf("Command sent: %s\n", command);
}

// Function to configure the drone
void configure_drone(DroneConfig *config, int altitude, int speed, int direction) {
    config->altitude = altitude;
    config->speed = speed;
    config->direction = direction;

    printf("Drone configuration updated:\n");
    printf("Altitude: %d meters\n", config->altitude);
    printf("Speed: %d m/s\n", config->speed);
    printf("Direction: %d\n", config->direction);
}

// Function to generate the command string based on config
void generate_command(DroneConfig *config, char *command) {
    sprintf(command, "ALT:%d;SPD:%d;DIR:%d;", config->altitude, config->speed, config->direction);
}

// Function to control the drone flight
void control_drone(int fd, DroneConfig *config) {
    char command[BUFFER_SIZE];
    
    generate_command(config, command);
    send_command(fd, command);
}

// Function to print a usage message
void print_usage() {
    printf("Usage: drone_control <serial_port> <altitude> <speed> <direction>\n");
    printf("Direction: 0 - North, 1 - East, 2 - South, 3 - West\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    const char *portname = argv[1];
    int altitude = atoi(argv[2]);
    int speed = atoi(argv[3]);
    int direction = atoi(argv[4]);

    if (direction < 0 || direction > 3) {
        fprintf(stderr, "Invalid direction. Must be between 0 and 3.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize drone configuration
    DroneConfig drone;
    configure_drone(&drone, altitude, speed, direction);

    // Initialize serial communication
    int fd = init_serial(portname);
    
    // Control the drone with the configured settings
    control_drone(fd, &drone);

    // Clean up and close the serial port
    close(fd);
    
    return 0;
}