//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#define PORT_NUMBER 21

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  int client_socket;
  char message_buffer[1024];
  struct sockaddr_in server_address;

  // Pirate's ship ready for launch!
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("Socket creation failed");
    return 2;
  }

  // Time to set sail towards the horizon
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
    perror("Invalid IP address");
    return 3;
  }

  // Anchors aweigh! Let's connect to the distant shore
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Connection failed");
    return 4;
  }

  // Raise the jolly roger! Time to chat with the server
  memset(message_buffer, 0, sizeof(message_buffer));
  recv(client_socket, message_buffer, sizeof(message_buffer), 0);
  printf("Server greeting: %s\n", message_buffer);

  // Send a message to the server, like a message in a bottle
  memset(message_buffer, 0, sizeof(message_buffer));
  strcpy(message_buffer, "USER anonymous\r\n");
  send(client_socket, message_buffer, strlen(message_buffer), 0);

  // Receive the server's response, like a secret treasure map
  memset(message_buffer, 0, sizeof(message_buffer));
  recv(client_socket, message_buffer, sizeof(message_buffer), 0);
  printf("Server response: %s\n", message_buffer);

  // Send the password, like a key to unlock the treasure chest
  memset(message_buffer, 0, sizeof(message_buffer));
  strcpy(message_buffer, "PASS username@example.com\r\n");
  send(client_socket, message_buffer, strlen(message_buffer), 0);

  // Receive the server's response, like a confirmation of our loot
  memset(message_buffer, 0, sizeof(message_buffer));
  recv(client_socket, message_buffer, sizeof(message_buffer), 0);
  printf("Server response: %s\n", message_buffer);

  // Send a command to the server, like a request for a specific treasure
  memset(message_buffer, 0, sizeof(message_buffer));
  strcpy(message_buffer, "RETR index.html\r\n");
  send(client_socket, message_buffer, strlen(message_buffer), 0);

  // Receive the server's response, like our precious treasure chest
  memset(message_buffer, 0, sizeof(message_buffer));
  recv(client_socket, message_buffer, sizeof(message_buffer), 0);
  printf("Server response: %s\n", message_buffer);

  // Close the connection, like setting sail for a new adventure
  close(client_socket);

  return 0;
}