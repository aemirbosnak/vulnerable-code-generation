//FormAI DATASET v1.0 Category: Client Server Application ; Style: ultraprecise
// This program is an example of a simple C Client-Server Application that can transmit messages between them.
// The program contains a Server and a Client that interact with each other over the network.

// Importing Required Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Define Constants
#define PORT 9000
#define MAXMSG 1024

// Function to Send a Message
int sendMessage(int socket, char* message) {
  int bytes;
  if ((bytes = send(socket, message, strlen(message), 0)) == -1) {
    perror("Error sending message");
    return -1;
  }
  printf("Sent %d bytes\n", bytes);
  return 0;
}

// Function to Receive a Message
int receiveMessage(int socket, char* buffer) {
  int bytes;
  if ((bytes = recv(socket, buffer, MAXMSG, 0)) == -1) {
    perror("Error receiving message");
    return -1;
  }
  buffer[bytes] = '\0';
  printf("Received %d bytes: %s\n", bytes, buffer);
  return 0;
}

// Main Function
int main(int argc, char *argv[]) {
  int sock, connection, bytes;
  struct sockaddr_in server;
  char message[MAXMSG], buffer[MAXMSG];

  // Create Socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Set Server Address
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT);

  // Bind Socket to Server Address
  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Error binding socket to server");
    exit(1);
  }

  // Listen for Client Connections
  if (listen(sock, 1) < 0) {
    perror("Error listening for connections");
    exit(1);
  }

  printf("Server started on port %d\n", PORT);

  // Accept Incoming Connections
  connection = accept(sock, NULL, NULL);
  if (connection < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  printf("Connection accepted\n");

  // Begin Chatting with Client
  while (1) {
    // Receive Message from Client
    receiveMessage(connection, buffer);

    // Quit if Client Sends "quit"
    if (strcmp(buffer, "quit") == 0) {
      break;
    }

    // Print Recieved Message
    printf("Client: %s\n", buffer);

    // Get Message to Send to Client
    printf("Enter message to send to Client: ");
    fgets(message, MAXMSG, stdin);

    // Send Message to Client
    sendMessage(connection, message);
  }

  // Close Connection and Socket
  close(connection);
  close(sock);

  printf("Connection closed\n");

  return 0;
}