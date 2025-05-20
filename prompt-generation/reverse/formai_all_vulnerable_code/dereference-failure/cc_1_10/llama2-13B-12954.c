//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server_addr = {
    .sin_family = AF_INET,
    .sin_port = htons(PORT),
    .sin_addr.s_addr = inet_addr("127.0.0.1")
  };

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect failed");
    exit(EXIT_FAILURE);
  }

  char buffer[BUFFER_SIZE];
  printf("Please enter a message: ");
  fgets(buffer, BUFFER_SIZE, stdin);

  // Send the message
  send(sock, buffer, strlen(buffer), 0);

  // Receive the response
  char *response = malloc(BUFFER_SIZE);
  recv(sock, response, BUFFER_SIZE, 0);

  // Print the response
  printf("Server response: %s\n", response);

  // Close the socket
  close(sock);

  return 0;
}

void* my_malloc(size_t size) {
  void* mem = malloc(size);
  if (mem == NULL) {
    perror("malloc failed");
    exit(EXIT_FAILURE);
  }
  return mem;
}

int my_send(int sock, const char* message, int len) {
  int sent = send(sock, message, len, 0);
  if (sent < 0) {
    perror("send failed");
    exit(EXIT_FAILURE);
  }
  return sent;
}

int my_recv(int sock, char* buffer, int len) {
  int received = recv(sock, buffer, len, 0);
  if (received < 0) {
    perror("recv failed");
    exit(EXIT_FAILURE);
  }
  return received;
}