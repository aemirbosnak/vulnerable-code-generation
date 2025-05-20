//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Sherlock Holmes
#include <arpa/inet.h>
#include <libgen.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Sherlock Holmes-style function to establish an FTP connection
int establishFTPConnection(const char* serverName, int port) {
  int socketDescriptor;
  struct sockaddr_in serverAddress;
  struct hostent* serverHostEntry;

  // Elementary, my dear Watson!
  printf("Establishing connection to %s on port %d...\n", serverName, port);

  // Resolve the server name to an IP address
  serverHostEntry = gethostbyname(serverName);
  if (serverHostEntry == NULL) {
    perror("gethostbyname");
    return -1;
  }

  // Create a socket
  socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socketDescriptor == -1) {
    perror("socket");
    return -1;
  }

  // Set up the server address structure
  memset(&serverAddress, 0, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(port);
  memcpy(&serverAddress.sin_addr, serverHostEntry->h_addr, serverHostEntry->h_length);

  // Connect to the server
  if (connect(socketDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
    perror("connect");
    close(socketDescriptor);
    return -1;
  }

  // Connection established!
  printf("Connected to %s on port %d.\n", serverName, port);

  return socketDescriptor;
}

// Sherlock Holmes-style function to retrieve a file from an FTP server
int retrieveFileFromFTPServer(int socketDescriptor, const char* fileName) {
  char buffer[1024];
  int bytesReceived;
  FILE* file;

  // Open the file for writing
  file = fopen(fileName, "wb");
  if (file == NULL) {
    perror("fopen");
    return -1;
  }

  // Send the RETR command to the server
  snprintf(buffer, sizeof(buffer), "RETR %s\r\n", fileName);
  if (send(socketDescriptor, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    fclose(file);
    return -1;
  }

  // Receive the file data from the server
  while ((bytesReceived = recv(socketDescriptor, buffer, sizeof(buffer), 0)) > 0) {
    if (fwrite(buffer, 1, bytesReceived, file) != bytesReceived) {
      perror("fwrite");
      fclose(file);
      return -1;
    }
  }

  // Close the file
  fclose(file);

  // File retrieved successfully!
  printf("File %s retrieved successfully.\n", fileName);

  return 0;
}

int main(int argc, char** argv) {
  int socketDescriptor;

  // Check the command line arguments
  if (argc != 4) {
    printf("Usage: %s <server name> <port> <file name>\n", basename(argv[0]));
    return -1;
  }

  // Establish an FTP connection
  socketDescriptor = establishFTPConnection(argv[1], atoi(argv[2]));
  if (socketDescriptor == -1) {
    return -1;
  }

  // Retrieve the file from the FTP server
  if (retrieveFileFromFTPServer(socketDescriptor, argv[3]) == -1) {
    close(socketDescriptor);
    return -1;
  }

  // Close the FTP connection
  close(socketDescriptor);

  return 0;
}