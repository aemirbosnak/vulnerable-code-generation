//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port1,port2,...>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  char *ports = argv[2];

  struct hostent *host = gethostbyname(hostname);

  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
    perror("Error: could not create socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(0);
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Error: could not bind socket");
    exit(EXIT_FAILURE);
  }

  char *port;
  int portnum;
  char *saveptr;

  for (port = strtok_r(ports, ",", &saveptr); port != NULL; port = strtok_r(NULL, ",", &saveptr)) {
    portnum = atoi(port);

    if (portnum < 0 || portnum > 65535) {
      fprintf(stderr, "Error: invalid port number %d\n", portnum);
      continue;
    }

    addr.sin_port = htons(portnum);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
      printf("Port %d is open\n", portnum);
    }
  }

  close(sockfd);

  return EXIT_SUCCESS;
}