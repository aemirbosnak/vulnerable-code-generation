//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <resolv.h>

int main(void) {
  int sockfd;
  struct sockaddr_in serv_addr;
  char buf[1024];
  char *host = "www.example.com";
  char *port = "25";

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error creating socket: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  struct hostent *he;
  he = gethostbyname(host);
  if (he == NULL) {
    printf("Error resolving hostname: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(port));
  serv_addr.sin_addr = *((struct in_addr *)he->h_addr);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    printf("Error connecting to server: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  snprintf(buf, sizeof(buf), "HELO %s\r\n", host);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    printf("Error sending HELO command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", "sender@example.com");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    printf("Error sending MAIL FROM command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", "recipient@example.com");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    printf("Error sending RCPT TO command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  snprintf(buf, sizeof(buf), "DATA\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    printf("Error sending DATA command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  snprintf(buf, sizeof(buf), "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    printf("Error sending email body: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    printf("Error sending QUIT command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  close(sockfd);
  
  return 0;
}