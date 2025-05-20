//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PORT_NUM 65535
#define MAX_PORTS 100

struct port_scanner_state {
  struct sockaddr_in addr;
  int sockfd;
  bool ports[MAX_PORT_NUM];
};

int init_port_scanner(struct port_scanner_state *state, const char *host, int port) {
  memset(state, 0, sizeof(struct port_scanner_state));
  state->addr.sin_family = AF_INET;
  state->addr.sin_port = htons(port);
  state->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (state->sockfd == -1) {
    return -1;
  }
  inet_aton(host, &state->addr.sin_addr);
  return 0;
}

int scan_port(struct port_scanner_state *state, int port) {
  state->addr.sin_port = htons(port);
  int ret = connect(state->sockfd, (struct sockaddr *)&state->addr, sizeof(state->addr));
  if (ret == -1) {
    if (errno != ECONNREFUSED) {
      return -1;
    }
  } else {
    state->ports[port] = true;
  }
  return ret;
}

void cleanup_port_scanner(struct port_scanner_state *state) {
  close(state->sockfd);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }
  struct port_scanner_state state;
  int ret = init_port_scanner(&state, argv[1], atoi(argv[2]));
  if (ret != 0) {
    fprintf(stderr, "Failed to initialize port scanner: %s\n", strerror(errno));
    return 1;
  }
  for (int port = 0; port < MAX_PORT_NUM; port++) {
    ret = scan_port(&state, port);
    if (ret == -1) {
      fprintf(stderr, "Failed to scan port %d: %s\n", port, strerror(errno));
      continue;
    }
    if (state.ports[port]) {
      printf("Port %d is open\n", port);
    }
  }
  cleanup_port_scanner(&state);
  return 0;
}