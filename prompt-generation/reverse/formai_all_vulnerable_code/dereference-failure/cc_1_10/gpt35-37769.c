//FormAI DATASET v1.0 Category: Networking ; Style: introspective
/* 
   This C Networking program creates a client-side socket that connects to a server-side socket,
   sends a message to the server and waits for a response. It is written in a introspective style 
   to demonstrate the step-by-step process of creating a successful network connection. 

   Created by [YOUR NAME]    
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Step 1: Create a socket

  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (client_socket < 0) {
    printf("Error creating socket\n");
    exit(EXIT_FAILURE);
  }

  // Step 2: Define the server address including IP and port number

  struct sockaddr_in server_address;

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(atoi(argv[1])); // Converts port number to network byte order
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Step 3: Connect to the server

  int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

  if (connection_status < 0) {
    printf("Error connecting to server\n");
    exit(EXIT_FAILURE);
  }

  // Step 4: Send message to server

  char *message = "Hello from client!";
  int message_length = strlen(message);

  int bytes_sent = send(client_socket, message, message_length, 0);

  if (bytes_sent < 0) {
    printf("Error sending message to server\n");
    exit(EXIT_FAILURE);
  }

  // Step 5: Receive message from server

  char server_response[256];

  int bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);

  if (bytes_received < 0) {
    printf("Error receiving message from server\n");
    exit(EXIT_FAILURE);
  }

  printf("Server response: %s\n", server_response);

  // Step 6: Close the socket
  
  close(client_socket);

  return 0;
}