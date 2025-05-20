//FormAI DATASET v1.0 Category: QR code reader ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>

#define BUFFER_SIZE 128

volatile sig_atomic_t not_done = true;

void sigint_handler(int sig) {
  printf("\nQR code reader stopped\n");
  not_done = false;
}

int main(void) {
  int fd;
  char buffer[BUFFER_SIZE];
  struct termios options;
  fd_set rfds;
  struct timeval tv;

  // Open the serial port
  fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1) {
    perror("open_port: Unable to open /dev/ttyUSB1 - ");
    exit(EXIT_FAILURE);
  }

  // Configure the serial port
  tcgetattr(fd, &options);
  cfsetispeed(&options, B9600);
  cfsetospeed(&options, B9600);
  options.c_cflag |= (CLOCAL | CREAD);
  options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
  options.c_oflag &= ~OPOST;
  options.c_cc[VMIN]  = 0;
  options.c_cc[VTIME] = 10;
  tcsetattr(fd, TCSANOW, &options);

  // Set up the signal handler
  signal(SIGINT, sigint_handler);

  // Wait for a QR code to be scanned
  printf("QR code reader started\n");
  while (not_done) {
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (select(fd + 1, &rfds, NULL, NULL, &tv) == -1) {
      perror("select");
      exit(EXIT_FAILURE);
    }
    if (FD_ISSET(fd, &rfds)) {
      ssize_t num_read = read(fd, buffer, BUFFER_SIZE);
      if (num_read == -1) {
        if (errno == EAGAIN) {
          continue;
        } else {
          perror("read");
          exit(EXIT_FAILURE);
        }
      }
      buffer[num_read] = '\0';
      printf("QR code: %s", buffer);
    }
  }

  // Clean up
  close(fd);
  exit(EXIT_SUCCESS);
}