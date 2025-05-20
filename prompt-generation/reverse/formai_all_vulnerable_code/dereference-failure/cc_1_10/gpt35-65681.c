//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Check for correct command line arguments
  if (argc < 3) {
    printf("Usage: %s <hostname> <port number>\n", argv[0]);
    exit(0);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  // Get server details
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error, no such host\n");
    exit(0);
  }

  // Set server address details
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  portno = atoi(argv[2]);
  serv_addr.sin_port = htons(portno);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send SMTP commands to the server
  char buffer[256];
  bzero(buffer, 256);
  // Read server response
  read(sockfd, buffer, 255);
  printf("Server Response: %s", buffer);

  // Send HELO command
  sprintf(buffer, "HELO %s\r\n", argv[1]);
  write(sockfd, buffer, strlen(buffer));
  // Read server response
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("Server Response: %s", buffer);

  // Send MAIL FROM command
  sprintf(buffer, "MAIL FROM:<example@domain.com>\r\n");
  write(sockfd, buffer, strlen(buffer));
  // Read server response
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("Server Response: %s", buffer);

  // Send RCPT TO command
  sprintf(buffer, "RCPT TO:<recipient@domain.com>\r\n");
  write(sockfd, buffer, strlen(buffer));
  // Read server response
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("Server Response: %s", buffer);

  // Send DATA command
  sprintf(buffer, "DATA\r\n");
  write(sockfd, buffer, strlen(buffer));
  // Read server response
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("Server Response: %s", buffer);

  // Send email body
  sprintf(buffer, "Subject: Testing SMTP Client\r\n\r\nHello,\r\nThis is a test email from SMTP client\r\n.\r\n");
  write(sockfd, buffer, strlen(buffer));
  // Read server response
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("Server Response: %s", buffer);

  // Send QUIT command
  sprintf(buffer, "QUIT\r\n");
  write(sockfd, buffer, strlen(buffer));
  // Read server response
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("Server Response: %s", buffer);

  close(sockfd);
  return 0;
}