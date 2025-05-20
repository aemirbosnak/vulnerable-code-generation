//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <sys/time.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define DRONE_NAME "MyDrone"

// Drone commands
#define DRONE_CMD_TAKEOFF 0x01
#define DRONE_CMD_LAND 0x02
#define DRONE_CMD_UP 0x03
#define DRONE_CMD_DOWN 0x04
#define DRONE_CMD_LEFT 0x05
#define DRONE_CMD_RIGHT 0x06
#define DRONE_CMD_FORWARD 0x07
#define DRONE_CMD_BACKWARD 0x08
#define DRONE_CMD_FLIP_LEFT 0x09
#define DRONE_CMD_FLIP_RIGHT 0x0A
#define DRONE_CMD_FLIP_FORWARD 0x0B
#define DRONE_CMD_FLIP_BACKWARD 0x0C

// Drone status
#define DRONE_STATUS_OK 0x00
#define DRONE_STATUS_ERROR 0x01
#define DRONE_STATUS_LOW_BATTERY 0x02
#define DRONE_STATUS_OUT_OF_RANGE 0x03

// Serial port parameters
#define SERIAL_PORT "/dev/ttyUSB0"
#define SERIAL_BAUDRATE B115200

// Socket parameters
#define SOCKET_PORT 5555
#define SOCKET_ADDRESS "192.168.1.1"

// Thread parameters
#define THREAD_STACK_SIZE 1024
#define THREAD_PRIORITY 10

// Global variables
int serial_fd;
int socket_fd;
pthread_t thread_id;
bool running = true;

// Function to open the serial port
int open_serial_port() {
  int fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY | O_NONBLOCK);
  if (fd < 0) {
    fprintf(stderr, "Error opening serial port: %s\n", strerror(errno));
    return -1;
  }

  struct termios term;
  tcgetattr(fd, &term);
  term.c_cflag &= ~PARENB; // Disable parity
  term.c_cflag &= ~CSTOPB; // Set stop bits to 1
  term.c_cflag &= ~CSIZE; // Set character size to 8 bits
  term.c_cflag |= CS8;
  term.c_cflag &= ~CRTSCTS; // Disable hardware flow control
  term.c_lflag &= ~ICANON; // Set input mode to non-canonical (raw)
  term.c_lflag &= ~ECHO; // Disable echo
  term.c_lflag &= ~ISIG; // Disable signal characters
  term.c_oflag &= ~OPOST; // Disable output processing
  term.c_cc[VMIN] = 0; // Set minimum number of characters to read to 0
  term.c_cc[VTIME] = 0; // Set timeout to 0

  tcsetattr(fd, TCSANOW, &term);

  return fd;
}

// Function to close the serial port
void close_serial_port(int fd) {
  close(fd);
}

// Function to send a command to the drone
void send_command(uint8_t command) {
  uint8_t buffer[2];
  buffer[0] = DRONE_NAME[0];
  buffer[1] = command;

  write(serial_fd, buffer, sizeof(buffer));
}

// Function to receive a status from the drone
uint8_t receive_status() {
  uint8_t buffer[1];
  read(serial_fd, buffer, sizeof(buffer));

  return buffer[0];
}

// Function to open the socket
int open_socket() {
  int fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (fd < 0) {
    fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
    return -1;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(SOCKET_ADDRESS);
  addr.sin_port = htons(SOCKET_PORT);

  if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
    close(fd);
    return -1;
  }

  return fd;
}

// Function to close the socket
void close_socket(int fd) {
  close(fd);
}

// Function to receive data from the socket
void* receive_data(void* args) {
  while (running) {
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);

    uint8_t buffer[256];
    ssize_t nbytes = recvfrom(socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addrlen);
    if (nbytes < 0) {
      fprintf(stderr, "Error receiving data from socket: %s\n", strerror(errno));
      continue;
    }

    // Parse the data
    uint8_t command = buffer[0];

    // Send the command to the drone
    send_command(command);

    // Receive the status from the drone
    uint8_t status = receive_status();

    // Send the status back to the client
    sendto(socket_fd, &status, sizeof(status), 0, (struct sockaddr*)&addr, addrlen);
  }

  return NULL;
}

// Function to start the drone
void start_drone() {
  // Open the serial port
  serial_fd = open_serial_port();
  if (serial_fd < 0) {
    fprintf(stderr, "Error opening serial port\n");
    exit(1);
  }

  // Open the socket
  socket_fd = open_socket();
  if (socket_fd < 0) {
    fprintf(stderr, "Error opening socket\n");
    exit(1);
  }

  // Create the thread
  pthread_create(&thread_id, NULL, receive_data, NULL);

  // Send the takeoff command
  send_command(DRONE_CMD_TAKEOFF);
}

// Function to stop the drone
void stop_drone() {
  // Send the land command
  send_command(DRONE_CMD_LAND);

  // Close the serial port
  close_serial_port(serial_fd);

  // Close the socket
  close_socket(socket_fd);

  // Terminate the thread
  running = false;
  pthread_join(thread_id, NULL);
}

// Main function
int main(int argc, char** argv) {
  // Start the drone
  start_drone();

  // Keep the drone running until the user presses Ctrl+C
  while (running) {
    sleep(1);
  }

  // Stop the drone
  stop_drone();

  return 0;
}