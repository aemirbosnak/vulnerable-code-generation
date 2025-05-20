//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>

#define SMTP_PORT 25

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server> <recipient> <message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *server = argv[1];
  char *recipient = argv[2];
  char *message = argv[3];

  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int sfd, s;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  s = getaddrinfo(server, NULL, &hints, &result);
  if (s != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    return EXIT_FAILURE;
  }

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd == -1) {
      perror("socket");
      continue;
    }

    if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1) {
      break;
    }

    close(sfd);
  }

  if (rp == NULL) {
    fprintf(stderr, "Could not connect to server\n");
    return EXIT_FAILURE;
  }

  freeaddrinfo(result);

  char buffer[1024];

  s = snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
  if (s < 0) {
    perror("snprintf");
    close(sfd);
    return EXIT_FAILURE;
  }

  if (send(sfd, buffer, s, 0) != s) {
    perror("send");
    close(sfd);
    return EXIT_FAILURE;
  }

  s = snprintf(buffer, sizeof(buffer), "MAIL FROM: <sender@example.com>\r\n");
  if (s < 0) {
    perror("snprintf");
    close(sfd);
    return EXIT_FAILURE;
  }

  if (send(sfd, buffer, s, 0) != s) {
    perror("send");
    close(sfd);
    return EXIT_FAILURE;
  }

  s = snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", recipient);
  if (s < 0) {
    perror("snprintf");
    close(sfd);
    return EXIT_FAILURE;
  }

  if (send(sfd, buffer, s, 0) != s) {
    perror("send");
    close(sfd);
    return EXIT_FAILURE;
  }

  s = snprintf(buffer, sizeof(buffer), "DATA\r\n");
  if (s < 0) {
    perror("snprintf");
    close(sfd);
    return EXIT_FAILURE;
  }

  if (send(sfd, buffer, s, 0) != s) {
    perror("send");
    close(sfd);
    return EXIT_FAILURE;
  }

  s = snprintf(buffer, sizeof(buffer), "%s", message);
  if (s < 0) {
    perror("snprintf");
    close(sfd);
    return EXIT_FAILURE;
  }

  if (send(sfd, buffer, s, 0) != s) {
    perror("send");
    close(sfd);
    return EXIT_FAILURE;
  }

  s = snprintf(buffer, sizeof(buffer), ".\r\n");
  if (s < 0) {
    perror("snprintf");
    close(sfd);
    return EXIT_FAILURE;
  }

  if (send(sfd, buffer, s, 0) != s) {
    perror("send");
    close(sfd);
    return EXIT_FAILURE;
  }

  s = snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  if (s < 0) {
    perror("snprintf");
    close(sfd);
    return EXIT_FAILURE;
  }

  if (send(sfd, buffer, s, 0) != s) {
    perror("send");
    close(sfd);
    return EXIT_FAILURE;
  }

  close(sfd);

  return EXIT_SUCCESS;
}