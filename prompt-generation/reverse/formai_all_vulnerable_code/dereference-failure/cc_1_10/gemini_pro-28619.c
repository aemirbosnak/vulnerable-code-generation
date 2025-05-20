//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  // Check if the user has provided the necessary arguments.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server address> <port number>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the server address and port number from the command line arguments.
  char *serverAddress = argv[1];
  int portNumber = atoi(argv[2]);

  // Create a socket for communicating with the server.
  int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socketDescriptor == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Resolve the server address.
  struct hostent *serverHostEnt = gethostbyname(serverAddress);
  if (serverHostEnt == NULL) {
    perror("Error resolving server address");
    exit(EXIT_FAILURE);
  }

  // Create the server address structure.
  struct sockaddr_in serverAddressStruct;
  memset(&serverAddressStruct, 0, sizeof(serverAddressStruct));
  serverAddressStruct.sin_family = AF_INET;
  serverAddressStruct.sin_port = htons(portNumber);
  memcpy(&serverAddressStruct.sin_addr, serverHostEnt->h_addr, serverHostEnt->h_length);

  // Connect to the server.
  if (connect(socketDescriptor, (struct sockaddr *)&serverAddressStruct, sizeof(serverAddressStruct)) == -1) {
    perror("Error connecting to server");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server.
  char *message = "Hello, world!";
  if (send(socketDescriptor, message, strlen(message), 0) == -1) {
    perror("Error sending message to server");
    exit(EXIT_FAILURE);
  }

  // Receive a response from the server.
  char response[MAX_LINE_LENGTH];
  int responseLength = recv(socketDescriptor, response, MAX_LINE_LENGTH, 0);
  if (responseLength == -1) {
    perror("Error receiving response from server");
    exit(EXIT_FAILURE);
  }

  // Print the response from the server.
  printf("Response from server: %s\n", response);

  // Close the socket.
  close(socketDescriptor);

  return EXIT_SUCCESS;
}