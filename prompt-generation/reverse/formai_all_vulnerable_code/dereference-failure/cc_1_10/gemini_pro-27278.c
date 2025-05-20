//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 110

int main(int argc, char **argv) {
  char *hostname, *username, *password;

  if (argc != 4) {
    fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  hostname = argv[1];
  username = argv[2];
  password = argv[3];

  // Establish a connection to the POP3 server
  struct hostent *hostinfo = gethostbyname(hostname);
  if (hostinfo == NULL) {
    fprintf(stderr, "Host not found: %s\n", hostname);
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    fprintf(stderr, "Unable to create socket\n");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr, hostinfo->h_addr, hostinfo->h_length);
  server_addr.sin_port = htons(PORT);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    fprintf(stderr, "Unable to connect to server: %s\n", hostname);
    exit(EXIT_FAILURE);
  }

  // Authenticate with the server
  char response[1024];
  recv(sockfd, response, sizeof(response), 0);
  printf("%s\n", response);

  char auth[1024];
  snprintf(auth, sizeof(auth), "USER %s\r\n", username);
  send(sockfd, auth, strlen(auth), 0);
  recv(sockfd, response, sizeof(response), 0);
  printf("%s\n", response);

  snprintf(auth, sizeof(auth), "PASS %s\r\n", password);
  send(sockfd, auth, strlen(auth), 0);
  recv(sockfd, response, sizeof(response), 0);
  printf("%s\n", response);

  // Retrieve the list of messages
  char stat[1024];
  snprintf(stat, sizeof(stat), "STAT\r\n");
  send(sockfd, stat, strlen(stat), 0);
  recv(sockfd, response, sizeof(response), 0);
  printf("%s\n", response);

  char list[1024];
  snprintf(list, sizeof(list), "LIST\r\n");
  send(sockfd, list, strlen(list), 0);
  recv(sockfd, response, sizeof(response), 0);
  printf("%s\n", response);

  // Retrieve a specific message
  char retrive[1024];
  snprintf(retrive, sizeof(retrive), "RETR 1\r\n");
  send(sockfd, retrive, strlen(retrive), 0);
  recv(sockfd, response, sizeof(response), 0);
  printf("%s\n", response);

  // Quit the session
  char quit[1024];
  snprintf(quit, sizeof(quit), "QUIT\r\n");
  send(sockfd, quit, strlen(quit), 0);
  recv(sockfd, response, sizeof(response), 0);
  printf("%s\n", response);

  close(sockfd);

  return EXIT_SUCCESS;
}