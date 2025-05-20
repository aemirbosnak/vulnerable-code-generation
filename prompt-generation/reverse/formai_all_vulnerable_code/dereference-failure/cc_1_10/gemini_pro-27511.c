//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <pthread.h>

// Function to handle the client's request
void handle_client(int socket)
{
  char buffer[1024];
  int nbytes;

  // Receive the request from the client
  nbytes = recv(socket, buffer, sizeof(buffer), 0);
  if (nbytes < 0)
  {
    perror("recv");
    exit(1);
  }

  // Parse the request
  char *request = strtok(buffer, " ");
  char *filename = strtok(NULL, " ");

  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    perror("fopen");
    exit(1);
  }

  // Send the file to the client
  while ((nbytes = fread(buffer, 1, sizeof(buffer), file)) > 0)
  {
    if (send(socket, buffer, nbytes, 0) < 0)
    {
      perror("send");
      exit(1);
    }
  }

  // Close the file
  fclose(file);

  // Close the socket
  close(socket);
}

// The main function starts the server
int main(int argc, char **argv)
{
  int server_socket;
  int client_socket;
  struct sockaddr_in server_address;
  struct sockaddr_in client_address;
  socklen_t client_address_length;
  pthread_t thread;

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0)
  {
    perror("socket");
    exit(1);
  }

  // Set the server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(8080);

  // Bind the server socket to the address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
  {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) < 0)
  {
    perror("listen");
    exit(1);
  }

  // Accept incoming connections
  while (1)
  {
    client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
    if (client_socket < 0)
    {
      perror("accept");
      exit(1);
    }

    // Create a new thread to handle the client's request
    if (pthread_create(&thread, NULL, (void *)handle_client, (void *)client_socket) != 0)
    {
      perror("pthread_create");
      exit(1);
    }
  }

  // Close the server socket
  close(server_socket);

  return 0;
}