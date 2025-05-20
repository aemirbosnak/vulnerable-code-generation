//GEMINI-pro DATASET v1.0 Category: Networking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
  // Initialize the socket like a maestro preparing his symphony!
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Alas! Socket creation failed miserably!\n");
    return -1;
  }

  // Configure the server's address like a skilled architect designing a grand mansion!
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(atoi(argv[1]));

  // Bind the socket to the server's address like a jester clinging to his master!
  if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Alas! Socket binding failed like a clumsy acrobatic clown!\n");
    return -1;
  }

  // Listen for incoming connections like a watchful guard awaiting a royal procession!
  if (listen(sockfd, 5) < 0) {
    printf("Alas! Listening failed like a tuneless choir singing off-key!\n");
    return -1;
  }

  // Accept incoming connections like a gracious host welcoming guests!
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int connfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
  if (connfd < 0) {
    printf("Alas! Accepting connections failed like a broken bridge collapsing!\n");
    return -1;
  }

  // Read data from the client like a historian studying an ancient scroll!
  char buffer[1024];
  int n = read(connfd, buffer, sizeof(buffer));
  if (n < 0) {
    printf("Alas! Reading from the client failed like a failed attempt at a sonnet!\n");
    return -1;
  }

  // Write data back to the client like a scribe writing a royal decree!
  n = write(connfd, "Hello from the server!\n", 24);
  if (n < 0) {
    printf("Alas! Writing to the client failed like a misfired arrow!\n");
    return -1;
  }

  // Close the connections like a wise king sealing a treaty!
  close(sockfd);
  close(connfd);

  return 0;
}