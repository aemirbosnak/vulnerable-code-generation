//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: mind-bending
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct hostent *serverInfo;
  char buffer[MAXLINE];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
    exit(1);
  }

  serverInfo = gethostbyname(argv[1]);
  if (serverInfo == NULL) {
    fprintf(stderr, "Error: could not resolve host %s\n", argv[1]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error: could not create socket");
    exit(1);
  }

  struct sockaddr_in serverAddress;
  memset(&serverAddress, 0, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  memcpy(&serverAddress.sin_addr.s_addr, serverInfo->h_addr, serverInfo->h_length);
  serverAddress.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
    perror("Error: could not connect to server");
    exit(1);
  }

  while (1) {
    printf("Enter a message to send to the server (or \"quit\" to exit): ");
    fgets(buffer, MAXLINE, stdin);

    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }

    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
      perror("Error: could not write to server");
      exit(1);
    }

    n = read(sockfd, buffer, MAXLINE);
    if (n == -1) {
      perror("Error: could not read from server");
      exit(1);
    }

    printf("Received from server: %s\n", buffer);
  }

  close(sockfd);

  return 0;
}