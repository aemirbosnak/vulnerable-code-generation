//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

void mind_bending_ftp_client(char *hostname, char *port) {
  struct sockaddr_in server_addr;
  int sockfd, bytes_received;
  char buffer[1024], command[100];

  // Establish the connection to the FTP server
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(port));
  if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
    perror("Error converting hostname to IP address");
    return;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    return;
  }

  // Receive the welcome message from the FTP server
  bytes_received = recv(sockfd, buffer, 1024, 0);
  if (bytes_received < 0) {
    perror("Error receiving welcome message");
    return;
  }

  printf("%s", buffer);

  // Send the username to the FTP server
  sprintf(command, "USER anonymous\r\n");
  if (send(sockfd, command, strlen(command), 0) < 0) {
    perror("Error sending username");
    return;
  }

  // Receive the response from the FTP server
  bytes_received = recv(sockfd, buffer, 1024, 0);
  if (bytes_received < 0) {
    perror("Error receiving response");
    return;
  }

  printf("%s", buffer);

  // Send the password to the FTP server
  sprintf(command, "PASS anonymous@example.com\r\n");
  if (send(sockfd, command, strlen(command), 0) < 0) {
    perror("Error sending password");
    return;
  }

  // Receive the response from the FTP server
  bytes_received = recv(sockfd, buffer, 1024, 0);
  if (bytes_received < 0) {
    perror("Error receiving response");
    return;
  }

  printf("%s", buffer);

  // Send the LIST command to the FTP server
  strcpy(command, "LIST\r\n");
  if (send(sockfd, command, strlen(command), 0) < 0) {
    perror("Error sending LIST command");
    return;
  }

  // Receive the response from the FTP server
  while ((bytes_received = recv(sockfd, buffer, 1024, 0)) > 0) {
    printf("%s", buffer);
  }

  // Close the connection to the FTP server
  close(sockfd);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }

  mind_bending_ftp_client(argv[1], argv[2]);

  return 0;
}