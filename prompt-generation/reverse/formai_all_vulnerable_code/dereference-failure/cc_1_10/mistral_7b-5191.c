//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 1024

bool ping(const char *ip_address) {
  int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
  if (sockfd < 0) {
    perror("socket");
    return false;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
  server_addr.sin_port = htons(SERVER_PORT);

  char buffer[BUFFER_SIZE];
  ssize_t sent = sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (sent < 0) {
    perror("sendto");
    close(sockfd);
    return false;
  }

  fd_set read_fds;
  FD_ZERO(&read_fds);
  FD_SET(sockfd, &read_fds);

  struct timeval timeout = {0, 500};
  int result = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);

  if (result < 0) {
    perror("select");
    close(sockfd);
    return false;
  }

  ssize_t received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
  if (received < 0) {
    perror("recvfrom");
    close(sockfd);
    return false;
  }

  close(sockfd);

  if (strncmp(buffer, "PONG", 4) == 0) {
    return true;
  }

  return false;
}

void print_ip_address(const char *ip_address) {
  struct addrinfo hints, *result;
  int error = getaddrinfo("localhost", NULL, &hints, &result);
  if (error != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
    return;
  }

  char hostname[NI_MAXHOST];
  getnameinfo(result->ai_addr, result->ai_addrlen, hostname, sizeof(hostname), NULL, 0, NI_NUMERICHOST);
  printf("%s -> %s\n", ip_address, hostname);
  freeaddrinfo(result);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  print_ip_address(argv[1]);
  bool status = ping(argv[1]);
  printf("%s: %s\n", argv[1], status ? "UP" : "DOWN");

  return EXIT_SUCCESS;
}