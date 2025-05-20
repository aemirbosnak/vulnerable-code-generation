//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_BUS "/dev/i2c-1"
#define I2C_ADDR 0x48

int main(int argc, char **argv) {
  int fd;
  unsigned char cmd[2];

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <on|off>\n", argv[0]);
    exit(1);
  }

  if ((fd = open(I2C_BUS, O_RDWR)) < 0) {
    perror("open");
    exit(1);
  }

  if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
    perror("ioctl");
    exit(1);
  }

  if (strcmp(argv[1], "on") == 0) {
    cmd[0] = 0x01;
    cmd[1] = 0xFF;
  } else if (strcmp(argv[1], "off") == 0) {
    cmd[0] = 0x01;
    cmd[1] = 0x00;
  } else {
    fprintf(stderr, "Invalid argument: %s\n", argv[1]);
    exit(1);
  }

  if (write(fd, cmd, 2) < 0) {
    perror("write");
    exit(1);
  }

  close(fd);

  return 0;
}