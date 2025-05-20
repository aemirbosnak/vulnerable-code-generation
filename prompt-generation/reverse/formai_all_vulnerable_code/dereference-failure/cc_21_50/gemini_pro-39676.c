//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *server = argv[1];
  char *username = argv[2];

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  if (strstr(line, "+OK") == NULL) {
    fprintf(stderr, "Error: %s\n", line);
    return EXIT_FAILURE;
  }

  snprintf(line, MAX_LINE_LENGTH, "USER %s\r\n", username);
  if (send(sockfd, line, strlen(line), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  if (strstr(line, "+OK") == NULL) {
    fprintf(stderr, "Error: %s\n", line);
    return EXIT_FAILURE;
  }

  snprintf(line, MAX_LINE_LENGTH, "PASS %s\r\n", argv[2]);
  if (send(sockfd, line, strlen(line), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  if (strstr(line, "+OK") == NULL) {
    fprintf(stderr, "Error: %s\n", line);
    return EXIT_FAILURE;
  }

  snprintf(line, MAX_LINE_LENGTH, "STAT\r\n");
  if (send(sockfd, line, strlen(line), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  if (strstr(line, "+OK") == NULL) {
    fprintf(stderr, "Error: %s\n", line);
    return EXIT_FAILURE;
  }

  int num_messages = atoi(strtok(line, " "));
  int total_size = atoi(strtok(NULL, " "));

  printf("Number of messages: %d\n", num_messages);
  printf("Total size: %d\n", total_size);

  for (int i = 1; i <= num_messages; i++) {
    snprintf(line, MAX_LINE_LENGTH, "RETR %d\r\n", i);
    if (send(sockfd, line, strlen(line), 0) == -1) {
      perror("send");
      return EXIT_FAILURE;
    }

    FILE *fp = fopen(strtok(line, " "), "w");
    if (fp == NULL) {
      perror("fopen");
      return EXIT_FAILURE;
    }

    while (1) {
      if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
      }

      if (strstr(line, "\r\n.\r\n") != NULL) {
        break;
      }

      fprintf(fp, "%s", line);
    }

    fclose(fp);
  }

  snprintf(line, MAX_LINE_LENGTH, "QUIT\r\n");
  if (send(sockfd, line, strlen(line), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  if (strstr(line, "+OK") == NULL) {
    fprintf(stderr, "Error: %s\n", line);
    return EXIT_FAILURE;
  }

  close(sockfd);
  return EXIT_SUCCESS;
}