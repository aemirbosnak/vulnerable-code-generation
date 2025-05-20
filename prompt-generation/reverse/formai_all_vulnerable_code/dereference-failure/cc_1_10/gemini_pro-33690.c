//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to handle HTTP requests
int handleRequest(int clientSocket) {
  char request[1024];
  char response[1024];

  // Read the HTTP request from the client
  recv(clientSocket, request, sizeof(request), 0);

  // Parse the HTTP request to get the requested file
  char *file = strtok(request, " ");
  file = strtok(NULL, " ");

  // Open the requested file
  FILE *fp = fopen(file, "r");

  // If the file cannot be opened, send a 404 error
  if (fp == NULL) {
    sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\nFile not found.");
    send(clientSocket, response, strlen(response), 0);
    return 1;
  }

  // Read the file contents into the response
  char *fileContents = malloc(1024);
  fread(fileContents, 1, 1024, fp);

  // Send the HTTP response to the client
  sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n%s", fileContents);
  send(clientSocket, response, strlen(response), 0);

  // Close the file and the client socket
  fclose(fp);
  close(clientSocket);

  return 0;
}

int main(int argc, char *argv[]) {
  // Create a server socket
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

  // Set the server socket to listen on port 80
  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(80);
  bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

  // Listen for incoming connections
  listen(serverSocket, 5);

  // Accept incoming connections
  while (1) {
    int clientSocket = accept(serverSocket, NULL, NULL);

    // Handle the HTTP request
    handleRequest(clientSocket);
  }

  return 0;
}