//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFERSIZE 1024
#define TIMEOUTSECS 5

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <host name> <port>\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in serveraddr;
  struct timeval timeout;
  struct hostent *host;
  int sockfd, numsent, numrecv, speed;
  char buffer[BUFFERSIZE];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Set timeout
  timeout.tv_sec = TIMEOUTSECS;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
    perror("setsockopt");
    close(sockfd);
    return 1;
  }

  // Resolve the hostname
  host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    close(sockfd);
    return 1;
  }

  // Fill in the server address
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(port);
  serveraddr.sin_addr = *(struct in_addr *)host->h_addr;

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
    perror("connect");
    close(sockfd);
    return 1;
  }

  // Send a message to the server
  numsent = write(sockfd, "Hello world!", 12);
  if (numsent == -1) {
    perror("write");
    close(sockfd);
    return 1;
  }

  // Receive a message from the server
  numrecv = read(sockfd, buffer, BUFFERSIZE);
  if (numrecv == -1) {
    perror("read");
    close(sockfd);
    return 1;
  }

  // Calculate the speed
  speed = numrecv / TIMEOUTSECS;

  // Close the socket
  close(sockfd);

  // Print the speed
  printf("Speed: %d B/s\n", speed);

  return 0;
}