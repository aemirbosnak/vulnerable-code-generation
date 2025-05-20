//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

// A simple function to print the time
void printTime() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  printf("%02d:%02d:%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
}

// The main function
int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to an address
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    exit(1);
  }

  // Accept an incoming connection
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (clientfd == -1) {
    perror("accept");
    exit(1);
  }

  // Print the time
  printTime();

  // Send a message to the client
  char *message = "Elementary, my dear Watson!";
  if (send(clientfd, message, strlen(message), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Close the client socket
  close(clientfd);

  // Close the server socket
  close(sockfd);

  return 0;
}