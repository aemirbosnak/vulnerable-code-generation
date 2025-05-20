//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
  struct sockaddr_in addr;
  int sockfd, portno, n;
  char buffer[MAX_BUFF_SIZE];

  // Initialize the address struct
  memset((char *)&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[1]));
  addr.sin_addr.s_addr = inet_addr(argv[2]);

  // Create the socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send some data
  printf("Sending data...\n");
  send(sockfd, buffer, MAX_BUFF_SIZE, 0);

  // Receive some data
  printf("Receiving data...\n");
  n = recv(sockfd, buffer, MAX_BUFF_SIZE, 0);
  if (n < 0) {
    perror("ERROR receiving");
    exit(1);
  }

  // Close the socket
  printf("Closing socket...\n");
  close(sockfd);

  return 0;
}