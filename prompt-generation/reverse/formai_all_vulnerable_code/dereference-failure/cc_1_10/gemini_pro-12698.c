//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define PORT 9999

void send_message(char *message, int sockfd) {
  int len = strlen(message);
  int sent = 0;
  while (sent < len) {
    int n = send(sockfd, message + sent, len - sent, 0);
    if (n == -1) {
      perror("send");
      exit(1);
    }
    sent += n;
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip address> <message>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Connect to the server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = inet_addr(argv[1]);
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the message to the server
  send_message(argv[2], sockfd);

  // Close the socket
  close(sockfd);

  return 0;
}