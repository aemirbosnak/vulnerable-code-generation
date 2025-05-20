//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {

  int client_socket;
  
  struct hostent *server;
  struct sockaddr_in server_address;

  char *hostname = "imap.server.com";
  int port = 143;

  char buffer[2048];
  bool done = false;
  char command[1024];

  // Establish connection with the IMAP server
  client_socket = socket(AF_INET, SOCK_STREAM, 0);

  server = gethostbyname(hostname);
  bzero((char *) &server_address, sizeof(server_address));
  server_address.sin_family = AF_INET;
  bcopy((char *)server->h_addr, 
        (char *)&server_address.sin_addr.s_addr,
        server->h_length);
  server_address.sin_port = htons(port);

  connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

  // Authenticate with the IMAP server
  sprintf(command, "LOGIN %s %s\r\n", "username", "password");
  send(client_socket, command, strlen(command), 0);
  recv(client_socket, buffer, 2048, 0);
  printf("%s", buffer);

  while (!done) {
      // Read user input
      printf("> ");
      fgets(command, 1024, stdin);

      // Check for QUIT command
      if (strncmp(command, "QUIT", 4) == 0) {
          send(client_socket, "QUIT\r\n", 6, 0);
          recv(client_socket, buffer, 2048, 0);
          printf("%s", buffer);
          done = true;
      } else {
          // Send command to IMAP server
          send(client_socket, command, strlen(command), 0);

          // Wait for response from server
          recv(client_socket, buffer, 2048, 0);
          printf("%s", buffer);
      }
  }

  close(client_socket);

  return 0;
}