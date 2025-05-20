//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Sockets stuff
#define MAX_SIZE 1024
#define PORT 25

// Email stuff
#define FROM "sender@example.com"
#define TO "recipient@example.com"
#define SUBJECT "Hello, world!"
#define BODY "This is an email sent from a C program."

int main() {
  // Let's start by getting the recipient's IP address
  struct hostent *host;
  host = gethostbyname(TO);
  if (host == NULL) {
    printf("Couldn't find the recipient's IP address.\n");
    return EXIT_FAILURE;
  }

  // Now let's create a socket
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Couldn't create a socket.\n");
    return EXIT_FAILURE;
  }

  // Let's connect to the recipient's mail server
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    printf("Couldn't connect to the mail server.\n");
    return EXIT_FAILURE;
  }

  // Let's establish a connection
  char buffer[MAX_SIZE];
  memset(buffer, 0, MAX_SIZE);
  recv(sockfd, buffer, MAX_SIZE, 0);
  printf("%s\n", buffer);
  send(sockfd, "HELO localhost\r\n", strlen("HELO localhost\r\n"), 0);
  memset(buffer, 0, MAX_SIZE);
  recv(sockfd, buffer, MAX_SIZE, 0);
  printf("%s\n", buffer);

  // Let's send the email
  send(sockfd, "MAIL FROM: <" FROM ">\r\n", strlen("MAIL FROM: <" FROM ">\r\n"), 0);
  memset(buffer, 0, MAX_SIZE);
  recv(sockfd, buffer, MAX_SIZE, 0);
  printf("%s\n", buffer);
  send(sockfd, "RCPT TO: <" TO ">\r\n", strlen("RCPT TO: <" TO ">\r\n"), 0);
  memset(buffer, 0, MAX_SIZE);
  recv(sockfd, buffer, MAX_SIZE, 0);
  printf("%s\n", buffer);
  send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);
  memset(buffer, 0, MAX_SIZE);
  recv(sockfd, buffer, MAX_SIZE, 0);
  printf("%s\n", buffer);

  // Let's build the email
  char email[MAX_SIZE];
  sprintf(
    email,
    "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.",
    FROM,
    TO,
    SUBJECT,
    BODY
  );

  // Let's send the email
  send(sockfd, email, strlen(email), 0);

  // Let's finish the email
  send(sockfd, ".\r\n", strlen(".\r\n"), 0);
  memset(buffer, 0, MAX_SIZE);
  recv(sockfd, buffer, MAX_SIZE, 0);
  printf("%s\n", buffer);

  // Let's quit
  send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
  memset(buffer, 0, MAX_SIZE);
  recv(sockfd, buffer, MAX_SIZE, 0);
  printf("%s\n", buffer);

  // Let's close the connection
  close(sockfd);

  return EXIT_SUCCESS;
}