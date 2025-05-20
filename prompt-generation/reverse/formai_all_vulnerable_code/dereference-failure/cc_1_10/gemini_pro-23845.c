//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in servaddr;
  char sendline[MAX_LINE], recvline[MAX_LINE];

  if (argc != 3) {
    printf("usage: ./email_client <server_address> <port>\n");
    exit(1);
  }

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  // Resolve the server address
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Initialize the server address structure
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Send a message to the server
  printf("Enter the email body:\n");
  while (fgets(sendline, MAX_LINE, stdin) != NULL) {
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
      perror("send");
      exit(1);
    }
  }

  // Receive a message from the server
  if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print the received message
  printf("Received from the server:\n%s", recvline);

  // Close the socket
  close(sockfd);

  return 0;
}