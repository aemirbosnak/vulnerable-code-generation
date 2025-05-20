//FormAI DATASET v1.0 Category: Socket programming ; Style: genious
// import required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // check if the required number of arguments are provided
  if (argc < 3) {
    printf("Usage: %s <IP address> <Port>\n", argv[0]);
    exit(1);
  } 

  // create a socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  // initialize the server address and port number
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  inet_pton(AF_INET, argv[1], &server_address.sin_addr);
  server_address.sin_port = htons(atoi(argv[2]));

  // connect to the server
  int conn_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  if (conn_status < 0) {
    perror("Connection failed");
    exit(1);
  }

  // send a message to the server
  char *message = "Hello from the client!";
  if (send(client_socket, message, strlen(message), 0) < 0) {
    perror("Send failed");
    exit(1);
  }

  // receive a message from the server
  char buffer[BUFFER_SIZE] = {0};
  if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
    perror("Receive failed");
    exit(1);
  }

  // print the message received from the server
  printf("Server says: %s\n", buffer);

  // close the client socket
  close(client_socket);

  return 0;
}