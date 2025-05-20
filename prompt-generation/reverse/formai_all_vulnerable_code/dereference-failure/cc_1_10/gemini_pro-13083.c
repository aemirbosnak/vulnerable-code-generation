//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  char buffer[MAX_BUFFER_SIZE];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server_ip> <port_number>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    perror("ERROR converting server IP address");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting to server");
    exit(1);
  }

  printf("Connected to server at %s:%d\n", argv[1], portno);

  while (1) {
    printf("Enter message to send to server: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      perror("ERROR sending message to server");
      break;
    }

    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
      perror("ERROR receiving message from server");
      break;
    }

    printf("Message from server: %s\n", buffer);
  }

  close(sockfd);

  return 0;
}