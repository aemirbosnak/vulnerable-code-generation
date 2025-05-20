//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error: could not create socket");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error: could not connect to server");
    return EXIT_FAILURE;
  }

  char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("Error: could not send request");
    return EXIT_FAILURE;
  }

  char buffer[1024];
  int nbytes;
  while ((nbytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    printf("%s", buffer);
  }

  if (nbytes == -1) {
    perror("Error: could not receive response");
    return EXIT_FAILURE;
  }

  close(sockfd);

  return EXIT_SUCCESS;
}