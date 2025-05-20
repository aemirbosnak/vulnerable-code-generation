//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define IMAP_PORT 143
#define IMAP_BUF_SIZE 4096

/* Romeo and Juliet's tragic love story, reimagined as an IMAP client. */
int main(int argc, char** argv)
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char* hostname = argv[1];
  char* username = argv[2];

  /* Romeo's tragic tale begins here. */
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct hostent* hostinfo = gethostbyname(hostname);
  if (hostinfo == NULL) {
    fprintf(stderr, "gethostbyname: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr.s_addr, hostinfo->h_addr, hostinfo->h_length);
  server_addr.sin_port = htons(IMAP_PORT);

  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  /* Romeo and Juliet exchange greetings. */
  char buf[IMAP_BUF_SIZE];
  recv(sockfd, buf, IMAP_BUF_SIZE - 1, 0);
  printf("%s", buf);

  snprintf(buf, IMAP_BUF_SIZE - 1, "CAPABILITY\r\n");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, IMAP_BUF_SIZE - 1, 0);
  printf("%s", buf);

  snprintf(buf, IMAP_BUF_SIZE - 1, "LOGIN %s\r\n", username);
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, IMAP_BUF_SIZE - 1, 0);
  printf("%s", buf);

  /* Their love blooms in the inbox. */
  snprintf(buf, IMAP_BUF_SIZE - 1, "SELECT INBOX\r\n");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, IMAP_BUF_SIZE - 1, 0);
  printf("%s", buf);

  /* But fate conspires against them. */
  snprintf(buf, IMAP_BUF_SIZE - 1, "FETCH 1 BODY[TEXT]\r\n");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, IMAP_BUF_SIZE - 1, 0);
  printf("\n%s", buf);

  /* Their love ends in tragedy. */
  snprintf(buf, IMAP_BUF_SIZE - 1, "LOGOUT\r\n");
  send(sockfd, buf, strlen(buf), 0);
  recv(sockfd, buf, IMAP_BUF_SIZE - 1, 0);
  printf("%s", buf);

  close(sockfd);
  return EXIT_SUCCESS;
}