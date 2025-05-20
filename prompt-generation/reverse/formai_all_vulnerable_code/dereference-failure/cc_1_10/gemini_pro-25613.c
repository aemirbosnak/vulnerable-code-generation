//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Custom data structure to hold client information
typedef struct {
  int sockfd;
  struct sockaddr_in addr;
  char name[100];
} client_info;

// Global variables
pthread_mutex_t lock;
client_info clients[100];
int num_clients = 0;

// Function to send a message to all clients
void broadcast_message(char *message) {
  pthread_mutex_lock(&lock);
  for (int i = 0; i < num_clients; i++) {
    send(clients[i].sockfd, message, strlen(message), 0);
  }
  pthread_mutex_unlock(&lock);
}

// Function to handle a client connection
void* handle_client(void *arg) {
  client_info *client = (client_info *)arg;
  char buffer[1024];

  // Receive the client's name
  recv(client->sockfd, buffer, sizeof(buffer), 0);
  strcpy(client->name, buffer);

  // Send a welcome message to the client
  sprintf(buffer, "Welcome to the chat room, %s!", client->name);
  send(client->sockfd, buffer, strlen(buffer), 0);

  // Loop until the client disconnects
  while (1) {
    // Receive a message from the client
    recv(client->sockfd, buffer, sizeof(buffer), 0);

    // If the message is empty, the client has disconnected
    if (strlen(buffer) == 0) {
      break;
    }

    // Broadcast the message to all clients
    broadcast_message(buffer);
  }

  // Remove the client from the list of active clients
  pthread_mutex_lock(&lock);
  for (int i = 0; i < num_clients; i++) {
    if (clients[i].sockfd == client->sockfd) {
      clients[i] = clients[num_clients - 1];
      num_clients--;
      break;
    }
  }
  pthread_mutex_unlock(&lock);

  // Close the client's socket
  close(client->sockfd);

  // Free the client's memory
  free(client);

  return NULL;
}

int main() {
  int sockfd, newsockfd, portno = 5000;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t clilen;

  // Create a TCP socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return EXIT_FAILURE;
  }

  // Set the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  listen(sockfd, 5);

  // Initialize the mutex lock
  pthread_mutex_init(&lock, NULL);

  // Main loop: accept new connections and create threads to handle them
  while (1) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    // Create a new client structure
    client_info *client = (client_info *)malloc(sizeof(client_info));
    client->sockfd = newsockfd;
    client->addr = cli_addr;

    // Create a new thread to handle the client
    pthread_t thread;
    pthread_create(&thread, NULL, handle_client, (void *)client);

    // Increment the number of clients
    pthread_mutex_lock(&lock);
    num_clients++;
    pthread_mutex_unlock(&lock);
  }

  // Close the server socket
  close(sockfd);

  // Destroy the mutex lock
  pthread_mutex_destroy(&lock);

  return 0;
}