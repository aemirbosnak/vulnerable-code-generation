//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  printf("Welcome to the Happy SMTP Client!\n");

  printf("Please enter the hostname of the SMTP server: ");
  scanf("%s", buffer);
  server = gethostbyname(buffer);
  if (server == NULL) {
    printf("Error: no such host\n");
    exit(0);
  }

  printf("Please enter the port number (usually 25): ");
  scanf("%d", &portno);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: could not open socket\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error: could not connect to server\n");
    exit(0);
  }

  printf("Connection established!\n");

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    printf("Error: could not read from server\n");
    exit(0);
  }

  printf("Response from server: %s\n", buffer);

  printf("Please enter the 'MAIL FROM:' address: ");
  scanf("%s", buffer);
  sprintf(buffer, "MAIL FROM: <%s>\r\n", buffer);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not write to server\n");
    exit(0);
  }

  printf("Please enter the 'RCPT TO:' address: ");
  scanf("%s", buffer);
  sprintf(buffer, "RCPT TO: <%s>\r\n", buffer);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not write to server\n");
    exit(0);
  }

  printf("Please enter the subject of the email: ");
  scanf("%s", buffer);
  sprintf(buffer, "Subject: %s\r\n", buffer);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not write to server\n");
    exit(0);
  }

  printf("Please enter the body of the email: ");
  scanf("%s", buffer);
  sprintf(buffer, "\r\n%s\r\n.\r\n", buffer);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not write to server\n");
    exit(0);
  }

  printf("Email sent!\n");

  close(sockfd);
  return 0;
}