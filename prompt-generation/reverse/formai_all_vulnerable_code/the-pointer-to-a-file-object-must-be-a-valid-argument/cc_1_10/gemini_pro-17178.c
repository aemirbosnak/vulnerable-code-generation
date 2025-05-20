//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_LINE 1024

void usage(char *name) {
  printf("Usage: %s <host> <user> <password>\n", name);
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    usage(argv[0]);
  }

  int sockfd;
  struct sockaddr_in servaddr;
  char line[MAX_LINE];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(POP3_PORT);
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Part 1: The POP3 conversation

  // Receive the greeting message
  if (fgets(line, MAX_LINE, sockfd) == NULL) {
    perror("fgets");
    exit(1);
  }

  // Send the USER command
  snprintf(line, MAX_LINE, "USER %s\r\n", argv[2]);
  if (send(sockfd, line, strlen(line), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the USER response
  if (fgets(line, MAX_LINE, sockfd) == NULL) {
    perror("fgets");
    exit(1);
  }

  // Send the PASS command
  snprintf(line, MAX_LINE, "PASS %s\r\n", argv[3]);
  if (send(sockfd, line, strlen(line), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the PASS response
  if (fgets(line, MAX_LINE, sockfd) == NULL) {
    perror("fgets");
    exit(1);
  }

  // Part 2: Listing messages

  // Send the LIST command
  if (send(sockfd, "LIST\r\n", 6, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the LIST response
  while (fgets(line, MAX_LINE, sockfd) != NULL) {
    if (line[0] == '.') {
      break;
    }

    printf("%s", line);
  }

  // Part 3: Retrieving a message

  // Send the RETR command with a message number
  if (send(sockfd, "RETR 1\r\n", 8, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the RETR response
  while (fgets(line, MAX_LINE, sockfd) != NULL) {
    if (line[0] == '.') {
      break;
    }

    printf("%s", line);
  }

  // Part 4: Deleting a message

  // Send the DELE command with a message number
  if (send(sockfd, "DELE 1\r\n", 8, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the DELE response
  if (fgets(line, MAX_LINE, sockfd) == NULL) {
    perror("fgets");
    exit(1);
  }

  // Part 5: Quitting

  // Send the QUIT command
  if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the QUIT response
  if (fgets(line, MAX_LINE, sockfd) == NULL) {
    perror("fgets");
    exit(1);
  }

  close(sockfd);
  return 0;
}