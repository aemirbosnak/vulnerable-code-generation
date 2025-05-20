//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXPORT 65535 // max port number

int main(int argc, char *argv[]) {
  if (argc != 2) { // check if port number argument is provided
    printf("Please provide a port number to scan.\n");
    exit(EXIT_FAILURE);
  }
  
  // parse input argument
  int port = atoi(argv[1]);
  if (port < 0 || port > MAXPORT) {
    printf("Invalid port number, please enter a number between 0 and 65535.\n");
    exit(EXIT_FAILURE);
  }

  // create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // check for errors while creating socket
  if (sockfd == -1) {
    printf("Error while creating socket: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // set socket timeout
  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
    printf("Error while setting socket timeout: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // scan ports
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost address
  int connected;
  for (int i = 1; i <= MAXPORT; i++) {
    address.sin_port = htons(i);
    connected = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
    if (connected == 0) {
      printf("Port %d is open.\n", i);
    }
  }

  // close socket
  close(sockfd);

  return 0;
}