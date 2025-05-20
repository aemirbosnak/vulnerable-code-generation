//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  int sockfd, n;
  char buffer[BUF_SIZE];
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if(argc < 2) {
    fprintf(stderr, "Usage: %s hostname\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  /* create socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0) {
    fprintf(stderr, "Error: Failed to create socket\n");
    exit(EXIT_FAILURE);
  }

  /* get server info */
  server = gethostbyname(argv[1]);

  if(server == NULL) {
    fprintf(stderr, "Error: Failed to get server info\n");
    exit(EXIT_FAILURE);
  }

  /* set server address */
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(143); /* IMAP port */

  /* establish connection */
  if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: Failed to connect to server\n");
    exit(EXIT_FAILURE);
  }

  /* receive greeting message */
  n = recv(sockfd, buffer, sizeof(buffer), 0);

  if(n < 0) {
    fprintf(stderr, "Error: Failed to receive message from server\n");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);

  /* send login command */
  sprintf(buffer, "LOGIN username password\r\n");

  if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
    fprintf(stderr, "Error: Failed to send message to server\n");
    exit(EXIT_FAILURE);
  }

  /* receive login result */
  n = recv(sockfd, buffer, sizeof(buffer), 0);

  if(n < 0) {
    fprintf(stderr, "Error: Failed to receive message from server\n");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);

  /* send logout command */
  sprintf(buffer, "LOGOUT\r\n");

  if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
    fprintf(stderr, "Error: Failed to send message to server\n");
    exit(EXIT_FAILURE);
  }

  /* receive logout result */
  n = recv(sockfd, buffer, sizeof(buffer), 0);

  if(n < 0) {
    fprintf(stderr, "Error: Failed to receive message from server\n");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);

  /* close socket */
  close(sockfd);

  return EXIT_SUCCESS;
}