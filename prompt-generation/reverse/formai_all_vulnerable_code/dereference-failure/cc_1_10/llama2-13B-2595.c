//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main() {
  int sock, port, i;
  struct sockaddr_in server_addr;
  char buffer[1024];

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  // Set address and port
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(0);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  // Bind the socket to the address and port
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Binding failed");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sock, PORT_RANGE) < 0) {
    perror("Listening failed");
    exit(1);
  }

  // Loop to handle incoming connections
  for (i = 0; i < PORT_RANGE; i++) {
    // Accept an incoming connection
    if ((sock = accept(sock, NULL, NULL)) < 0) {
      perror("Accept failed");
      continue;
    }

    // Print the client's IP address and port
    printf("Client IP: %s, Port: %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

    // Send a random message to the client
    srand(time(NULL));
    int message_len = rand() % 1000;
    char *message = malloc(message_len);
    for (int j = 0; j < message_len; j++) {
      message[j] = rand() % 26 + 'a';
    }
    send(sock, message, message_len, 0);

    // Receive a response from the client
    recv(sock, buffer, 1024, 0);

    // Print the response
    printf("Client Response: %s\n", buffer);

    // Close the socket
    close(sock);
  }

  return 0;
}