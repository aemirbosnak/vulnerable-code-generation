//FormAI DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PORTS 65535 // maximum port number
#define MAX_IP_LEN INET6_ADDRSTRLEN // maximum IP address length
#define MAX_CONNS 100 // maximum number of concurrent connections
#define MAX_RETRY 3 // maximum number of retry attempts

int sock_list[MAX_CONNS]; // list of socket file descriptors
char error_buf[1024]; // buffer for error messages

/*
 * Function: print_usage
 * ---------------------
 * Prints the usage information.
 */

void print_usage() {
  printf("Usage: portscan <ip address>\n");
  printf("Example: portscan 127.0.0.1\n");
}

/*
 * Function: set_non_blocking
 * --------------------------
 * Sets the given socket file descriptor to non-blocking mode.
 */

void set_non_blocking(int sock_fd) {
  int flags = fcntl(sock_fd, F_GETFL, 0);
  fcntl(sock_fd, F_SETFL, flags | O_NONBLOCK);
}

/*
 * Function: connect_to_port
 * -------------------------
 * Attempts to connect to the given IP address and port number.
 */

int connect_to_port(char* ip_addr, int port) {
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    sprintf(error_buf, "Error opening socket: %s", strerror(errno));
    return -1;
  }

  set_non_blocking(sock_fd);

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, ip_addr, &server_addr.sin_addr) < 0) {
    sprintf(error_buf, "Error parsing IP address: %s", strerror(errno));
    return -1;
  }

  int ret = connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr));
  if (ret < 0 && errno != EINPROGRESS) {
    sprintf(error_buf, "Error connecting to port %d: %s", port, strerror(errno));
    return -1;
  }

  return sock_fd;
}

/*
 * Function: check_socket
 * ----------------------
 * Checks if the given socket file descriptor is ready for I/O.
 */

int check_socket(int sock_fd, fd_set* read_fds) {
  if (FD_ISSET(sock_fd, read_fds)) {
    return 1;
  } else {
    return 0;
  }
}

/*
 * Function: scan_ports
 * --------------------
 * Scans all ports on the given IP address.
 */

void scan_ports(char* ip_addr) {
  int finished = 0;
  int num_conns = 0;
  struct hostent* host = gethostbyname(ip_addr);
  if (host == NULL) {
    printf("Invalid IP address: %s\n", ip_addr);
    return;
  }

  printf("Scanning ports on %s...\n", ip_addr);

  int port;
  for (port = 1; port <= MAX_PORTS && !finished;) {
    fd_set read_fds;
    FD_ZERO(&read_fds);

    int i, max_fd = 0;
    for (i = 0; i < num_conns; i++) {
      FD_SET(sock_list[i], &read_fds);
      if (sock_list[i] > max_fd) {
        max_fd = sock_list[i];
      }
    }

    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    int ready_fds = select(max_fd + 1, &read_fds, NULL, NULL, &timeout);
    if (ready_fds < 0) {
      printf("Error waiting for sockets: %s\n", strerror(errno));
      return;
    }

    if (ready_fds == 0) {
      num_conns = 0;
      continue;
    }

    for (i = 0; i < num_conns; i++) {
      if (check_socket(sock_list[i], &read_fds)) {
        printf("Port %d is open on %s\n", port, ip_addr);
        close(sock_list[i]);
        sock_list[i] = -1;
        num_conns--;
        port++;
      }
    }

    while (num_conns < MAX_CONNS && port <= MAX_PORTS) {
      int sock_fd = connect_to_port(ip_addr, port);
      if (sock_fd < 0) {
        if (strcmp(error_buf, "Resource temporarily unavailable") == 0 &&
            (errno == EINPROGRESS || errno == EWOULDBLOCK)) {
          printf("Retrying port %d...\n", port);
          continue;
        }
        port++;
      } else {
        sock_list[num_conns] = sock_fd;
        num_conns++;
        port++;
      }
    }

    if (num_conns == 0) {
      finished = 1;
    }
  }

  printf("Scan complete.\n");
}

/*
 * Function: main
 * --------------
 * Parses the given command-line arguments and starts the port scan.
 */

int main(int argc, char** argv) {
  if (argc != 2) {
    print_usage();
    return 1;
  }

  char ip_addr[MAX_IP_LEN + 1];
  memset(ip_addr, 0, sizeof(ip_addr));
  strncpy(ip_addr, argv[1], MAX_IP_LEN);

  scan_ports(ip_addr);

  return 0;
}