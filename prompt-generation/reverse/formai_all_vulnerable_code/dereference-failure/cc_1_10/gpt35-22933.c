//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LINE 4096

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {

  int sockfd, portno, n;
  char buffer[MAX_LINE];
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc < 3) {
    fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    error("ERROR opening socket");
  }

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
       (char *)&serv_addr.sin_addr.s_addr,
            server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    error("ERROR connecting");
  }

  // Send User credentials
  printf("Enter Username: ");
  bzero(buffer, MAX_LINE);
  fgets(buffer, MAX_LINE, stdin);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  printf("Enter Password: ");
  bzero(buffer, MAX_LINE);
  fgets(buffer, MAX_LINE, stdin);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // Read server response
  bzero(buffer, MAX_LINE);
  n = read(sockfd, buffer, MAX_LINE);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  
  // If response contains OK, proceed with command
  if (strstr(buffer, "OK")) {
    printf("Enter Command: ");
    bzero(buffer, MAX_LINE);
    fgets(buffer, MAX_LINE, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
      error("ERROR writing to socket");
    }

    // Read server response
    bzero(buffer, MAX_LINE);
    n = read(sockfd, buffer, MAX_LINE);
    if (n < 0) {
      error("ERROR reading from socket");
    }

    printf("Server response: %s", buffer);
  }
  
  close(sockfd);
  return 0;
}