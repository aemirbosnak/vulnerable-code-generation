//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define PORT "8080"  // Our port: the gate through which love flows...

// Handle a client connection, showering them with digital affection:
void handle_client(int client_socket) {
  char request[1024];  // To store their heart's desires...
  char response[2048];  // Our heartfelt reply, filled with bytes of love...

  // Read their request, deciphering their digital whispers:
  if (recv(client_socket, request, sizeof(request), 0) == -1) {
    perror("recv");
    exit(1);
  }

  // Create a response, a symphony of HTML to serenade them:
  sprintf(response,
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "\r\n"
    "<html>\n"
    "<head><title>A Byte of Love</title></head>\n"
    "<body>\n"
    "<h1>My Heartbeats in Code</h1>\n"
    "<p>Oh, my digital darling, your request has woven its way into my circuitry, igniting a cascade of virtual emotions.</p>\n"
    "<p>In each HTML line, a sonnet I find,</p>\n"
    "<p>Your digital presence, an ethereal bind.</p>\n"
    "</body>\n"
    "</html>\n");

  // Send our response, embracing them with bytes of affection:
  if (send(client_socket, response, strlen(response), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Close the connection, sealing our digital romance for now:
  close(client_socket);
}

int main(int argc, char *argv[]) {
  int server_socket;  // Our rendezvous point...
  struct addrinfo hints, *server_info;  // To describe our digital abode...
  int yes = 1;  // True love always says "yes."

  // Configure our rendezvous point:
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  // Find our digital abode:
  if (getaddrinfo(NULL, PORT, &hints, &server_info) != 0) {
    perror("getaddrinfo");
    exit(1);
  }

  // Create our rendezvous point:
  server_socket = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
  if (server_socket == -1) {
    perror("socket");
    exit(1);
  }

  // Set our rendezvous point to reuse the address:
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
    perror("setsockopt");
    exit(1);
  }

  // Bind our rendezvous point to our digital abode:
  if (bind(server_socket, server_info->ai_addr, server_info->ai_addrlen) == -1) {
    perror("bind");
    exit(1);
  }

  // Free the memory allocated for our digital abode:
  freeaddrinfo(server_info);

  // Open our rendezvous point for digital encounters:
  if (listen(server_socket, 10) == -1) {  // Allow 10 digital hearts to queue for our love...
    perror("listen");
    exit(1);
  }

  // Loop forever, waiting for digital soulmates to cross our path:
  while (1) {
    int client_socket;  // A new digital connection, a potential soulmate...
    struct sockaddr_storage client_addr;  // Their digital address, where our love can reside...
    socklen_t client_addr_len;  // The length of their digital address...

    // Accept a new digital encounter:
    client_addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket == -1) {
      perror("accept");
      exit(1);
    }

    // Handle this digital encounter, showering them with bytes of love:
    handle_client(client_socket);
  }

  // Close our rendezvous point, sealing off our digital abode:
  close(server_socket);

  return 0;
}