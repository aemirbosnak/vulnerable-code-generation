//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PAYLOAD 1024

// Creates a socket and connects to the specified IP address and port.
int create_socket_and_connect(char* ip_address, int port) {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create a socket.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Set the server address.
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, ip_address, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return -1;
  }

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return -1;
  }

  return sockfd;
}

// Sends a request message and waits for a response message.
int send_and_receive(int sockfd, char* request_message, int wait_time) {
  int n;
  char response_message[MAX_PAYLOAD];

  // Send the request message.
  if (send(sockfd, request_message, strlen(request_message), 0) < 0) {
    perror("send");
    return -1;
  }

  // Wait for the response message.
  bzero(response_message, MAX_PAYLOAD);
  if (wait_time > 0) {
    fd_set readfds;
    struct timeval tv;

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    tv.tv_sec = wait_time;
    tv.tv_usec = 0;

    if (select(sockfd+1, &readfds, NULL, NULL, &tv) < 0) {
      perror("select");
      return -1;
    }

    if (!FD_ISSET(sockfd, &readfds)) {
      printf("No response received within %d seconds.\n", wait_time);
      return -1;
    }

    if ((n = recv(sockfd, response_message, MAX_PAYLOAD, 0)) < 0) {
      perror("recv");
      return -1;
    }
  }

  // Print the response message.
  printf("Response: %s\n", response_message);

  return 0;
}

// Performs a ping test by sending a request message and waiting for a response message.
int ping_test(char* ip_address, int port, int wait_time) {
  int sockfd;
  char request_message[MAX_PAYLOAD];

  // Create a socket and connect to the specified IP address and port.
  sockfd = create_socket_and_connect(ip_address, port);
  if (sockfd == -1) {
    return -1;
  }

  // Send a request message and wait for a response message.
  sprintf(request_message, "PING %s", ip_address);
  if (send_and_receive(sockfd, request_message, wait_time) == -1) {
    return -1;
  }

  // Close the socket.
  close(sockfd);

  return 0;
}

// Main function.
int main(int argc, char** argv) {
  if (argc != 4) {
    printf("Usage: %s <IP address> <port> <wait time>\n", argv[0]);
    return 1;
  }

  // Parse the command-line arguments.
  char* ip_address = argv[1];
  int port = atoi(argv[2]);
  int wait_time = atoi(argv[3]);

  // Perform the ping test.
  if (ping_test(ip_address, port, wait_time) == -1) {
    printf("Ping test failed.\n");
    return 1;
  }

  printf("Ping test successful.\n");

  return 0;
}