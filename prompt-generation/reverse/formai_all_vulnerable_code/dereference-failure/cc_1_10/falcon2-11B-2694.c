//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]) {
  // Create socket
  int sockfd, portno;
  struct sockaddr_in serv_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set up server address struct
  memset((char *)&serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(atoi(argv[1]));

  // Bind to the port
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 5);
  printf("Waiting for connection\n");

  // Accept incoming connection
  int connfd = accept(sockfd, NULL, NULL);
  if (connfd < 0) {
    perror("ERROR on accept");
    exit(1);
  }

  printf("Connection from: %s\n", inet_ntoa(serv_addr.sin_addr));

  char buffer[1024];
  int n;

  // Read data from client
  while ((n = read(connfd, buffer, sizeof(buffer))) > 0) {
    printf("Received: %s\n", buffer);
    sleep(1);
    write(connfd, buffer, n);
  }

  close(connfd);
  close(sockfd);
  return 0;
}