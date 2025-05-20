//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
  // Declare our FTP warrior's trusty steed
  int sockfd;
  struct sockaddr_in server_addr;
  struct hostent *server;

  // Embark on the quest for the FTP server's lair
  char *hostname = "ftp.example.com";
  server = gethostbyname(hostname);
  if (server == NULL) {
    printf("Failed to find our destination, the FTP server!");
    return EXIT_FAILURE;
  }

  // Forge a pact with the socket, our faithful companion
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Socket creation failed!");
    return EXIT_FAILURE;
  }

  // Set sail towards the server's port, 21 for FTP adventures
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy((char *) &server_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
  server_addr.sin_port = htons(21);

  // Connect to the FTP server, our destination of wonder
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    printf("Failed to reach the FTP server!");
    return EXIT_FAILURE;
  }

  // Prepare for the adventure, establish a user
  char username[] = "ftpuser";
  char password[] = "secretpassword";
  send(sockfd, username, strlen(username), 0);
  recv(sockfd, NULL, 256, 0);
  send(sockfd, password, strlen(password), 0);
  recv(sockfd, NULL, 256, 0);

  // Send a command to the server, beckoning it to unveil its secrets
  char command[] = "LIST";
  send(sockfd, command, strlen(command), 0);
  recv(sockfd, NULL, 256, 0);

  // Behold the spoils of our quest, a list of files
  char buffer[256];
  while (recv(sockfd, buffer, 256, 0) > 0) {
    printf("%s", buffer);
  }

  // Bid farewell to the server, our journey's end
  close(sockfd);
  return EXIT_SUCCESS;
}