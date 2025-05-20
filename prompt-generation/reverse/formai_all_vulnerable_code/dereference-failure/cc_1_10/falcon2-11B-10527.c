//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: excited
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Initialize socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket failed");
    return 1;
  }

  // Resolve server address
  server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr, "gethostbyname: nodename look-up failed\n");
    return 1;
  }

  // Assign socket to server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(80);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return 1;
  }

  printf("Connection established\n");

  // Read data from server
  char buffer[256];
  n = read(sockfd, buffer, 256);
  if (n <= 0) {
    perror("read");
    return 1;
  }
  printf("Received: %s\n", buffer);

  // Send data to server
  write(sockfd, "Hello, server!", 13);
  if (write(sockfd, "World!", 6) < 0) {
    perror("write");
    return 1;
  }

  // Close connection
  close(sockfd);

  return 0;
}