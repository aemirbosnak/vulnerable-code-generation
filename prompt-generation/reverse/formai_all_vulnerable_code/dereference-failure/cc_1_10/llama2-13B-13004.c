//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(void) {
  int sock, client_sock;
  struct sockaddr_in server, client;
  socklen_t client_len = sizeof(client);
  char buffer[256];

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  // Set up the server address
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT);

  // Bind the socket to the address and port
  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Binding failed");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sock, 3) < 0) {
    perror("Listening failed");
    exit(1);
  }

  printf("Listening on port %d...\n", PORT);

  // Accept an incoming connection
  client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
  if (client_sock < 0) {
    perror("Accept failed");
    exit(1);
  }

  printf("Connection accepted from %s:%d\n",
         inet_ntoa(client.sin_addr), ntohs(client.sin_port));

  // Loop until the client sends a message
  while (1) {
    // Receive a message from the client
    recv(client_sock, buffer, 255, 0);

    // Print the message
    printf("Received message from client: %s\n", buffer);

    // Send a response back to the client
    char* message = "You said: ";
    message = message + strlen(message);
    strcat(message, buffer);
    send(client_sock, message, strlen(message), 0);

    // Check if the client has closed the connection
    if (recv(client_sock, buffer, 1, 0) < 1) {
      printf("Client has closed the connection\n");
      break;
    }
  }

  // Close the socket
  close(client_sock);

  return 0;
}