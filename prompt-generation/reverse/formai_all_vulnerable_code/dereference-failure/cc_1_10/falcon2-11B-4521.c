//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// global variables
int port = 8888;
int max_connections = 10;
char* username = NULL;
int connection_count = 0;

// function declarations
void handle_connection(int client_socket);
void send_message(int client_socket, const char* message);
void handle_disconnect(int client_socket);
void handle_command(int client_socket, const char* command);

int main(int argc, char** argv) {
  // check command line arguments
  if (argc!= 3) {
    printf("Usage: %s <port> <username>\n", argv[0]);
    return 1;
  }

  // parse command line arguments
  port = atoi(argv[1]);
  username = argv[2];

  // create socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return 1;
  }

  // configure socket
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // bind socket
  if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return 1;
  }

  // listen for connections
  if (listen(server_socket, max_connections) == -1) {
    perror("listen");
    return 1;
  }

  printf("Chat server started on port %d\n", port);

  while (1) {
    // accept a connection
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // handle client disconnects
    handle_disconnect(client_socket);

    // handle client commands
    while (1) {
      char command[100];
      int length = read(client_socket, command, sizeof(command));
      if (length <= 0) {
        close(client_socket);
        connection_count--;
        break;
      }

      handle_command(client_socket, command);
    }

    // close client socket
    close(client_socket);
    connection_count--;
  }

  return 0;
}

void handle_connection(int client_socket) {
  char message[100];
  printf("New connection: %d\n", connection_count);

  // send welcome message
  send_message(client_socket, "Welcome to the chat server!");

  // wait for client to send username
  while (1) {
    char username_buffer[100];
    int length = read(client_socket, username_buffer, sizeof(username_buffer));
    if (length <= 0) {
      close(client_socket);
      connection_count--;
      break;
    }

    if (strcmp(username_buffer, "username") == 0) {
      send_message(client_socket, "Please provide your username");
      continue;
    }

    // set username for client
    username = username_buffer;
    break;
  }

  printf("Client %d connected as %s\n", connection_count, username);
}

void send_message(int client_socket, const char* message) {
  printf("%s\n", message);

  // send message to all connected clients
  for (int i = 0; i < connection_count; i++) {
    if (i!= client_socket) {
      send_message(i, message);
    }
  }
}

void handle_disconnect(int client_socket) {
  printf("Client %d disconnected\n", connection_count);
  connection_count--;
}

void handle_command(int client_socket, const char* command) {
  if (strcmp(command, "exit") == 0) {
    printf("Client %d disconnected\n", connection_count);
    close(client_socket);
    connection_count--;
  } else if (strcmp(command, "list") == 0) {
    printf("Current clients:\n");
    for (int i = 0; i < connection_count; i++) {
      printf("Client %d: %s\n", i, username);
    }
  } else {
    printf("Invalid command: %s\n", command);
  }
}