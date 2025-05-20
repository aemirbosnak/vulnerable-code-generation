//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 4
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
char buffer[BUFFER_SIZE];

void handle_client(int client_socket) {
  while (1) {
    // Receive a message from the client
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
      // Client has disconnected
      printf("Client %d disconnected\n", client_socket);
      close(client_socket);
      return;
    }

    // Process the message
    char *expression = strtok(buffer, " ");
    double result = 0;
    if (strcmp(expression, "ADD") == 0) {
      double num1 = atof(strtok(NULL, " "));
      double num2 = atof(strtok(NULL, " "));
      result = num1 + num2;
    } else if (strcmp(expression, "SUB") == 0) {
      double num1 = atof(strtok(NULL, " "));
      double num2 = atof(strtok(NULL, " "));
      result = num1 - num2;
    } else if (strcmp(expression, "MUL") == 0) {
      double num1 = atof(strtok(NULL, " "));
      double num2 = atof(strtok(NULL, " "));
      result = num1 * num2;
    } else if (strcmp(expression, "DIV") == 0) {
      double num1 = atof(strtok(NULL, " "));
      double num2 = atof(strtok(NULL, " "));
      result = num1 / num2;
    } else {
      // Invalid expression
      result = 0;
    }

    // Send the result back to the client
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%f", result);
    if (send(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
      // Client has disconnected
      printf("Client %d disconnected\n", client_socket);
      close(client_socket);
      return;
    }
  }
}

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  int addrlen = sizeof(struct sockaddr_in);

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return -1;
  }

  // Bind the server socket to the address and port
  memset(&server_address, 0, addrlen);
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  if (bind(server_socket, (struct sockaddr *)&server_address, addrlen) == -1) {
    perror("bind");
    return -1;
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("listen");
    return -1;
  }

  while (1) {
    // Accept an incoming connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Add the client socket to the list of clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i] == 0) {
        clients[i] = client_socket;
        break;
      }
    }

    // Create a new thread to handle the client
    pthread_t thread;
    if (pthread_create(&thread, NULL, (void *(*)(void *))handle_client, (void *)client_socket) != 0) {
      perror("pthread_create");
      continue;
    }
  }

  // Close the server socket
  close(server_socket);

  return 0;
}