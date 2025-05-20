//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME_LENGTH 1024
#define MAX_DATA_LENGTH 1024

int main(int argc, char *argv[]) {
  if (argc!= 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }

  char hostname[MAX_HOSTNAME_LENGTH] = { 0 };
  strncpy(hostname, argv[1], MAX_HOSTNAME_LENGTH - 1);

  int port = atoi(argv[2]);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error creating socket: %s\n", strerror(errno));
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
    printf("Invalid hostname or IP address\n");
    close(sockfd);
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Error connecting to server: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  char data[MAX_DATA_LENGTH] = { 0 };
  strncpy(data, "PING", MAX_DATA_LENGTH - 1);

  if (send(sockfd, data, strlen(data), 0) == -1) {
    printf("Error sending data: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  char buffer[MAX_DATA_LENGTH] = { 0 };
  int bytes_received = 0;

  while ((bytes_received = recv(sockfd, buffer, MAX_DATA_LENGTH - 1, 0)) > 0) {
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);
  }

  if (bytes_received == -1) {
    printf("Error receiving data: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  close(sockfd);
  return 0;
}