//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define BUS 0
#define SPEED 1000000
#define MESSAGE_LENGTH 10

// Function to turn on the light
void turnOnLight() {
  FILE *file;
  int fd;

  // Open the serial port
  if ((fd = open("/dev/spidev0.0", O_RDWR)) < 0) {
    printf("Error opening serial port\n");
    exit(1);
  }

  // Set the bits per second (baud rate)
  if (ioctl(fd, SPI_IOC_WR_MODE, SPI_MODE_0) < 0) {
    printf("Error setting baud rate\n");
    exit(1);
  }

  // Send the message to turn on the light
  char message[MESSAGE_LENGTH];
  sprintf(message, "TURN ON");
  if (write(fd, message, strlen(message)) < 0) {
    printf("Error writing to serial port\n");
    exit(1);
  }

  close(fd);
}

// Function to turn off the light
void turnOffLight() {
  FILE *file;
  int fd;

  // Open the serial port
  if ((fd = open("/dev/spidev0.0", O_RDWR)) < 0) {
    printf("Error opening serial port\n");
    exit(1);
  }

  // Set the bits per second (baud rate)
  if (ioctl(fd, SPI_IOC_WR_MODE, SPI_MODE_0) < 0) {
    printf("Error setting baud rate\n");
    exit(1);
  }

  // Send the message to turn off the light
  char message[MESSAGE_LENGTH];
  sprintf(message, "TURN OFF");
  if (write(fd, message, strlen(message)) < 0) {
    printf("Error writing to serial port\n");
    exit(1);
  }

  close(fd);
}

int main() {
  turnOnLight();
  turnOffLight();

  return 0;
}