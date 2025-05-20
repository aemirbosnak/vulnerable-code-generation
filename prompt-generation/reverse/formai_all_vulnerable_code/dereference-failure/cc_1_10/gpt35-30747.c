//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: genious
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  char buffer[BUF_SIZE];

  struct addrinfo hints, *servinfo, *p;
  int rv;
  char *server_addr = argv[1];
  char *port = argv[2];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(server_addr, port, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype,
        p->ai_protocol)) == -1) {
      perror("socket");
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("connect");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "failed to connect\n");
    return 2;
  }

  freeaddrinfo(servinfo);

  while(1) {
    printf("Enter a message to send to server: ");
    fgets(buffer, BUF_SIZE, stdin);

    // Send message to server
    if ((send(sockfd, buffer, strlen(buffer), 0)) == -1) {
      fprintf(stderr, "Error sending message\n");
      break;
    }

    // Receive response from server
    if ((n = recv(sockfd, buffer, BUF_SIZE-1, 0)) == -1) {
      perror("recv");
      break;
    }

    if (n == 0) {
      fprintf(stderr, "Connection closed\n");
      break;
    }

    buffer[n] = '\0';

    printf("Server response: %s\n", buffer);
  }

  close(sockfd);
  return 0;
}