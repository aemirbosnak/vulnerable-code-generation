//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <hostname> <filename>\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  char *filename = argv[2];

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    printf("Error: Could not resolve hostname %s\n", hostname);
    return 1;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error: Could not create socket");
    return 1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr = *((struct in_addr *)host->h_addr);

  int connect_status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status == -1) {
    perror("Error: Could not connect to server");
    close(sockfd);
    return 1;
  }

  char buffer[256];

  // Send the USER command
  snprintf(buffer, sizeof(buffer), "USER anonymous\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // Receive the response
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  // Send the PASS command
  snprintf(buffer, sizeof(buffer), "PASS anonymous@\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // Receive the response
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  // Send the CWD command
  snprintf(buffer, sizeof(buffer), "CWD /\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // Receive the response
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  // Send the RETR command
  snprintf(buffer, sizeof(buffer), "RETR %s\r\n", filename);
  send(sockfd, buffer, strlen(buffer), 0);

  // Receive the response
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  // Open the file
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("Error: Could not open file");
    close(sockfd);
    return 1;
  }

  // Receive the file data
  while (1) {
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
      perror("Error: Could not receive file data");
      close(sockfd);
      fclose(fp);
      return 1;
    }
    if (bytes_received == 0) {
      break;
    }
    fwrite(buffer, 1, bytes_received, fp);
  }

  // Close the file
  fclose(fp);

  // Send the QUIT command
  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // Close the socket
  close(sockfd);

  return 0;
}