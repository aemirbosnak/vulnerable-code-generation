//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Function to handle client connections
void *handle_client(void *arg) {
  int sockfd = *(int *)arg;

  // Receive message from client
  char buffer[256];
  int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);

  if (bytes_received < 0) {
    perror("Error receiving message from client");
    close(sockfd);
    return NULL;
  }

  // Process the message
  printf("Received message from client: %s\n", buffer);
  char response[256];
  strcpy(response, "Hello from server!");

  // Send response to client
  int bytes_sent = send(sockfd, response, strlen(response), 0);

  if (bytes_sent < 0) {
    perror("Error sending message to client");
    close(sockfd);
    return NULL;
  }

  // Close client connection
  close(sockfd);
  return NULL;
}

int main() {
  // Create a server socket
  int serverfd = socket(AF_INET, SOCK_STREAM, 0);

  if (serverfd < 0) {
    perror("Error creating server socket");
    return 1;
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the server address
  int bind_status = bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  if (bind_status < 0) {
    perror("Error binding server socket");
    close(serverfd);
    return 1;
  }

  // Listen for incoming connections
  int listen_status = listen(serverfd, 5);

  if (listen_status < 0) {
    perror("Error listening for connections");
    close(serverfd);
    return 1;
  }

  printf("Server listening on port 8080\n");

  // Main loop for accepting and handling client connections
  while (1) {
    // Accept an incoming connection
    int clientfd = accept(serverfd, NULL, NULL);

    if (clientfd < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Create a new thread to handle the client connection
    pthread_t client_thread;
    int *client_fd_ptr = malloc(sizeof(int));
    *client_fd_ptr = clientfd;
    int thread_status = pthread_create(&client_thread, NULL, handle_client, (void *)client_fd_ptr);

    if (thread_status != 0) {
      perror("Error creating client thread");
      close(clientfd);
      free(client_fd_ptr);
      continue;
    }

    // Detach the thread so it can run independently
    pthread_detach(client_thread);
  }

  // Close the server socket when done
  close(serverfd);
  return 0;
}