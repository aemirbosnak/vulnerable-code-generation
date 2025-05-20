//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
  // Check if the correct number of arguments are provided
  if (argc!= 3) {
    printf("Usage: %s <IP_ADDRESS> <PORT>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Set up the address struct
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  // Get the IP address of the client
  char client_ip[INET_ADDRSTRLEN];
  if (inet_ntop(AF_INET, &(serv_addr.sin_addr), client_ip, INET_ADDRSTRLEN) == NULL) {
    perror("Error getting client IP address");
    return 1;
  }

  // Check if the client is allowed to connect
  if (strcmp(argv[1], client_ip) == 0) {
    printf("Client is allowed to connect\n");
  } else {
    printf("Client is not allowed to connect\n");
  }

  // Close the socket
  close(sockfd);
  return 0;
}