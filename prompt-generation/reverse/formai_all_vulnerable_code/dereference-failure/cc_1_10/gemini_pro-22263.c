//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char** argv) {
  int sockfd, newsockfd, valread;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t len;
  char buffer[1024] = {0};
  
  // Create a TCP socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket creation failed");
    exit(1);
  }
  printf("Socket created\n");

  // Set the socket options
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

  // Bind the socket to the port
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
    perror("bind failed");
    exit(1);
  }
  printf("Socket binded\n");

  // Listen for connections
  if (listen(sockfd, 5) != 0) {
    perror("listen failed");
    exit(1);
  }
  printf("Socket listening\n");

  // Accept a connection
  len = sizeof(cliaddr);
  newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
  if (newsockfd < 0) {
    perror("accept failed");
    exit(1);
  }
  printf("Socket accepted\n");

  // Read the message from the client
  valread = read(newsockfd, buffer, 1024);
  if (valread < 0) {
    perror("read failed");
    exit(1);
  }
  printf("Message received: %s\n", buffer);

  // Write the message back to the client
  write(newsockfd, buffer, strlen(buffer));

  // Close the sockets
  close(newsockfd);
  close(sockfd);

  return 0;
}