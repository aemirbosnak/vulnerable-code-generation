//FormAI DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SYN_TIMEOUT 5 // Timeout for SYN-ACK response in seconds
#define MAX_PORTS 100 // Maximum number of ports to scan

int open_non_blocking_socket() {
  int fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, IPPROTO_TCP);
  if (fd < 0) {
    perror("socket");
    exit(1);
  }
  return fd;
}

int connect_with_timeout(int fd, struct sockaddr_in addr) {
  int rc = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
  if (rc < 0 && errno != EINPROGRESS) {
    perror("connect");
    exit(1);
  }

  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(fd, &fds);

  struct timeval timeout;
  timeout.tv_sec = SYN_TIMEOUT;
  timeout.tv_usec = 0;

  rc = select(fd + 1, NULL, &fds, NULL, &timeout);
  if (rc < 0) {
    perror("select");
    exit(1);
  } else if (rc == 0) {
    return 0;
  } else {
    int err;
    socklen_t len = sizeof(err);
    if (getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &len) < 0) {
      perror("getsockopt");
      exit(1);
    }
    if (err != 0) {
      errno = err;
      perror("connect");
      exit(1);
    }
  }

  return 1;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <host>\n", argv[0]);
    return 1;
  }

  int port;
  int ports[MAX_PORTS];
  int num_ports = 0;

  // Parse command line arguments to get ports to scan
  if (argc > 2) {
    for (int i = 2; i < argc; i++) {
      port = atoi(argv[i]);
      if (port > 0 && port < 65536) {
        ports[num_ports++] = port;
      }
      if (num_ports == MAX_PORTS) {
        break;
      }
    }
  } else {
    // Default to scanning the first 1000 ports
    for (int i = 1; i <= 1000; i++) {
      ports[num_ports++] = i;
    }
  }

  // Create non-blocking sockets and set them up for connecting to the target host
  int fds[num_ports];
  for (int i = 0; i < num_ports; i++) {
    fds[i] = open_non_blocking_socket();
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(ports[i]);
    if (!connect_with_timeout(fds[i], addr)) {
      printf("Port %d closed\n", ports[i]);
      close(fds[i]);
      fds[i] = -1;
    } else {
      fcntl(fds[i], F_SETFL, fcntl(fds[i], F_GETFL) & ~O_NONBLOCK);
    }
  }

  // Wait for all connections to finish or timeout
  fd_set fds_set;
  FD_ZERO(&fds_set);
  int max_fd = 0;
  for (int i = 0; i < num_ports; i++) {
    if (fds[i] >= 0) {
      FD_SET(fds[i], &fds_set);
      if (fds[i] > max_fd) {
        max_fd = fds[i];
      }
    }
  }

  struct timeval timeout;
  timeout.tv_sec = SYN_TIMEOUT;
  timeout.tv_usec = 0;

  int rc = select(max_fd + 1, &fds_set, NULL, NULL, &timeout);
  if (rc < 0) {
    perror("select");
    exit(1);
  }

  // Print results
  for (int i = 0; i < num_ports; i++) {
    if (fds[i] >= 0) {
      if (FD_ISSET(fds[i], &fds_set)) {
        printf("Port %d open\n", ports[i]);
      } else {
        printf("Port %d closed\n", ports[i]);
      }
      close(fds[i]);
    }
  }

  return 0;
}