//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server> <port> <message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve the server's address
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
    return EXIT_FAILURE;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the message
  char buf[BUFSIZE];
  snprintf(buf, BUFSIZE, "EHLO localhost\r\nMAIL FROM: <%s>\r\nRCPT TO: <%s>\r\nDATA\r\n%s\r\n.\r\nQUIT\r\n", "sender@localhost", "recipient@localhost", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  memset(buf, 0, BUFSIZE);
  if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the response
  printf("%s", buf);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}