//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: No such host\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: Could not create socket\n");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: Could not connect to server\n");
    exit(1);
  }

  printf("Connected to server\n");

  while (1) {
    memset(buffer, 0, sizeof(buffer));
    printf("Enter command: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      fprintf(stderr, "Error: Could not send data to server\n");
      exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      fprintf(stderr, "Error: Could not receive data from server\n");
      exit(1);
    }

    printf("Received from server: %s\n", buffer);
  }

  close(sockfd);
  return 0;
}