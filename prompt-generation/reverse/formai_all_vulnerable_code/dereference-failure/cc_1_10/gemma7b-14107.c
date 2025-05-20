//Gemma-7B DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  int sockfd;
  struct sockaddr_in server_addr;
  char buffer[MAX_BUFFER_SIZE];
  int num_chars;
  char *to_address;
  char *subject;
  char *message;

  to_address = malloc(256);
  subject = malloc(256);
  message = malloc(256);

  printf("Enter the recipient's email address: ");
  scanf("%s", to_address);

  printf("Enter the subject: ");
  scanf("%s", subject);

  printf("Enter the message: ");
  scanf("%[^\n]", message);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(25));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(25);
  server_addr.sin_addr.s_addr = inet_addr(to_address);

  connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  sprintf(buffer, "EHLO localhost\r\n");
  write(sockfd, buffer, strlen(buffer));

  sprintf(buffer, "MAIL FROM %s\r\n", "sender@example.com");
  write(sockfd, buffer, strlen(buffer));

  sprintf(buffer, "RCPT TO %s\r\n", to_address);
  write(sockfd, buffer, strlen(buffer));

  sprintf(buffer, "DATA\r\n");
  write(sockfd, buffer, strlen(buffer));

  write(sockfd, message, strlen(message));

  sprintf(buffer, "\r\n. . \r\n");
  write(sockfd, buffer, strlen(buffer));

  close(sockfd);

  return 0;
}