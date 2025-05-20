//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

// Function to convert a char array to an ASCII art representation
char *text_to_ascii(char *text) {
  int len = strlen(text);
  char *ascii_art = malloc(len * 8 * sizeof(char));
  int i, j, k;
  for (i = 0; i < len; i++) {
    char c = text[i];
    for (j = 0; j < 8; j++) {
      for (k = 0; k < 8; k++) {
        ascii_art[i * 8 * 8 + j * 8 + k] = (c >> (7 - j) & (1 << k)) ? '#' : ' ';
      }
    }
  }
  return ascii_art;
}

// Function to send a message to a client
void send_message(int client_socket, char *message) {
  int len = strlen(message);
  send(client_socket, &len, sizeof(int), 0);
  send(client_socket, message, len, 0);
}

// Function to handle a client connection
void handle_client(int client_socket) {
  char buffer[1024];
  while (1) {
    // Receive the message from the client
    int len;
    recv(client_socket, &len, sizeof(int), 0);
    recv(client_socket, buffer, len, 0);

    // Convert the message to ASCII art
    char *ascii_art = text_to_ascii(buffer);

    // Send the ASCII art back to the client
    send_message(client_socket, ascii_art);

    free(ascii_art);
  }
}

// Function to start the server
void start_server() {
  // Create a socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Bind the socket to an address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);
  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // Listen for connections
  listen(server_socket, 5);

  // Accept connections and handle them in a loop
  while (1) {
    int client_socket = accept(server_socket, NULL, NULL);
    handle_client(client_socket);
  }
}

int main() {
  start_server();
  return 0;
}