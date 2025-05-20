//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the port number that the server will listen on
#define PORT 8080

// Define the buffer size for receiving and sending messages
#define BUFFER_SIZE 1024

// Define the structure that will be used to store client information
typedef struct client_info {
  int socket_fd;
  char username[BUFFER_SIZE];
} client_info;

// Define the structure that will be used to store the server information
typedef struct server_info {
  int socket_fd;
  struct sockaddr_in server_addr;
} server_info;

// Define the mutex that will be used to protect the client list
pthread_mutex_t client_list_mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the list of clients that are connected to the server
client_info client_list[MAX_CLIENTS];

// Define the function that will be used to handle client connections
void* handle_client(void* arg) {
  // Get the client information from the argument
  client_info* client = (client_info*)arg;

  // Receive the username from the client
  char username[BUFFER_SIZE];
  recv(client->socket_fd, username, BUFFER_SIZE, 0);

  // Add the client to the client list
  pthread_mutex_lock(&client_list_mutex);
  for (int i = 0; i < MAX_CLIENTS; i++) {
    if (client_list[i].socket_fd == 0) {
      client_list[i] = *client;
      break;
    }
  }
  pthread_mutex_unlock(&client_list_mutex);

  // Send a welcome message to the client
  char welcome_message[BUFFER_SIZE];
  sprintf(welcome_message, "Welcome to the chat server, %s!", username);
  send(client->socket_fd, welcome_message, strlen(welcome_message), 0);

  // Loop until the client disconnects
  while (1) {
    // Receive a message from the client
    char message[BUFFER_SIZE];
    int bytes_received = recv(client->socket_fd, message, BUFFER_SIZE, 0);

    // If the client disconnected, break out of the loop
    if (bytes_received == 0) {
      break;
    }

    // Otherwise, send the message to all other clients
    pthread_mutex_lock(&client_list_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (client_list[i].socket_fd != client->socket_fd) {
        send(client_list[i].socket_fd, message, bytes_received, 0);
      }
    }
    pthread_mutex_unlock(&client_list_mutex);
  }

  // Remove the client from the client list
  pthread_mutex_lock(&client_list_mutex);
  for (int i = 0; i < MAX_CLIENTS; i++) {
    if (client_list[i].socket_fd == client->socket_fd) {
      client_list[i].socket_fd = 0;
      break;
    }
  }
  pthread_mutex_unlock(&client_list_mutex);

  // Close the client's socket
  close(client->socket_fd);

  // Free the client's memory
  free(client);

  return NULL;
}

int main() {
  // Create the server socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the server socket to be reusable
  int reuseaddr_opt = 1;
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_opt, sizeof(reuseaddr_opt));

  // Bind the server socket to the port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);
  if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  while (1) {
    // Accept a new connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Create a new client thread
    pthread_t client_thread;
    client_info* client = malloc(sizeof(client_info));
    client->socket_fd = client_socket;
    if (pthread_create(&client_thread, NULL, handle_client, (void*)client) != 0) {
      perror("pthread_create");
      continue;
    }

    // Detach the client thread
    pthread_detach(client_thread);
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}