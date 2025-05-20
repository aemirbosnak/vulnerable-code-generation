//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFSIZE];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: No such host\n");
    exit(0);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: Socket");
    exit(0);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error: Connect");
    exit(0);
  }

  while (1) {
    memset(buffer, 0, BUFSIZE);
    printf("Enter command: ");
    fgets(buffer, BUFSIZE, stdin);

    if (strcmp(buffer, "exit\n") == 0) {
      break;
    }

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      perror("Error: Send");
      exit(0);
    }

    memset(buffer, 0, BUFSIZE);
    if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
      perror("Error: Receive");
      exit(0);
    }

    printf("%s", buffer);
  }

  close(sockfd);
  return 0;
}