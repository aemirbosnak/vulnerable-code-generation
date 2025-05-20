//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Initialize variables
  int sockfd, n;
  struct sockaddr_in servaddr;
  struct hostent *server;

  // Check for correct usage
  if (argc!= 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    return 1;
  }

  // Convert hostname to IP address
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: hostname not found\n");
    return 1;
  }

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: failed to create socket\n");
    return 1;
  }

  // Set up socket address
  bzero((char *) &servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
  servaddr.sin_port = htons(atoi(argv[2]));

  // Connect to server
  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    fprintf(stderr, "Error: failed to connect to server\n");
    return 1;
  }

  // Send and receive data
  char data[256];
  bzero(data, sizeof(data));
  while (1) {
    n = read(sockfd, data, sizeof(data));
    if (n <= 0) {
      fprintf(stderr, "Error: failed to read from socket\n");
      return 1;
    }
    write(sockfd, data, n);
  }

  return 0;
}