//LLAMA2-13B DATASET v1.0 Category: Browser Plugin ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MESSAGE_LENGTH 1024

int main(int argc, char *argv[]) {
  int sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char message[MAX_MESSAGE_LENGTH];

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  // Set up the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  // Bind the socket to the address and port
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Binding failed");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sock, 3) < 0) {
    perror("Listening failed");
    exit(1);
  }

  // Accept an incoming connection
  client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
  if (client_sock < 0) {
    perror("Accept failed");
    exit(1);
  }

  // Read the message from the client
  read(client_sock, message, MAX_MESSAGE_LENGTH);

  // Display the message on the user's browser
  printf("Received message from client: %s\n", message);

  // Send a copy of the message to the remote server
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(1);
  }
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8081);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Connecting failed");
    exit(1);
  }
  send(sock, message, strlen(message), 0);

  // Close the sockets
  close(sock);
  close(client_sock);

  return 0;
}