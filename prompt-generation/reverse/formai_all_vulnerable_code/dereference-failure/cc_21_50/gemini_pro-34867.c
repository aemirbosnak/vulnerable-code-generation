//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define SMTP_PORT "25"

int main() {
  int sockfd;
  struct addrinfo hints, *result, *rp;
  const char *hostname = "smtp.example.com";
  char *line, *buffer;
  int n;
  size_t len;

  /* Initialize hints structure for getaddrinfo() */
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  /* Get address information for hostname */
  if (getaddrinfo(hostname, SMTP_PORT, &hints, &result)) {
    perror("getaddrinfo");
    exit(EXIT_FAILURE);
  }

  /* Try each result until we find a connection */
  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sockfd == -1) {
      continue;
    }

    if (connect(sockfd, rp->ai_addr, rp->ai_addrlen)) {
      close(sockfd);
      continue;
    }

    break;
  }

  if (rp == NULL) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(result);

  /* Read and discard initial server greeting */
  line = malloc(256);
  if (!line) {
    perror("malloc");
    return EXIT_FAILURE;
  }
  while (n = read(sockfd, line, 256)) {
    printf("%s", line);
    if (line[n - 1] == '\n')
      break;
  }
  free(line);

  /* Send HELO command */
  buffer = malloc(256);
  if (!buffer) {
    perror("malloc");
    return EXIT_FAILURE;
  }
  sprintf(buffer, "HELO %s\r\n", hostname);
  if (write(sockfd, buffer, strlen(buffer)) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  /* Read server response to HELO command */
  line = malloc(256);
  if (!line) {
    perror("malloc");
    return EXIT_FAILURE;
  }
  while (n = read(sockfd, line, 256)) {
    printf("%s", line);
    if (line[n - 1] == '\n')
      break;
  }
  free(line);

  /* Send MAIL FROM command */
  sprintf(buffer, "MAIL FROM: <sender@example.com>\r\n");
  if (write(sockfd, buffer, strlen(buffer)) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  /* Read server response to MAIL FROM command */
  line = malloc(256);
  if (!line) {
    perror("malloc");
    return EXIT_FAILURE;
  }
  while (n = read(sockfd, line, 256)) {
    printf("%s", line);
    if (line[n - 1] == '\n')
      break;
  }
  free(line);

  /* Send RCPT TO command */
  sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
  if (write(sockfd, buffer, strlen(buffer)) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  /* Read server response to RCPT TO command */
  line = malloc(256);
  if (!line) {
    perror("malloc");
    return EXIT_FAILURE;
  }
  while (n = read(sockfd, line, 256)) {
    printf("%s", line);
    if (line[n - 1] == '\n')
      break;
  }
  free(line);

  /* Send DATA command */
  if (write(sockfd, "DATA\r\n", 5) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  /* Read server response to DATA command */
  line = malloc(256);
  if (!line) {
    perror("malloc");
    return EXIT_FAILURE;
  }
  while (n = read(sockfd, line, 256)) {
    printf("%s", line);
    if (line[n - 1] == '\n')
      break;
  }
  free(line);

  /* Send email message */
  len = getline(&buffer, &len, stdin);
  while (len != -1) {
    if (len > 2 && strncmp(buffer, ".\r\n", 3) == 0)
      break;
    if (write(sockfd, buffer, len) < 0) {
      perror("write");
      return EXIT_FAILURE;
    }
    len = getline(&buffer, &len, stdin);
  }
  free(buffer);

  /* Send QUIT command */
  if (write(sockfd, "QUIT\r\n", 5) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  /* Read server response to QUIT command */
  line = malloc(256);
  if (!line) {
    perror("malloc");
    return EXIT_FAILURE;
  }
  while (n = read(sockfd, line, 256)) {
    printf("%s", line);
    if (line[n - 1] == '\n')
      break;
  }
  free(line);

  close(sockfd);

  return EXIT_SUCCESS;
}