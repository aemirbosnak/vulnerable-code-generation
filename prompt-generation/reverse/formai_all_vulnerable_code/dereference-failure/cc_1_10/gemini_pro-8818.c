//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Resolve the hostname to an IP address
  struct hostent *host = gethostbyname(hostname);
  if (!host) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Create a socket for communicating with the FTP server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the FTP server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr = *(struct in_addr *)host->h_addr;
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the USER command to the FTP server
  const char *user = "user";
  send(sockfd, "USER ", 5, 0);
  send(sockfd, user, strlen(user), 0);
  send(sockfd, "\r\n", 2, 0);

  // Receive the response from the FTP server
  char buf[256];
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s", buf);

  // Send the PASS command to the FTP server
  const char *pass = "pass";
  send(sockfd, "PASS ", 5, 0);
  send(sockfd, pass, strlen(pass), 0);
  send(sockfd, "\r\n", 2, 0);

  // Receive the response from the FTP server
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s", buf);

  // Send the CWD command to the FTP server
  const char *cwd = "/tmp";
  send(sockfd, "CWD ", 4, 0);
  send(sockfd, cwd, strlen(cwd), 0);
  send(sockfd, "\r\n", 2, 0);

  // Receive the response from the FTP server
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s", buf);

  // Send the LIST command to the FTP server
  send(sockfd, "LIST\r\n", 6, 0);

  // Receive the response from the FTP server
  while (recv(sockfd, buf, sizeof(buf), 0) > 0) {
    printf("%s", buf);
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}