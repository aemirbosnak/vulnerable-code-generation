//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: Sherlock Holmes
// A sinister case of a rogue socket, presented to the keen Mr. Holmes.

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Elementary, my dear Watson.
int main(int argc, char* argv[]) {
  int socket_descriptor, port_number;
  struct sockaddr_in server_address;
  struct hostent* server;

  // Let us examine the evidence.
  if (argc < 3) {
    printf("Usage: %s <server_address> <port_number>\n", argv[0]);
    exit(0);
  }

  // Retrieve the server's address.
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("Unable to resolve server address.\n");
    exit(1);
  }

  // Establish a connection to the server.
  socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_descriptor < 0) {
    printf("Failed to create socket.\n");
    exit(2);
  }

  // Configure the server address.
  port_number = atoi(argv[2]);
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port_number);
  memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

  // Attempt a connection to the server.
  if (connect(socket_descriptor, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
    printf("Failed to connect to the server.\n");
    exit(3);
  }

  // Watson, I deduce that we have successfully connected to the server.

  // Now, let us send a message to the server.
  char message[] = "Elementary, my dear Watson.";
  int sent_bytes = send(socket_descriptor, message, strlen(message), 0);
  if (sent_bytes < 0) {
    printf("Failed to send message to the server.\n");
    exit(4);
  }

  // Let us wait for a response from the server.
  char buffer[256];
  int received_bytes = recv(socket_descriptor, buffer, sizeof(buffer), 0);
  if (received_bytes < 0) {
    printf("Failed to receive response from the server.\n");
    exit(5);
  }

  // Excellent! We have received a response from the server.
  printf("Server response: %s\n", buffer);

  // The investigation is complete, Watson. Let us close the connection.
  close(socket_descriptor);

  return 0;
}