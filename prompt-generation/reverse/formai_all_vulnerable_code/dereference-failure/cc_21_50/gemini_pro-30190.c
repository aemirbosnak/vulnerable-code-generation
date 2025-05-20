//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  // Check for arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
    return 1;
  }

  // Get server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid server address: %s\n", argv[1]);
    return 1;
  }

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Read server greeting
  char buffer[1024];
  if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
    perror("recv");
    return 1;
  }

  // Send USER command
  sprintf(buffer, "USER %s\r\n", argv[2]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read server response
  if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
    perror("recv");
    return 1;
  }

  // Send PASS command
  sprintf(buffer, "PASS %s\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read server response
  if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
    perror("recv");
    return 1;
  }

  // Send STAT command
  if (send(sockfd, "STAT\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read server response
  if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
    perror("recv");
    return 1;
  }

  // Parse server response
  int num_messages, total_size;
  sscanf(buffer, "+OK %d %d", &num_messages, &total_size);

  // Send LIST command
  if (send(sockfd, "LIST\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read server response
  for (int i = 0; i < num_messages; i++) {
    if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
      perror("recv");
      return 1;
    }

    int message_number, message_size;
    sscanf(buffer, "%d %d", &message_number, &message_size);

    printf("Message %d: %d bytes\n", message_number, message_size);
  }

  // Send RETR command
  int message_number = 1;
  sprintf(buffer, "RETR %d\r\n", message_number);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read server response
  FILE *fp = fopen("message.txt", "w");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  while (1) {
    if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
      perror("recv");
      return 1;
    }

    int len = strlen(buffer);
    if (strncmp(buffer, ".\r\n", 3) == 0) {
      break;
    }

    fwrite(buffer, 1, len, fp);
  }

  fclose(fp);

  // Send QUIT command
  if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Close socket
  close(sockfd);

  return 0;
}