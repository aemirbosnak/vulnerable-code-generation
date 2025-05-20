//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
// Welcome, Runner. This program will hack into the city's temperature control grid and give you the inside scoop.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {
  // Initialize our magical variables
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  portno = 1337; // The port we're hacking into
  server = gethostbyname("megaCorp.net"); // The target server

  // Establish connection with the server
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Connection failed. Maybe the firewall is too strong?\n");
    return -1;
  }
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("Connection failed. Maybe the firewall is too strong?\n");
    return -1;
  }

  // Send the magic packet to the server
  strcpy(buffer, "temp?");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Transmission failed. Maybe the firewall is too strong?\n");
    return -1;
  }

  // Receive the server's response
  memset(buffer, 0, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    printf("Transmission failed. Maybe the firewall is too strong?\n");
    return -1;
  }
  printf("Current temperature: %s\n", buffer);

  // Close the connection
  close(sockfd);
  return 0;
}