//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the port number for the server.
#define PORT 5000

// Define the maximum number of clients that can connect to the server.
#define MAX_CLIENTS 10

// Define the maximum size of a log message.
#define MAX_LOG_SIZE 1024

// Define the structure of a log message.
typedef struct {
  char *message;
  int size;
} LogMessage;

// Define the structure of a client.
typedef struct {
  int socket;
  pthread_t thread;
} Client;

// Define an array of clients.
Client clients[MAX_CLIENTS];

// Define a mutex to protect the array of clients.
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Define a condition variable to signal when a new client has connected.
pthread_cond_t clients_cond = PTHREAD_COND_INITIALIZER;

// Define a function to handle a client connection.
void *handle_client(void *arg) {
  // Get the client socket.
  int socket = *(int *)arg;

  // Allocate memory for a log message.
  LogMessage *log_message = malloc(sizeof(LogMessage));

  // Receive the log message from the client.
  recv(socket, log_message, sizeof(LogMessage), 0);

  // Print the log message to the console.
  printf("%s\n", log_message->message);

  // Free the memory allocated for the log message.
  free(log_message);

  // Close the client socket.
  close(socket);

  // Signal that the client has disconnected.
  pthread_mutex_lock(&clients_mutex);
  clients[socket] = (Client){0, 0};
  pthread_cond_signal(&clients_cond);
  pthread_mutex_unlock(&clients_mutex);

  // Exit the thread.
  pthread_exit(NULL);
}

// Define a function to start the server.
void start_server() {
  // Create a server socket.
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Set the server socket to be reusable.
  int reuseaddr_on = 1;
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_on, sizeof(reuseaddr_on));

  // Bind the server socket to the port.
  struct sockaddr_in server_addr = {0};
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);
  bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Listen for incoming connections.
  listen(server_socket, MAX_CLIENTS);

  // Accept incoming connections.
  while (1) {
    // Accept a new client connection.
    int client_socket = accept(server_socket, NULL, NULL);

    // Find an empty slot in the array of clients.
    pthread_mutex_lock(&clients_mutex);
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i].socket == 0) {
        break;
      }
    }

    // If there is no empty slot, wait for one to become available.
    if (i == MAX_CLIENTS) {
      pthread_cond_wait(&clients_cond, &clients_mutex);
    }

    // Add the new client to the array of clients.
    clients[i] = (Client){client_socket, 0};

    // Create a new thread to handle the client connection.
    pthread_create(&clients[i].thread, NULL, handle_client, &clients[i].socket);

    // Unlock the array of clients.
    pthread_mutex_unlock(&clients_mutex);
  }

  // Close the server socket.
  close(server_socket);
}

// Define the main function.
int main() {
  // Start the server.
  start_server();

  // Exit the program.
  return 0;
}