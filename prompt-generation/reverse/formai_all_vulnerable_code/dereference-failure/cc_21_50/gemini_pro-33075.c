//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <math.h>
#include <time.h>

#define MAX_HOPS 30
#define MAX_PROBES 3
#define TIMEOUT 1000

int main(int argc, char *argv[]) {
  // Initialize variables
  int sockfd, n, i, j, k, l, m, p, q, r, s, t, u, v, w, x, y, z;
  char buffer[1024];
  struct sockaddr_in servaddr, cliaddr;
  struct hostent *server;
  struct timeval timeout;
  fd_set readfds;
  int maxfd;
  int hops[MAX_HOPS];
  int probes[MAX_PROBES];
  int rtt[MAX_HOPS][MAX_PROBES];
  int ttl[MAX_HOPS];
  int port = 33434;
  int verbose = 0;
  int help = 0;

  // Parse command line arguments
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0) {
      verbose = 1;
    } else if (strcmp(argv[i], "-h") == 0) {
      help = 1;
    } else {
      printf("Usage: %s [-v] [-h] hostname\n", argv[0]);
      exit(1);
    }
  }

  // Print help message
  if (help) {
    printf("Usage: %s [-v] [-h] hostname\n", argv[0]);
    printf("Options:\n");
    printf("  -v: Verbose output\n");
    printf("  -h: Print this help message\n");
    exit(0);
  }

  // Get hostname
  if (argc != 2) {
    printf("Usage: %s [-v] [-h] hostname\n", argv[0]);
    exit(1);
  }
  char *hostname = argv[1];

  // Create socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Set socket options
  timeout.tv_sec = TIMEOUT / 1000;
  timeout.tv_usec = (TIMEOUT % 1000) * 1000;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("setsockopt");
    exit(1);
  }

  // Resolve hostname
  server = gethostbyname(hostname);
  if (server == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Set server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  memcpy(&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Set client address
  memset(&cliaddr, 0, sizeof(cliaddr));
  cliaddr.sin_family = AF_INET;
  cliaddr.sin_port = htons(0);
  cliaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Bind socket to client address
  if (bind(sockfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Set TTL to 1
  ttl[0] = 1;

  // Main loop
  for (i = 0; i < MAX_HOPS; i++) {
    // Send probe
    for (j = 0; j < MAX_PROBES; j++) {
      if (verbose) {
        printf("Sending probe %d to %s with TTL %d\n", j + 1, hostname, ttl[i]);
      }
      if (sendto(sockfd, "PROBE", 5, 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("sendto");
        exit(1);
      }
    }

    // Set up select()
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd + 1;

    // Wait for response
    n = select(maxfd, &readfds, NULL, NULL, &timeout);
    if (n < 0) {
      perror("select");
      exit(1);
    } else if (n == 0) {
      if (verbose) {
        printf("No response received from %s with TTL %d\n", hostname, ttl[i]);
      }
      hops[i] = -1;
      for (j = 0; j < MAX_PROBES; j++) {
        rtt[i][j] = -1;
      }
      continue;
    }

    // Receive response
    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
    if (n < 0) {
      perror("recvfrom");
      exit(1);
    }

    // Get hops
    hops[i] = atoi(buffer);
    if (verbose) {
      printf("Received response from %s with TTL %d: %d hops\n", hostname, ttl[i], hops[i]);
    }

    // Get RTT
    for (j = 0; j < MAX_PROBES; j++) {
      rtt[i][j] = atoi(buffer + strlen(buffer) - 3 - j);
      if (verbose) {
        printf("RTT for probe %d: %d ms\n", j + 1, rtt[i][j]);
      }
    }

    // Increment TTL
    ttl[i + 1] = ttl[i] + 1;
  }

  // Print results
  printf("Network Topology Map for %s\n", hostname);
  printf("-----------------------------------------\n");
  printf("Hop\tTTL\tRTT (ms)\n");
  for (i = 0; i < MAX_HOPS; i++) {
    if (hops[i] == -1) {
      printf("%d\t*\t*\n", i + 1);
    } else {
      printf("%d\t%d\t", i + 1, ttl[i]);
      for (j = 0; j < MAX_PROBES; j++) {
        printf("%d ", rtt[i][j]);
      }
      printf("\n");
    }
  }

  // Close socket
  close(sockfd);

  return 0;
}