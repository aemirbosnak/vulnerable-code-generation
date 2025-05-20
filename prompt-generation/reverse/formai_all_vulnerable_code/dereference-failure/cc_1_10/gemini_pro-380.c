//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_DEV "/dev/i2c-1"
#define I2C_ADDR 0x38

int main(int argc, char **argv) {
  int fd;
  unsigned char buf[2];

  if ((fd = open(I2C_DEV, O_RDWR)) < 0) {
    fprintf(stderr, "Error opening I2C device: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
    fprintf(stderr, "Error setting I2C slave address: %s\n", strerror(errno));
    close(fd);
    return EXIT_FAILURE;
  }

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <on|off>\n", argv[0]);
    close(fd);
    return EXIT_FAILURE;
  }

  if (strcmp(argv[1], "on") == 0) {
    buf[0] = 0x01;
  } else if (strcmp(argv[1], "off") == 0) {
    buf[0] = 0x00;
  } else {
    fprintf(stderr, "Invalid argument: %s\n", argv[1]);
    close(fd);
    return EXIT_FAILURE;
  }

  if (write(fd, buf, 1) != 1) {
    fprintf(stderr, "Error writing to I2C device: %s\n", strerror(errno));
    close(fd);
    return EXIT_FAILURE;
  }

  close(fd);
  return EXIT_SUCCESS;
}