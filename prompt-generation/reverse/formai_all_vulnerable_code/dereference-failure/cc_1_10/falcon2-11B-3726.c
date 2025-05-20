//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Initialize socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket creation failed");
    exit(1);
  }

  // Prepare server address structure
  server = gethostbyname("smtp.gmail.com");
  if (server == NULL) {
    perror("gethostbyname failed");
    exit(1);
  }

  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(25);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection failed");
    exit(1);
  }

  char buf[256] = "Subject: Test\r\nTo: user@example.com\r\nFrom: user@example.com\r\n\r\nHello World!\r\n";

  // Send email
  n = write(sockfd, buf, strlen(buf));
  if (n < 0) {
    perror("write failed");
    exit(1);
  }

  // Close socket
  close(sockfd);
  return 0;
}