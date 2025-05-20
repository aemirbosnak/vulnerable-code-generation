//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main() {
  int sockfd, valread, addrlen;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Step 1: Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Step 2: Get the server's address
  server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  memcpy((char *)&serv_addr, server->h_addr, server->h_length);

  // Step 3: Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Step 4: Send data to the server
  char message[] = "Hello, World!";
  send(sockfd, message, strlen(message), 0);

  // Step 5: Receive data from the server
  valread = recv(sockfd, NULL, 0, 0);
  if (valread < 0) {
    perror("ERROR receiving data");
    exit(1);
  }

  // Step 6: Print the received data
  printf("%s", (char *)malloc(valread));
  free(malloc(valread));

  // Step 7: Close the socket
  close(sockfd);

  return 0;
}