//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Custom error handler
void error(char *msg) {
  perror(msg);
  exit(1);
}

// Ping function
int ping(char *host) {
  struct sockaddr_in addr;
  int sockfd, ret;
  struct timeval tv;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("Error creating socket");

  bzero((char *) &addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80); // Pinging on port 80

  // Get the host IP address
  struct hostent *he = gethostbyname(host);
  if (he == NULL)
    error("Error getting host IP address");

  bcopy((char *)he->h_addr, (char *)&addr.sin_addr, he->h_length);

  // Set timeout
  tv.tv_sec = 1;
  tv.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0)
    error("Error setting timeout");

  // Connect to the host
  ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    if (errno == ETIMEDOUT)
      return -1; // Host unreachable
    else
      error("Error connecting to host");
  }

  // Close the socket
  close(sockfd);

  return 0; // Host reachable
}

// Main function
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <host>\n", argv[0]);
    exit(1);
  }

  char *host = argv[1];
  int ret = ping(host);

  if (ret == 0)
    printf("%s is reachable\n", host);
  else if (ret == -1)
    printf("%s is unreachable\n", host);
  else
    printf("Error pinging %s\n", host);

  return 0;
}