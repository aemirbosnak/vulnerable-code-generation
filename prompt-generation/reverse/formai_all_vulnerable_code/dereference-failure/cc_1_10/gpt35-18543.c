//FormAI DATASET v1.0 Category: Client Server Application ; Style: enthusiastic
// Welcome to my unique C Client Server Application program!

// First, let's include all the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  // Let's define some variables
  int serverSocket, clientSocket, portNumber, clientAddrLength;
  struct sockaddr_in serverAddr, clientAddr;
  char buffer[1024];

  // Check if the user entered the correct number of arguments
  if(argc < 2) {
    fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
    exit(1);
  }

  // Create the server socket
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if(serverSocket < 0) {
    perror("Error: Failed to create socket.\n");
    exit(1);
  }
  
  // Define the server address
  memset((char*)&serverAddr, 0, sizeof(serverAddr));
  portNumber = atoi(argv[1]);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = INADDR_ANY;
  serverAddr.sin_port = htons(portNumber);

  // Bind the socket
  if(bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
    perror("Error: Failed to bind socket.\n");
    exit(1);
  }

  // Listen for incoming connections
  listen(serverSocket, 5);
  printf("Server is now listening for incoming connections on port %d...\n", portNumber);

  // Accept incoming connection and create the client socket
  clientAddrLength = sizeof(clientAddr);
  clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLength);
  if(clientSocket < 0) {
    perror("Error: Failed to accept incoming connection.\n");
    exit(1);
  }

  // Print information about the connected client
  printf("Connected to client %s:%d.\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

  while(1) {
    // Receive a message from the client
    memset(buffer, 0, sizeof(buffer));
    int numBytes = recv(clientSocket, buffer, sizeof(buffer), 0);
    if(numBytes < 0) {
      perror("Error: Failed to receive message from client.\n");
      exit(1);
    }
  
    // Display the received message
    printf("Received message: %s", buffer);

    // Send a response to the client
    char response[] = "Hello from the server!\n";
    send(clientSocket, response, strlen(response), 0);
  }

  // Close the sockets
  close(clientSocket);
  close(serverSocket);
  
  return 0;
}