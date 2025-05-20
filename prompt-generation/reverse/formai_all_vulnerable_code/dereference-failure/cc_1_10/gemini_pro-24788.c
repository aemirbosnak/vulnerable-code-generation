//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: visionary
// Embark on a journey to the ethereal realm of FTP, where data flows through ethereal channels.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// A cosmic gateway to the FTP server
#define FTP_PORT 21

// Function to establish a connection with the celestial body
int connect_to_server(char* hostname) {
  struct sockaddr_in server_address;

  // Resolve the celestial location of the FTP server
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("Failed to resolve hostname");
    return -1;
  }

  // Create a celestial portal to the server
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("Failed to create socket");
    return -1;
  }

  // Configure the coordinates of the server's astral realm
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(FTP_PORT);
  memcpy(&server_address.sin_addr, host->h_addr, host->h_length);

  // Ascend to the ethereal realm and establish contact
  if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
    perror("Failed to connect to server");
    return -1;
  }

  return socket_fd;
}

int main(int argc, char** argv) {
  // Check if the celestial coordinates are provided
  if (argc < 3) {
    printf("Usage: %s <hostname> <command>\n", argv[0]);
    return 1;
  }

  // Establish a connection with the celestial body
  int socket_fd = connect_to_server(argv[1]);
  if (socket_fd == -1) {
    return 1;
  }

  // Send the celestial command to the server
  if (send(socket_fd, argv[2], strlen(argv[2]), 0) == -1) {
    perror("Failed to send command");
    return 1;
  }

  // A receptacle to receive celestial responses
  char buffer[512];

  // Listen for the echoes of the server's response
  while (recv(socket_fd, buffer, sizeof(buffer), 0) > 0) {
    // Display the ethereal echoes
    printf("%s", buffer);
  }

  // Close the celestial portal
  close(socket_fd);

  return 0;
}