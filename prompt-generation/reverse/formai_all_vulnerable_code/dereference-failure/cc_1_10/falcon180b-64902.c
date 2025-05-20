//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TRUE 1
#define FALSE 0
#define PORT 7
#define TIMEOUT 5

int main(int argc, char *argv[]) {
  int sock, ret;
  struct sockaddr_in server;
  char hostname[MAX_HOSTNAME];
  char data[MAX_DATA];
  int datalen;
  struct timeval timeout;

  if (argc!= 3) {
    printf("Usage: %s <hostname> <data>\n", argv[0]);
    return 1;
  }

  strncpy(hostname, argv[1], MAX_HOSTNAME);
  strncpy(data, argv[2], MAX_DATA);

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock == -1) {
    printf("Error creating socket\n");
    return 1;
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  if (inet_pton(AF_INET, hostname, &server.sin_addr) <= 0) {
    printf("Error resolving hostname\n");
    close(sock);
    return 1;
  }

  timeout.tv_sec = TIMEOUT;
  timeout.tv_usec = 0;

  ret = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
  if (ret == -1) {
    printf("Error setting timeout\n");
    close(sock);
    return 1;
  }

  datalen = strlen(data);
  ret = sendto(sock, data, datalen, 0, (struct sockaddr *)&server, sizeof(server));
  if (ret <= 0) {
    printf("Error sending data\n");
    close(sock);
    return 1;
  }

  memset(data, 0, MAX_DATA);
  datalen = recv(sock, data, MAX_DATA, 0);
  if (datalen <= 0) {
    printf("Error receiving data\n");
    close(sock);
    return 1;
  }

  printf("Received: %s\n", data);

  close(sock);
  return 0;
}