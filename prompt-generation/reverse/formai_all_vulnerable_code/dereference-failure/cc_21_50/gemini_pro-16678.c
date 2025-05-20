//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  char *username = argv[2];
  char *password = argv[3];

  struct hostent *host = gethostbyname(hostname);
  if (!host) {
    fprintf(stderr, "Error: could not resolve hostname '%s'\n", hostname);
    exit(1);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: could not create socket");
    exit(1);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error: could not connect to server");
    exit(1);
  }

  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) < 0) {
    perror("Error: could not receive data from server");
    exit(1);
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: unexpected response from server: '%s'\n", buffer);
    exit(1);
  }

  sprintf(buffer, "USER %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error: could not send data to server");
    exit(1);
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) < 0) {
    perror("Error: could not receive data from server");
    exit(1);
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: unexpected response from server: '%s'\n", buffer);
    exit(1);
  }

  sprintf(buffer, "PASS %s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error: could not send data to server");
    exit(1);
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) < 0) {
    perror("Error: could not receive data from server");
    exit(1);
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: unexpected response from server: '%s'\n", buffer);
    exit(1);
  }

  sprintf(buffer, "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error: could not send data to server");
    exit(1);
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) < 0) {
    perror("Error: could not receive data from server");
    exit(1);
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: unexpected response from server: '%s'\n", buffer);
    exit(1);
  }

  int num_messages = 0;
  char *message_list = buffer + 3;
  char *message_start = message_list;
  while (*message_list != '\n') {
    if (*message_list == '.') {
      num_messages++;
      message_start = message_list + 1;
    }
    message_list++;
  }

  printf("Number of messages: %d\n", num_messages);
  for (int i = 0; i < num_messages; i++) {
    printf("Message %d: %s\n", i + 1, message_start);
    message_start = strchr(message_start, '\n') + 1;
  }

  sprintf(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error: could not send data to server");
    exit(1);
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) < 0) {
    perror("Error: could not receive data from server");
    exit(1);
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: unexpected response from server: '%s'\n", buffer);
    exit(1);
  }

  close(sockfd);

  return 0;
}